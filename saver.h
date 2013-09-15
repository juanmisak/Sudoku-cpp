#ifndef SAVER_H
#define SAVER_H

#include <QObject>

#define FILE_NAME "sudoku.save"

class Saver : public QObject
{
    Q_OBJECT
public:
    explicit Saver(QObject *parent = 0);
    bool static save(int cell[]);
    bool static load(int cell[]);
    
signals:
    
public slots:
    
};

#endif // SAVER_H
