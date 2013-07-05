#ifndef DEVELOPER_H
#define DEVELOPER_H

#include <QDialog>

namespace Ui {
class Developer;
}
/**
 * La clase Developer representa un Widget para los desarrolladores.
 * @author Juan Mite
 */
class Developer : public QDialog
{
    Q_OBJECT
    
public:
/**
 * Un constructor.
 * @param parent un argumento QWidget .
 * Una descripción más elaborada del constructor.
*/
    explicit Developer(QWidget *parent = 0);
    ~Developer();
    
private slots:
    void on_pushButton_3_clicked();

private:
    Ui::Developer *ui;
};

#endif // DEVELOPER_H

