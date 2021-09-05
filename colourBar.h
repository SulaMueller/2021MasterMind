#ifndef COLOURBAR_H
#define COLOURBAR_H

#include "ui_mainwindow.h"

class colourbar{
public:
    colourbar();
    colourbar(QLabel*, QLabel*, QLabel*, QLabel*, QLabel*);
    ~colourbar(){};
    QLabel q1, q2, q3, q4, q5;
    void updateColourbar(int* c);
    void disableColourbar();
};

#endif // COLOURBAR_H
