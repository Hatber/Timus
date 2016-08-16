#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define TO_STRING(x) STRINGIFY(x)
#define STRINGIFY(x) #x

class SingleFileBuilder {
public:
    void buildFile(string prefix, string taskClassName, vector<string> fileOrder);
private:
    string getSourcePath();
    string fileToBuffer(istream& in);
    string removeUserInclude(string source);
    string makeATask();
};

void SingleFileBuilder::buildFile(string prefix, string taskClassName, vector<string> fileOrder) {
    string sourcePath = getSourcePath();
    string sourceBuffer;

    sourceBuffer += makeATask();

    int fileCount =  (int)fileOrder.size();
    for(int i = 0; i < fileCount; i++) {
        ifstream sourceFile;
        sourceFile.open(sourcePath + "/Task/" + prefix + fileOrder[i] + ".hpp");
        if(!sourceFile) {
            cerr << "Source file don't open!" << endl;
        }

        sourceBuffer += "//File: " +  fileOrder[i] + ".hpp\n";
        sourceBuffer += removeUserInclude(fileToBuffer(sourceFile));
        sourceBuffer += "\n";

        sourceFile.close();
        sourceFile.open(sourcePath + "/Task/" + prefix + fileOrder[i] + ".cpp");
        if(!sourceFile) {
            cerr << "Source file don't open!" << endl;
        }

        sourceBuffer += "//File: " +  fileOrder[i] + ".cpp\n";
        sourceBuffer += removeUserInclude(fileToBuffer(sourceFile));
        sourceBuffer += "\n";
    }

    //Write main section
    sourceBuffer += "//File: main.cpp\n";
    sourceBuffer +=
            "#include <iostream>\n"\
            "\n"\
            "using namespace std;\n"\
            "\n"\
            "int main() {\n"\
            "\ttask" + prefix.substr(1, 4) + "::" + taskClassName + " task(cin, cout);\n"\
            "\ttask.Solve();\n"\
            "\n"\
            "\treturn 0;\n"\
            "}";

    //Write Single Source File
    ofstream singleFile(prefix.substr(0,5));
    if(!singleFile) {
        cerr << "Out file don't open!" << endl;
    }

    singleFile << sourceBuffer;
    singleFile.close();
}

int main() {
    SingleFileBuilder builder;

    vector<string> T1000Files = {"APlusBProblem"};
    builder.buildFile("T1000/", "APlusBProblem", T1000Files);

    vector<string> T1001Files = {"ReverseRoot"};
    builder.buildFile("T1001/", "ReverseRoot", T1001Files);

    vector<string> T1002Files = {"Word", "Number", "Phones"};
    builder.buildFile("T1002/", "Phones", T1002Files);

    vector<string> T1003Files = {"Interval", "Sequence", "Parity"};
    builder.buildFile("T1003/", "Parity", T1003Files);

    return 0;
}

string SingleFileBuilder::getSourcePath() {
    return TO_STRING(_SOURCE_PATH_);
}

string SingleFileBuilder::fileToBuffer(istream& in) {
    in.seekg(0, std::ios_base::end);
    streamsize size = in.tellg();
    in.seekg(0, std::ios_base::beg);

    string buffer;
    buffer.resize(size);
    in.read(&buffer[0], size);

    return buffer;
}

string SingleFileBuilder::removeUserInclude(string source) {
    long pos = 0;
    while(true) {
        size_t startIncludePos = source.find("#include \"", pos);
        if(startIncludePos == string::npos) {break; }

        pos = startIncludePos + 3;
        source.insert(startIncludePos, "//");
    }

    return source;
}

string SingleFileBuilder::makeATask() {
    string bufferFile;

    string sourcePath = getSourcePath();

    ifstream file;
    file.open(sourcePath + "/Task/ATask.hpp");
    if(!file) {
        cerr << "Source file don't open!" << endl;
    }

    bufferFile += "//File: ATask.hpp\n";
    bufferFile += removeUserInclude(fileToBuffer(file));
    bufferFile += "\n";

    file.close();

    file.open(sourcePath + "/Task/ATask.cpp");
    if(!file) {
        cerr << "Source file don't open!" << endl;
    }

    bufferFile += "//File: ATask.cpp\n";
    bufferFile += removeUserInclude(fileToBuffer(file));
    bufferFile += "\n";

    file.close();

    return bufferFile;
}
