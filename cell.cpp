#include "cell.h"
#include "QPushButton"


Cell::Cell(QWidget *parent) :
    QPushButton(parent)
{
    QFont font1;
          font1.setFamily(QStringLiteral("Arial"));
          font1.setPointSize(16);
          font1.setBold(false);
          font1.setWeight(50);
          this->setFont(font1);
    QIcon icon1;
           icon1.addFile(QStringLiteral(":/images/Mysitemyway-Blue-Jeans-Social-Media-Delicious-square.ico"), QSize(), QIcon::Normal, QIcon::Off);
    this->setIcon(icon1);
    this->setIconSize(QSize(30, 30));
    this->backgroundRole();    
    this->setFlat(true);
}


