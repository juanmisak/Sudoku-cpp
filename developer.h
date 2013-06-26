#ifndef DEVELOPER_H
#define DEVELOPER_H

#include <QDialog>

namespace Ui {
class Developer;
}

class Developer : public QDialog
{
    Q_OBJECT
    
public:
    explicit Developer(QWidget *parent = 0);
    ~Developer();
    
private slots:
    void on_pushButton_3_clicked();

private:
    Ui::Developer *ui;
};

#endif // DEVELOPER_H

