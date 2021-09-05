/*
mainwindow.h

@author:    Sula Mueller
@change:    26/06/2021

@summary:   * Qt automatic created file
            * defines mainwindow elements
            * also header for all functionality
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "MasterMindGame.h"
#include "globals.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_newPattern_clicked();
    void on_button_showPattern_clicked();
    void on_button_checkMove_clicked();
    void on_button_test_clicked();

    void sliderValueChanged(int slider, int value);
    void on_horizontalSlider_valueChanged(int value);
    void on_horizontalSlider_2_valueChanged(int value);
    void on_horizontalSlider_3_valueChanged(int value);
    void on_horizontalSlider_4_valueChanged(int value);
    void on_horizontalSlider_5_valueChanged(int value);

    void on_in_numPins_valueChanged();
    void on_in_numColors_valueChanged();
    void on_in_numMultiples_valueChanged();

private:
    globalVars globals;
    Ui::MainWindow *ui;
    int* c_main;
    int numColors, numSlots, numMultiples;
    MasterMindGame Game;

    QColor getColor(int color);
    QColor getResult(int result);
    QLabel* getLabel(int row, int el, string type);
    QSlider* getSlider(int el);
    void fetchInput();
    void updateSingleColor(QLabel *ql, string type, int c);
    void updateAnyColorbar(string type, int row, int* c);
    void updateAllColorbars();
    void updateMainColorbar();
    void disableSingleColor(QLabel*);
    void disableAnyColorbar(string type, int row);
    void disableAllColorbars();
    void resetAllColorbars();
    void enableSingleSlider(int el, bool enable);
    void enableSliders();
    void disableAllSliders();
    void enableButtons();
    void disableButtons();
    void enableInput();
    void disableInput();
    void clearTextLabel();
    void newGame();
    void showPattern();
    void checkMove();
    void setCounter();
    void setAnyText(QString text, QColor background, QColor textcol, int fontsize);
    void setWinText();
    void setLoseText();
    void setWarnText(QString text);
    bool wonGame();
    void lostGame();
    bool checkNumberSanity();
    void numPinsChanged();
    void numColorsChanged();
    void numMultiplesChanged();
    void testFunc();
    void testInitPatternsMultiples();
};
#endif // MAINWINDOW_H
