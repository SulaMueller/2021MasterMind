#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MasterMindGame.h"
#include "globals.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    globals = globalVars();
    c_main = new int [globals.maxNumSlots];
#ifdef QT_DEBUG
  qDebug() << "Running a debug build";
#else
    cout("NOT IN DEBUG MODE");
    ui->button_test->setVisible(false);
#endif

    newGame();
}
MainWindow::~MainWindow(){
    delete ui;
    delete [] c_main;
}
void MainWindow::on_button_newPattern_clicked(){
    clearTextLabel();
    newGame();
}
void MainWindow::on_button_showPattern_clicked(){
    clearTextLabel();
    showPattern();
}
void MainWindow::on_button_checkMove_clicked(){
    clearTextLabel();
    checkMove();
}
void MainWindow::on_button_test_clicked(){
    cout("TESTING");
    testFunc();
}
void MainWindow::on_horizontalSlider_valueChanged(int position){
    clearTextLabel();
    c_main[0] = position;
    updateMainColorbar();
}
void MainWindow::on_horizontalSlider_2_valueChanged(int position){
    clearTextLabel();
    c_main[1] = position;
    updateMainColorbar();
}
void MainWindow::on_horizontalSlider_3_valueChanged(int position){
    clearTextLabel();
    c_main[2] = position;
    updateMainColorbar();
}
void MainWindow::on_horizontalSlider_4_valueChanged(int position){
    clearTextLabel();
    c_main[3] = position;
    updateMainColorbar();
}
void MainWindow::on_horizontalSlider_5_valueChanged(int position){
    clearTextLabel();
    c_main[4] = position;
    updateMainColorbar();
}

void MainWindow::on_in_numPins_valueChanged(){
    clearTextLabel();
    numPinsChanged();
}
void MainWindow::on_in_numColors_valueChanged(){
    clearTextLabel();
    numColorsChanged();
}

void MainWindow::on_in_numMultiples_valueChanged(){
    numMultiplesChanged();
}
