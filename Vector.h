//
// Created by Kajetan Dymkiewicz on 11.10.2017.
//

#ifndef UNTITLED_VECTOR_H
#define UNTITLED_VECTOR_H
#include <sstream>
using namespace std;


const string LEN = "len: ";
const string VALUES = "values: ";
const string COMA = ",";

const int PRODUCT_OF_CAPACITY = 2;
const int START_SIZE = 1;

const int SUCCES_CODE = 0;
const int ACTUAL_LENGTH_IS_THE_SAME_VALUE_FROM_USER_CODE = -1;
const int THE_SAME_VALUE_AS_DEFAULT = -2;
const int OFFSET_FROM_USER_DOES_NOT_EXIST = -3;
const int DEFAULT_VALUE_DOES_NOT_EXIST = -4;

void mvec(int *& tabOfValues, int *& tabOfOffset, int lenghtFromUser, int defaultValueFromUser, int &lenghtOfVector, int &defaultValue,int capacityOfTabs );
int def(int *& tabOfValues, int *& tabOfOffset,int &lenghtOfVector, int &indexOfFreePlace, int &capacityOfTabs, int defaultValue,int offsetFromUser, int valueFromUser);
int len(int *& tabOfValues, int *& tabOfOffset,int &lenghtOfVector, int &freePlace, int &capacityOfTabs, int newLenght);
int getDefaultvalue(int defaultValue, int indexOfFreePlace);
int getElementFromVector(int * tabOfValues, int * tabOfOffset, int defaultValue, int indexOfFreePlace, int indexOfElement );
string toString(int * tabOfValues, int * tabOfOffset, int lenghtOfVector, int defaultValue, int indexOfFreePlace );
void del(int *& tabOfValues, int *& tabOfOffset);
bool isCommand(const string command,const char *mnemonic);

#endif //UNTITLED_VECTOR_H
