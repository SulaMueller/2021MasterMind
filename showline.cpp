/*
showline.cpp

@author:    Sula Mueller
@change:    26/06/2021

@summary:   defines the
*/

#include "showline.h"
#include "globals.h"

#include <QMainWindow>

showLine::showLine(){
    globals = globalVars();

    c1 = new QLabel();
    c2 = new QLabel();
    c3 = new QLabel();
    c4 = new QLabel();
    c5 = new QLabel();

    r1 = new QLabel();
    r2 = new QLabel();
    r3 = new QLabel();
    r4 = new QLabel();
    r5 = new QLabel();
    r6 = new QLabel();
}
