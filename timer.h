#ifndef TIMER_H
#define TIMER_H
#include <QPushButton>
#include <QSettings>

const int borda = 10;

class Timer
{
public:
    Timer();
    void get_Timer();
private:
    QPushButton *btnTime;
    QSettings *conf;
    QTimer *timTimer;
    QTimer *timTimerConf;
    int h, m, s;
    void resizeEvent (QResizeEvent *);
    void moveEvent (QMoveEvent *);
    void escreveTXT ();

private slots:
    void btnReset_clicked (bool);
    void btnTime_clicked (bool);
    void timTimer_timeout ();
    void timTimerConf_timeout ();
};




#endif // TIMER_H
