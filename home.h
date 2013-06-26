#ifndef HOME_H
#define HOME_H

#include <QDialog>

namespace Ui {
class Home;
}

class Home : public QDialog
{
    Q_OBJECT
    
public:
    /**
       * Un constructor.
       * @param parent un argumento QWidget .
       * Una descripción más elaborada del constructor.
       */
    explicit Home(QWidget *parent = 0);
    /**
      * Un destructor.
      * Una descripción más elaborada del destructor.
      */
    ~Home();
    
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    /**
      * Una variable privada.
      * Detalles.
      */
    Ui::Home *ui;

};

#endif // HOME_H
