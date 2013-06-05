#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cell.h"

#define BOARD_SIZE 9

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_actionSalir_triggered();

private:
    Ui::MainWindow *ui;
    Cell *cell[BOARD_SIZE * BOARD_SIZE];
};

#endif // MAINWINDOW_H
