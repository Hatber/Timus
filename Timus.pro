TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Task/ATask.cpp \
    Task/T1000/APlusBProblem.cpp \
    Task/T1001/ReverseRoot.cpp \
    Task/T1002/Phones.cpp \
    Task/T1002/Word.cpp \
    Task/T1002/Number.cpp

HEADERS += \
    Task/ATask.hpp \
    Task/T1000/APlusBProblem.hpp \
    Task/T1001/ReverseRoot.hpp \
    Task/T1002/Word.hpp \
    Task/T1002/Number.hpp \
    Task/T1002/Phones.hpp

