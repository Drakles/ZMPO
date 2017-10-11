#include <iostream>
#include <sstream>
#include "Interface.h"
#include "Vector.h"
using namespace std;

bool isCommand(const string command,const char *mnemonic) {
    return command==mnemonic;
}

int main() {

    int * tabOfValues;
    int * tabOfOffset;
    int capacityOfTabs = START_SIZE;
    int defaultValue;
    int indexOfFreePlace = 0;
    int lenghtOfVector;

    while(true)
    {
        string line;
        string command;
        int firstArgument;
        int secondArgument;

        getline(cin,line);
        std::stringstream stream(line);
        stream >> command;
        if(line=="" || command[0]=='#'){
            // ignore empty line and comment
            continue;
        }

        // copy line on output with exclamation mark
        //cout << "!" << line << endl;;

        if(isCommand(command,"exit")) {
            break;
        }

        // zero-argument command

        if(isCommand(command,"print")){
            cout << toString(tabOfValues,tabOfOffset,lenghtOfVector,defaultValue,indexOfFreePlace);
            continue;
        }

        if(isCommand(command,"del")){
            del(tabOfValues,tabOfOffset);
            continue;
        }

        // read next argument, one int firstArgument
        stream >> firstArgument;

        if(isCommand(command,"len")){
            len(tabOfValues,tabOfOffset,lenghtOfVector,indexOfFreePlace,capacityOfTabs,firstArgument);
            continue;
        }

        // read second argument

        stream >> secondArgument;

        if(isCommand(command,"mvec")){
            mvec(tabOfValues,tabOfOffset,firstArgument,secondArgument,lenghtOfVector,defaultValue);
            continue;
        }

        if(isCommand(command,"def")){
            def(tabOfValues,tabOfOffset,lenghtOfVector,indexOfFreePlace,capacityOfTabs,defaultValue,firstArgument,secondArgument);
            continue;
        }

        cout << "błędne polecenie: " << command << endl;
    }

}


