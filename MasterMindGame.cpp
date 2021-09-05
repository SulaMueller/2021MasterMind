/*
MasterMindGame.cpp

@author:    Sula Mueller
@change:    26/06/2021

@summary:   * the actual game pattern (not the UI)
*/

#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <QDebug>
#include <globals.h>

#include "MasterMindGame.h"

using namespace std;

MasterMindGame::MasterMindGame(int nColors, int nSlots, int mColors){
    globals = globalVars();
    numColors = nColors;
    numSlots = nSlots;
    multipleColors = mColors;  // max number of occurences for each color
    isDone = false;  // check if pattern is correct
    currentMovePtr = 0;  // saves current moveindex

    originalPattern = new int[numSlots];
    originalOccurences = new int[numColors];  // how many times each color occurs
    newMove = new int[numSlots];
    newOccurences = new int[numColors];  // how many times each color occurs
    allMoves = new int[numSlots*globals.maxMoves];
    newResult = new int[numSlots];
    allResults = new int[numSlots*globals.maxMoves];

    initializePattern();
}
MasterMindGame::MasterMindGame(){
    MasterMindGame(8,5,true);  // at startup of mainwindow
}
MasterMindGame::~MasterMindGame(){
    //delete[] originalPattern;
    //delete[] originalSorted;
    //delete[] newMove;
    //delete[] allMoves;
    //delete[] newResult;
    //delete[] allResults;
}
// create random pattern where no color occurs twice
void MasterMindGame::initializeSingleColorPattern(){
    vector<int> allColors;
    for (int i=0; i<numColors; i++)
        allColors.push_back(i);
    random_shuffle( allColors.begin(), allColors.end() );
    for (int i=0; i<numSlots; i++)
        originalPattern[i] = allColors[i];
    getOccurences(originalPattern, originalOccurences);
}
// get a map, how many times each color occurs
void MasterMindGame::getOccurences(int* pattern, int* occurences){
    memset(occurences, 0, numColors*sizeof(int));
    for (int slot=0; slot<numSlots; slot++){
        occurences[pattern[slot]]++;
    }
}
// count how many times the most occuring color occurs (only for testing)
int MasterMindGame::countMaxOccurence(){
    int maxOc = 0;
    for(int color=0; color<numColors; color++){
        int occ = 0;
        for(int i=0; i<numSlots; i++)
            if (originalPattern[i] == color)
                occ++;
        if(occ>maxOc) maxOc = occ;
    }
    return maxOc;
}
// reduce occurence of a color that occurs too often
int MasterMindGame::reduceOccurence(int color){
    // find index of slot to change
    int switchind = rand() % originalOccurences[color];  // choose an index at random
    int count = 0;  // go through all occurences until switchind
    for(int i=0; i<numSlots; i++){
        if (originalPattern[i]==color)
            count++;
        if(count == switchind){
            switchind = i;
            break;
        }
    }
    // get new color
    while(originalOccurences[color] >= multipleColors)
        color = rand() % (numColors);
    originalPattern[switchind] = color;
    originalOccurences[color]++;
    return color;
}
// make sure, no color occurs too often
void MasterMindGame::restrainMultiples(){
    while(*max_element(originalOccurences, originalOccurences+numColors) > multipleColors){
        int color = distance(originalOccurences, max_element(originalOccurences, originalOccurences + numColors));
        reduceOccurence(color);
    }
}
// create random pattern where no color occurs more often than multipleColors
void MasterMindGame::initializeMultiColorPattern(){
    for (int i=0; i<numSlots; i++)
        originalPattern[i] = rand() % numColors;
    getOccurences(originalPattern, originalOccurences);
    restrainMultiples();
}
void MasterMindGame::initializePattern(){
    if (multipleColors>1) initializeMultiColorPattern();
    else initializeSingleColorPattern();
}
// import new move input by user
void MasterMindGame::updateMove( int* nMove ){
    memcpy(newMove, nMove, numSlots*sizeof(int));
    memcpy(allMoves + numSlots*currentMovePtr, nMove, numSlots*sizeof(int));
    getOccurences(newMove, newOccurences);
}
// get white and black sticks
void MasterMindGame::checkMove(){
    int blackSticks = 0, whiteSticks = 0;
    // black sticks
    for (int i=0; i<numSlots; i++){
        blackSticks += (newMove[i] == originalPattern[i] ? 1 : 0);
    }
    // white sticks
    for (int i=0; i<numColors; i++){
        whiteSticks += min(originalOccurences[i], newOccurences[i]);
    }
    whiteSticks -= blackSticks;
    updateResult(blackSticks, whiteSticks);
}
// write white and black sticks into result arrays
void MasterMindGame::updateResult(int blackSticks, int whiteSticks){
    memset(newResult, globals.nostick, numSlots*sizeof(int));
    setInt(newResult, 0, globals.black, blackSticks);
    setInt(newResult, blackSticks, globals.white, whiteSticks);
    memcpy(allResults + numSlots*currentMovePtr, newResult, numSlots*sizeof(int));
}
void MasterMindGame::checkIfDone(){
    isDone = newResult[numSlots-1] == globals.black;
}
void MasterMindGame::processMove(int* move){
    updateMove(move);
    checkMove();
    checkIfDone();
    currentMovePtr++;
}


