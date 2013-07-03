#ifndef ESTADISTIC_H
#define ESTADISTIC_H

#include <QWidget>

namespace Ui {
class Estadistic;
}

class Estadistic : public QWidget
{
    Q_OBJECT
    
public:
    explicit Estadistic(QWidget *parent = 0);
    ~Estadistic();
    
private slots:
    void on_pushButton_7_clicked();

private:
    Ui::Estadistic *ui;

};

#endif // ESTADISTIC_H
