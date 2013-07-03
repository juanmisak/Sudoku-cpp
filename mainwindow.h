#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cell.h"
#include "sudoku.h"

namespace Ui {
class MainWindow;
}
class Keyboard;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionSalir_triggered();
    void celda_clicked();
    void number_clicked();
    void validate();

    void on_lcdNumber_overflow();

private:
    Ui::MainWindow *ui;
    Cell *cell[BOARD_SIZE * BOARD_SIZE];
    Keyboard *keyboard;
    QIcon icon1;
    char selectedNumber;
    void initBoard();
};

#endif // MAINWINDOW_H

