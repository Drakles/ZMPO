//
// Created by Kajetan Dymkiewicz on 11.10.2017.
//

#ifndef UNTITLED_LIST1_H
#define UNTITLED_LIST1_H
#include <sstream>
using namespace std;


const int START_SIZE = 1;
const string LEN = "len: ";
const string VALUES = "values: ";
const string COMA = ",";
const int PRODUCT_OF_CAPACITY = 2;

void mvec(int *& tabOfValues, int *& tabOfOffset, int lenghtFromUser, int defaultValueFromUser, int &lenghtOfVector, int &defaultValue );
void def(int *& tabOfValues, int *& tabOfOffset,int &lenghtOfVector, int &indexOfFreePlace, int &capacityOfTabs, int defaultValue,int offsetFromUser, int valueFromUser);
void len(int *& tabOfValues, int *& tabOfOffset,int &lenghtOfVector, int &freePlace, int &capacityOfTabs, int newLenght);
void getDefaultvalue(int defaultValue, int indexOfFreePlace);
int getElementFromVector(int * tabOfValues, int * tabOfOffset, int defaultValue, int indexOfFreePlace, int indexOfElement );
string toString(int * tabOfValues, int * tabOfOffset, int lenghtOfVector, int defaultValue, int indexOfFreePlace );
void del(int *& tabOfValues, int *& tabOfOffset);
bool isCommand(const string command,const char *mnemonic);




#endif //UNTITLED_LIST1_H
