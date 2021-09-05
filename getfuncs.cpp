#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MasterMindGame.h"
#include "globals.h"

QColor grey = QColor(170, 170, 127);
QColor black = Qt::black;
QColor white = Qt::white;
QColor red = Qt::red;
QColor blue = QColor(0,85,255);
QColor green = QColor(85, 170, 0);
QColor yellow = Qt::yellow;
QColor brown = QColor(170, 85, 0);
QColor violet = QColor(170, 0, 127);
QColor orange = QColor(255, 85, 0);


QColor MainWindow::getColor(int c){
    switch (c) {
    case 0: return black;
    case 1: return red;
    case 2: return white;
    case 3: return blue;
    case 4: return yellow;
    case 5: return green;
    case 6: return brown;
    case 7: return violet;
    case 8: return grey;
    case 9: return orange;
    default: return grey;
    }
}
QColor MainWindow::getResult(int result){
    if (result == globals.white) return white;
    if (result == globals.black) return black;
    if (result == globals.nostick) return grey;
    return grey;
}
QLabel* MainWindow::getLabel(int row, int el, string type){
    if(type.compare("main")==0){
        switch(el){
        case 1: return ui->plate1;
        case 2: return ui->plate2;
        case 3: return ui->plate3;
        case 4: return ui->plate4;
        case 5: return ui->plate5;
        }
    }
    if(type.compare("plate")==0){
        if(row==0 && el==1) return ui->plate1_2;
        if(row==0 && el==2) return ui->plate2_2;
        if(row==0 && el==3) return ui->plate3_2;
        if(row==0 && el==4) return ui->plate4_2;
        if(row==0 && el==5) return ui->plate5_2;
        if(row==1 && el==1) return ui->plate1_3;
        if(row==1 && el==2) return ui->plate2_3;
        if(row==1 && el==3) return ui->plate3_3;
        if(row==1 && el==4) return ui->plate4_3;
        if(row==1 && el==5) return ui->plate5_3;
        if(row==2 && el==1) return ui->plate1_4;
        if(row==2 && el==2) return ui->plate2_4;
        if(row==2 && el==3) return ui->plate3_4;
        if(row==2 && el==4) return ui->plate4_4;
        if(row==2 && el==5) return ui->plate5_4;
        if(row==3 && el==1) return ui->plate1_5;
        if(row==3 && el==2) return ui->plate2_5;
        if(row==3 && el==3) return ui->plate3_5;
        if(row==3 && el==4) return ui->plate4_5;
        if(row==3 && el==5) return ui->plate5_5;
        if(row==4 && el==1) return ui->plate1_6;
        if(row==4 && el==2) return ui->plate2_6;
        if(row==4 && el==3) return ui->plate3_6;
        if(row==4 && el==4) return ui->plate4_6;
        if(row==4 && el==5) return ui->plate5_6;
        if(row==5 && el==1) return ui->plate1_7;
        if(row==5 && el==2) return ui->plate2_7;
        if(row==5 && el==3) return ui->plate3_7;
        if(row==5 && el==4) return ui->plate4_7;
        if(row==5 && el==5) return ui->plate5_7;
        if(row==6 && el==1) return ui->plate1_8;
        if(row==6 && el==2) return ui->plate2_8;
        if(row==6 && el==3) return ui->plate3_8;
        if(row==6 && el==4) return ui->plate4_8;
        if(row==6 && el==5) return ui->plate5_8;
        if(row==7 && el==1) return ui->plate1_9;
        if(row==7 && el==2) return ui->plate2_9;
        if(row==7 && el==3) return ui->plate3_9;
        if(row==7 && el==4) return ui->plate4_9;
        if(row==7 && el==5) return ui->plate5_9;
        if(row==8 && el==1) return ui->plate1_11;
        if(row==8 && el==2) return ui->plate2_11;
        if(row==8 && el==3) return ui->plate3_11;
        if(row==8 && el==4) return ui->plate4_11;
        if(row==8 && el==5) return ui->plate5_11;
        if(row==9 && el==1) return ui->plate1_12;
        if(row==9 && el==2) return ui->plate2_12;
        if(row==9 && el==3) return ui->plate3_12;
        if(row==9 && el==4) return ui->plate4_12;
        if(row==9 && el==5) return ui->plate5_12;
    }
    if(type.compare("result")==0){
        if(row==0 && el==1) return ui->result1_2;
        if(row==0 && el==2) return ui->result2_2;
        if(row==0 && el==3) return ui->result3_2;
        if(row==0 && el==4) return ui->result4_2;
        if(row==0 && el==5) return ui->result5_2;
        if(row==1 && el==1) return ui->result1_3;
        if(row==1 && el==2) return ui->result2_3;
        if(row==1 && el==3) return ui->result3_3;
        if(row==1 && el==4) return ui->result4_3;
        if(row==1 && el==5) return ui->result5_3;
        if(row==2 && el==1) return ui->result1_5;
        if(row==2 && el==2) return ui->result2_5;
        if(row==2 && el==3) return ui->result3_5;
        if(row==2 && el==4) return ui->result4_5;
        if(row==2 && el==5) return ui->result5_5;
        if(row==3 && el==1) return ui->result1_6;
        if(row==3 && el==2) return ui->result2_6;
        if(row==3 && el==3) return ui->result3_6;
        if(row==3 && el==4) return ui->result4_6;
        if(row==3 && el==5) return ui->result5_6;
        if(row==4 && el==1) return ui->result1_4;
        if(row==4 && el==2) return ui->result2_4;
        if(row==4 && el==3) return ui->result3_4;
        if(row==4 && el==4) return ui->result4_4;
        if(row==4 && el==5) return ui->result5_4;
        if(row==5 && el==1) return ui->result1_7;
        if(row==5 && el==2) return ui->result2_7;
        if(row==5 && el==3) return ui->result3_7;
        if(row==5 && el==4) return ui->result4_7;
        if(row==5 && el==5) return ui->result5_7;
        if(row==6 && el==1) return ui->result1_8;
        if(row==6 && el==2) return ui->result2_8;
        if(row==6 && el==3) return ui->result3_8;
        if(row==6 && el==4) return ui->result4_8;
        if(row==6 && el==5) return ui->result5_8;
        if(row==7 && el==1) return ui->result1_9;
        if(row==7 && el==2) return ui->result2_9;
        if(row==7 && el==3) return ui->result3_9;
        if(row==7 && el==4) return ui->result4_9;
        if(row==7 && el==5) return ui->result5_9;
        if(row==8 && el==1) return ui->result1_10;
        if(row==8 && el==2) return ui->result2_10;
        if(row==8 && el==3) return ui->result3_10;
        if(row==8 && el==4) return ui->result4_10;
        if(row==8 && el==5) return ui->result5_10;
        if(row==9 && el==1) return ui->result1_11;
        if(row==9 && el==2) return ui->result2_11;
        if(row==9 && el==3) return ui->result3_11;
        if(row==9 && el==4) return ui->result4_11;
        if(row==9 && el==5) return ui->result5_11;
    }
    return ui->spacer1;
}
QSlider* MainWindow::getSlider(int el){
    switch (el) {
    case 1: return ui->horizontalSlider;
    case 2: return ui->horizontalSlider_2;
    case 3: return ui->horizontalSlider_3;
    case 4: return ui->horizontalSlider_4;
    case 5: return ui->horizontalSlider_5;
    default: return ui->horizontalSlider;
    }
}
