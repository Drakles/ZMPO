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

    bool endOfProgram = false;

    while(!endOfProgram)
    {
        string line;
        string command;
        int firstArgument;
        int secondArgument;
        bool wrongArgument = true;



        cout << "podaj polecenie ";

        getline(cin,line);
        std::stringstream stream(line);
        stream >> command;

        // copy line on output with exclamation mark
        //cout << "!" << line << endl;;
        //cout << "command " << command << endl;

        if(isCommand(command,"exit")) {
            endOfProgram = true;
            wrongArgument = false;
        }

        // zero-argument command

        if(isCommand(command,"print")){
            cout << toString(tabOfValues,tabOfOffset,lenghtOfVector,defaultValue,indexOfFreePlace) << endl;
            wrongArgument = false;
        }

        if(isCommand(command,"del")){
            del(tabOfValues,tabOfOffset);
            wrongArgument = false;
        }

        // read next argument, one int firstArgument
        stream >> firstArgument;

        if(isCommand(command,"len")){

            int codeOfResult = len(tabOfValues,tabOfOffset,lenghtOfVector,indexOfFreePlace,capacityOfTabs,firstArgument);

           if( codeOfResult == SUCCES_CODE ){
               cout << "Udało zmienić się długość wektora" << endl;
           } else if (codeOfResult == ACTUAL_LENGTH_IS_THE_SAME_VALUE_FROM_USER_CODE){
               cout << "Długość wektora nie została zmieniona - aktualna długość jest taka sama jak podana" << endl;
           }else{
               cout << "Wystąpił błąd" << endl;
           }
            wrongArgument = false;
        }

        // read second argument

        stream >> secondArgument;

        if(isCommand(command,"mvec")){
            mvec(tabOfValues,tabOfOffset,firstArgument,secondArgument,lenghtOfVector,defaultValue,capacityOfTabs);
            wrongArgument = false;
        }

        if(isCommand(command,"def")){
            int result = def(tabOfValues,tabOfOffset,lenghtOfVector,indexOfFreePlace,capacityOfTabs,defaultValue,firstArgument,secondArgument);
            if(result == SUCCES_CODE){
                cout << "Udało się zmienić wartość elementu w wektorze " << endl;
            }else if(result == THE_SAME_VALUE_AS_DEFAULT){
                cout << "Błąd - podana wartość to wartość domyślna w wektorze" << endl;

            }else if(result == OFFSET_FROM_USER_DOES_NOT_EXIST){
                cout << "offset o podanej wartości nie istnieje" << endl;

            }else{
                cout <<"Wystąpił błąd" << endl;
            }
            wrongArgument = false;
        }

        if(wrongArgument){
        cout << "nie rozpoznano polecenia: " << line << endl;
        }
    }

}


