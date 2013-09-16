#include "timer.h"

Timer::Timer()
{
    this->conf = new QSettings ("cronometro", QString (), this);
    this->conf->sync ();
    this->h = this->conf->value ("tiempo/hora", 0).toInt ();
    this->m = this->conf->value ("tiempo/minuto", 0).toInt ();
    this->s = this->conf->value ("tiempo/segundo", 0).toInt ();
    this->timTimer = new QTimer (this);
    this->timTimer->setInterval (1000);
    this->timTimer->setSingleShot (false);
    QObject::connect (this->timTimer, SIGNAL (timeout ()), this, SLOT (timTimer_timeout ()));
    this->timTimer->start();//Inicia el conteo
    this->btnTime = new QPushButton (this);
    this->btnTime->move (10, 10);
    this->btnTime->setToolTip ("Clique para iniciar/parar o cronometro.");
    this->btnTime->setFlat (true);
    this->btnTime->setFocusPolicy (Qt::NoFocus);
    this->btnTime->setCursor (Qt::PointingHandCursor);
    this->btnTime->show ();
    /*QObject::connect (this->btnTime, SIGNAL (clicked (bool)), this, SLOT (btnTime_clicked (bool)));
    */
    this->btnReset = new QPushButton (this);
    this->btnReset->setText ("Reiniciar");
    this->btnReset->adjustSize ();
    this->btnReset->show ();
    QObject::connect (this->btnReset, SIGNAL (clicked (bool)), this, SLOT (btnReset_clicked (bool)));

    this->resize (this->conf->value ("janela/largura", 470).toInt(),
                  this->conf->value ("janela/altura", 140).toInt());
    this->move (this->conf->value ("janela/posicao_x", 20).toInt(),
                this->conf->value ("janela/posicao_y", 20).toInt());
    this->show ();
    this->setWindowTitle ("AMG Cronometer 1.0 [Parado]");
    this->escreveTXT ();


}
void Timer::timTimer_timeout () {
    this->s++;
    if (this->s > 59) {
        this->s = 0;
        this->m++;
        if (this->m > 59) {
            this->m = 0;
            this->h++;
            if (this->h > 23) {
                this->h = 0;
            }
        }
    }
    this->escreveTXT ();
}
void Timer::escreveTXT () {
    this->btnTime->setText (QString ("%1:%2:%3")
                                    .arg (this->h, 2, 10, QChar('0'))
                                    .arg (this->m, 2, 10, QChar('0'))
                                    .arg (this->s, 2, 10, QChar('0')));
    this->conf->setValue ("tiempo/hora", this->h);
    this->conf->setValue ("tiempo/minuto", this->m);
    this->conf->setValue ("tiempo   /segundo", this->s);
}
void Timer::btnTime_clicked (bool) {
    if (this->timTimer->isActive ()) {
        this->timTimer->stop ();
        this->setWindowTitle ("AMG Cronometer 1.0 [Parado]");
    } else {
        this->timTimer->start ();
        this->setWindowTitle ("AMG Cronometer 1.0 [Rodando]");
    }
}
void Timer::btnReset_clicked (bool) {
    if (QMessageBox::question (this, "Reiniciar o cronometro", "Tem certeza que voce deseja reiniciar o cronometro?", QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes) {
        this->timTimer->stop ();
        this->h = 0;
        this->m = 0;
        this->s = 0;
        this->escreveTXT ();
        this->setWindowTitle ("AMG Cronometer 1.0 [Parado]");
    }
}
QPushButton Timer::get_Timer(){
    return this->btnTime;
}
