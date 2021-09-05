/*
globals.h

@author:    Sula Mueller
@change:    26/06/2021

@summary:   * define simple functions
            * set global variables
*/

#ifndef GLOBALS_H
#define GLOBALS_H

#include<QDebug>

void printArr(int* arr, int N);
void sort(int* arr, int numels);
void cout(QString);
void setInt(int* arr, int begin, int val, int N);

class globalVars{
public:
    int maxMoves = 10;  // max number of moves after which game is lost
    int numTestInits = 100;  // test this number of games in test-mode
    int* c_example;  // load this color pattern at init

    int maxNumRows = 10;  // max number of moves that can be displayed
    int maxNumSlots = 5;  // max number of color slots
    int maxNumColors = 10;  // max number of different colors
    int minNumColors = 3;
    int minNumSlots = 2;

    enum results{
            black = 2,
            white = 1,
            nostick = 0
    };

    globalVars(){  // init
        c_example = new int[maxNumSlots];
        for(int i=0; i<maxNumSlots; i++){
            c_example[i] = i % maxNumColors;  // initialize with a few different colors
        }
    };
    ~globalVars(){
        //delete [] c_example;
    };
};

enum testmodes{
    initPatternMultiples,
    other
};

#endif // GLOBALS_H
