#ifndef SHOWLINE_H
#define SHOWLINE_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "globals.h"

class showLine{
public:
    showLine();
    void setLine(int* colors, int* results);
private:
    globalVars globals;

    QLabel* c1;
    QLabel* c2;
    QLabel* c3;
    QLabel* c4;
    QLabel* c5;

    QLabel* r1;
    QLabel* r2;
    QLabel* r3;
    QLabel* r4;
    QLabel* r5;
    QLabel* r6;

    QWidget central{};
    QGridLayout centralLayout{&central};
};

#endif // SHOWLINE_H
