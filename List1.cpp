#include <iostream>
#include <sstream>
#include "List1.h"
using namespace std;

void mvec(int *& tabOfValues, int *& tabOfOffset, int lenghtFromUser, int defaultValueFromUser, int &lenghtOfVector, int &defaultValue ){

    lenghtOfVector = lenghtFromUser;
    defaultValue = defaultValueFromUser;

    tabOfValues = new int[START_SIZE];
    tabOfOffset = new int [START_SIZE];
}

void def(int *& tabOfValues, int *& tabOfOffset,int &lenghtOfVector, int &indexOfFreePlace, int &capacityOfTabs, int defaultValue,int offsetFromUser, int valueFromUser){

    if(offsetFromUser < lenghtOfVector && offsetFromUser >= 0){

        if(valueFromUser != defaultValue) {

            if (indexOfFreePlace < capacityOfTabs) {

                tabOfValues[indexOfFreePlace] = valueFromUser;
                tabOfOffset[indexOfFreePlace] = offsetFromUser;
                indexOfFreePlace++;

            } else {

                int *resizedOffsests = new int[capacityOfTabs * 2];
                int *resizedValues = new int[capacityOfTabs * 2];

                for (int i = 0; i < (int) capacityOfTabs; ++i) {
                    resizedValues[i] = tabOfValues[i];
                    resizedOffsests[i] = tabOfOffset[i];
                }

                capacityOfTabs *= PRODUCT_OF_CAPACITY;

                delete[]tabOfOffset;
                delete[]tabOfValues;

                tabOfOffset = resizedOffsests;
                tabOfValues = resizedValues;

                tabOfValues[indexOfFreePlace] = valueFromUser;
                tabOfOffset[indexOfFreePlace] = offsetFromUser;
                indexOfFreePlace++;

            }
        } else{

            bool isOffsetFromUserInTabOfOffset = false;

            for (int i = 0; i < indexOfFreePlace && !isOffsetFromUserInTabOfOffset ; ++i) {
                if(tabOfOffset[i] == offsetFromUser){
                    isOffsetFromUserInTabOfOffset = true;
                }
            }

            if(isOffsetFromUserInTabOfOffset){

                int* resizedOffsests = new int[START_SIZE];
                int* resizedValues = new int[START_SIZE];

                int indexOfNewTables = 0;

                for (int i = 0; i < indexOfFreePlace ; ++i) {
                    if(tabOfOffset[i] != offsetFromUser){
                        resizedOffsests[indexOfNewTables] = tabOfOffset[i];
                        resizedValues[indexOfNewTables] = tabOfValues[i];
                        indexOfNewTables++;
                    }
                }

                delete []tabOfOffset;
                delete []tabOfValues;

                tabOfOffset = resizedOffsests;
                tabOfValues = resizedValues;

                capacityOfTabs = indexOfNewTables;


            } else{

            std::cout << "podana wartość to wartość domyślna w wektorze" << endl;

            }
        }

    } else{

        std::cout << "offset o podanej wartości nie istnieje" << endl;
    }
}

void len(int *& tabOfValues, int *& tabOfOffset,int &lenghtOfVector, int &freePlace, int &capacityOfTabs, int newLenght){

    if(newLenght < lenghtOfVector) {

        int* resizedOffsests = new int[START_SIZE];
        int* resizedValues = new int[START_SIZE];

        int indexOfNewTables = 0;

        for (int i = 0; i < capacityOfTabs; ++i) {

            if (tabOfOffset[i] < newLenght) {
                resizedOffsests[indexOfNewTables] = tabOfOffset[i];
                resizedValues[indexOfNewTables] = tabOfValues[i];
                indexOfNewTables++;
            }
        }

        delete []tabOfOffset;
        delete []tabOfValues;

        tabOfOffset = resizedOffsests;
        tabOfValues = resizedValues;

        lenghtOfVector = newLenght;
        capacityOfTabs = indexOfNewTables;

    } else if ( newLenght > lenghtOfVector){

        lenghtOfVector = newLenght;

    } else std::cout << "Aktualna długość wektora jest taka sama jak podana" << std::endl;

}

void getDefaultvalue(int defaultValue, int indexOfFreePlace){
    if (indexOfFreePlace == 0 ){
        cout << "domyślna wartość to: " << defaultValue << endl;
    } else{
        cout << "ERROR - nie ma domyślnej wartości" << endl;
    }
}

int getElementFromVector(int * tabOfValues, int * tabOfOffset, int defaultValue, int indexOfFreePlace, int indexOfElement ){

    for (int i = 0; i < indexOfFreePlace ; ++i) {
        if(tabOfOffset[i] == indexOfElement){
            return tabOfValues[i];
        }
    }
    return defaultValue;
}

string toString(int * tabOfValues, int * tabOfOffset, int lenghtOfVector, int defaultValue, int indexOfFreePlace ){

    string vector;
    vector.append(LEN);
    vector.append(std::to_string(lenghtOfVector));
    vector.append(" ");
    vector.append(VALUES);

    for (int i = 0; i < lenghtOfVector ; ++i) {
        for (int j = 0; j < indexOfFreePlace ; ++j) {
            if(i == tabOfOffset[j]){
                vector.append(std::to_string(tabOfValues[j]));
                vector.append(COMA);
                i++;

            }

        }
        vector.append(std::to_string(defaultValue));
        vector.append(COMA);
    }

    return vector;
}

void del(int *& tabOfValues, int *& tabOfOffset){
    delete []tabOfValues;
    delete []tabOfOffset;
}

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


