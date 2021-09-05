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
