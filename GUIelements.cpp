#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MasterMindGame.h"
#include "globals.h"

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
void MainWindow::sliderValueChanged(int slider, int position){
    clearTextLabel();
    c_main[slider-1] = position;
    updateMainColorbar();
}
void MainWindow::on_horizontalSlider_valueChanged(int position){
    sliderValueChanged(1, position);
}
void MainWindow::on_horizontalSlider_2_valueChanged(int position){
    sliderValueChanged(2, position);
}
void MainWindow::on_horizontalSlider_3_valueChanged(int position){
    sliderValueChanged(3, position);
}
void MainWindow::on_horizontalSlider_4_valueChanged(int position){
    sliderValueChanged(4, position);
}
void MainWindow::on_horizontalSlider_5_valueChanged(int position){
    sliderValueChanged(5, position);
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
    clearTextLabel();
    numMultiplesChanged();
}
