/*
MasterMindGame.h

@author:    Sula Mueller
@change:    26/06/2021

@summary:   * header for the actual game pattern (not the UI)
*/

#ifndef MASTERMINDGAME_H
#define MASTERMINDGAME_H

#include <cmath>
#include <vector>
#include "globals.h"

class MasterMindGame{
public:
    int numColors;
    int numSlots;
    int currentMovePtr;  // saves current moveindex
    int multipleColors;  // max number of occurences for each color
    bool isDone;  // check if pattern is correct

    int* originalPattern;  // (unknown) color pattern
    int* originalOccurences;  // how many times each color occurs
    int* newMove;  // color pattern input by user
    int* newOccurences;  // how many times each color occurs
    int* allMoves;  // save move history
    int* newResult;  // black and white pins
    int* allResults;  // result history

    MasterMindGame(int, int, int);
    MasterMindGame();
    ~MasterMindGame();
    void processMove(int*);

    int countMaxOccurence();  // for testing purposes

private:
    globalVars globals;
    void initializeSingleColorPattern();
    void getOccurences(int*, int*);
    int reduceOccurence(int color);
    void restrainMultiples();
    void initializeMultiColorPattern();
    void initializePattern();
    void updateMove( int* );
    void updateResult(int, int);
    void checkMove();
    void checkIfDone();
};

#endif // MASTERMINDGAME_H
