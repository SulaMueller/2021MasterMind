#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MasterMindGame.h"
#include "globals.h"

using namespace std;

void MainWindow::fetchInput(){
    numColors = ui->in_numColors->value();
    numSlots = ui->in_numPins->value();
    numMultiples = ui->in_numMultiples->value();
}
void MainWindow::updateSingleColor(QLabel *ql, string type, int c){
    QPalette pal = palette();
    if(type.compare("result")==0)
        pal.setColor(QPalette::Background, getResult(c));
    else
        pal.setColor(QPalette::Background, getColor(c));
    ql->setAutoFillBackground(true);
    ql->setPalette(pal);
}
void MainWindow::updateAnyColorbar(string type, int row, int* c){
    for(int el=0; el<numSlots; el++)
        updateSingleColor(getLabel(row, el+1, type), type, c[el]);
}
void MainWindow::updateAllColorbars(){
    for(int row=0; row<Game.currentMovePtr; row++){
        updateAnyColorbar("plate", row, Game.allMoves+row*numSlots);
        updateAnyColorbar("result", row, Game.allResults+row*numSlots);
    }
}
void MainWindow::updateMainColorbar(){
    updateAnyColorbar("main", 0, c_main);
}
void MainWindow::disableSingleColor(QLabel* ql){
    ql->setAutoFillBackground(false);
}
void MainWindow::disableAnyColorbar(string type, int row){
    for(int el=0; el<globals.maxNumSlots; el++)
        disableSingleColor(getLabel(row, el+1, type));
}
void MainWindow::disableAllColorbars(){
    for(int row=0; row<globals.maxNumRows; row++){
        disableAnyColorbar("main", row);
        disableAnyColorbar("plate", row);
        disableAnyColorbar("result", row);
    }
}
void MainWindow::resetAllColorbars(){
    disableAllColorbars();
    updateMainColorbar();
}
void MainWindow::enableSingleSlider(int el, bool enable){
    getSlider(el)->setEnabled(enable);
    getSlider(el)->setMaximum(numColors-1);
    getSlider(el)->setValue(c_main[el]);
}
void MainWindow::enableSliders(){
    for(int s=0; s<globals.maxNumSlots; s++)
        enableSingleSlider(s+1, s<numSlots);
}
void MainWindow::disableAllSliders(){
    for(int s=0; s<globals.maxNumSlots; s++)
        enableSingleSlider(s+1, false);
}
void MainWindow::enableButtons(){
    ui->button_checkMove->setEnabled(true);
    ui->button_showPattern->setEnabled(true);
}
void MainWindow::disableButtons(){
    ui->button_checkMove->setEnabled(false);
    ui->button_showPattern->setEnabled(false);
}
void MainWindow::enableInput(){
    ui->in_numColors->setEnabled(true);
    ui->in_numPins->setEnabled(true);
    ui->in_numMultiples->setEnabled(true);
}
void MainWindow::disableInput(){
    ui->in_numColors->setDisabled(true);
    ui->in_numPins->setDisabled(true);
    ui->in_numMultiples->setDisabled(true);
}
void MainWindow::clearTextLabel(){
    ui->out_label_result->setVisible(false);
}
void MainWindow::newGame(){
    fetchInput();
    Game = MasterMindGame(numColors, numSlots, numMultiples);
    memcpy(c_main, globals.c_example, globals.maxNumSlots*sizeof(int));
    enableSliders();
    enableButtons();
    enableInput();
    setCounter();
    resetAllColorbars();
}
void MainWindow::showPattern(){
    disableAllSliders();
    disableButtons();
    memcpy(c_main, Game.originalPattern, numSlots*sizeof(int));
    updateMainColorbar();
    enableInput();
}
void MainWindow::checkMove(){
    Game.processMove(c_main);
    updateAllColorbars();
    setCounter();
    if(!wonGame()) lostGame();
}
void MainWindow::setCounter(){
    ui->out_usedMoves->display(Game.currentMovePtr);
}
void MainWindow::setAnyText(QString text, QColor background, QColor textcol, int fontsize){
    QLabel* ql = ui->out_label_result;
    QPalette pal = palette();
    pal.setColor(QPalette::Background, background);
    pal.setColor(QPalette::Foreground, textcol);
    ql->setPalette(pal);
    QFont font = ql->font();
    font.setPointSize(fontsize);
    ql->setFont(font);
    ql->setAlignment(Qt::AlignCenter);
    ql->setAutoFillBackground(true);
    ql->setText(text);
    ql->setEnabled(true);
    ql->setVisible(true);
}
void MainWindow::setWinText(){
    setAnyText("YOU WIN!", Qt::green, Qt::white, 26);
}
void MainWindow::setLoseText(){
    setAnyText("Out of moves.\n You loose :(", Qt::red, Qt::white, 14);
}
void MainWindow::setWarnText(QString text){
    setAnyText(text, Qt::white, Qt::red, 12);
}
bool MainWindow::wonGame(){
    if(Game.isDone){
        showPattern();
        setWinText();
    }
    return Game.isDone;
}
void MainWindow::lostGame(){
    if(Game.currentMovePtr == globals.maxNumRows){
        showPattern();
        setLoseText();
    }
}
bool MainWindow::checkNumberSanity(){
    fetchInput();
    return numColors*numMultiples >= numSlots;
}
void MainWindow::numPinsChanged(){
    if(!checkNumberSanity()){
        setWarnText("Need as least as many colors as slots.\nIncreased number of colors.");
        ui->in_numColors->setValue((numSlots-1)/numMultiples+1);
    }
}
void MainWindow::numColorsChanged(){
    if(!checkNumberSanity()){
        setWarnText("Need as least as many colors as slots.\nIncreased number of multiples.");
        ui->in_numMultiples->setValue((numSlots-1)/numColors+1);
    }
}
void MainWindow::numMultiplesChanged(){
    if(!checkNumberSanity()){
        ui->in_numColors->setValue((numSlots-1)/numMultiples+1);
        setWarnText("Need as least as many colors as slots.\nIncreased number of colors.");
    }
}
