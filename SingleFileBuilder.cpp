#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define TO_STRING(x) STRINGIFY(x)
#define STRINGIFY(x) #x

string getSourcePath() {
    return TO_STRING(_SOURCE_PATH_);
}

string fileToBuffer(istream& in) {
    in.seekg(0, std::ios_base::end);
    streamsize size = in.tellg();
    in.seekg(0, std::ios_base::beg);

    string buffer;
    buffer.resize(size);
    in.read(&buffer[0], size);

    return buffer;
}

string removeUserInclude(string source) {
    long pos = 0;
    while(true) {
        size_t startIncludePos = source.find("#include \"", pos);
        if(startIncludePos == string::npos) {break; }

        pos = startIncludePos + 3;
        source.insert(startIncludePos, "//");
    }

    return source;
}

string makeATask() {
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

void makeT1000() {
    string prefix = "T1000/";
    string taskClassName = "APlusBProblem";
    string fileOrder[] = {"APlusBProblem"};
    string sourcePath = getSourcePath();
    string sourceBuffer;


    sourceBuffer += makeATask();

    int fileCount =  sizeof(fileOrder) / sizeof(string);
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
    cout << "Make Files : " << endl;

    makeT1000();

    return 0;
}
