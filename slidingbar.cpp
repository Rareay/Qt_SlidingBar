#include "slidingbar.h"
#include "ui_slidingbar.h"

SlidingBar::SlidingBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SlidingBar)
{
    ui->setupUi(this);

    this->setMinimumHeight(20);

    m_start = 0.01;
    m_end = 0.4;

    m_button1 = new QPushButton(this);
    m_button1->setStyleSheet("border-image: url(:/bar1.png);");
    m_button1->setMaximumWidth(7);
    m_button1->setMaximumHeight(15);
    m_button2 = new QPushButton(this);
    m_button2->setStyleSheet("border-image: url(:/bar1.png);");
    m_button2->setMaximumWidth(7);
    m_button2->setMaximumHeight(15);

    m_button1_pressed = false;
    m_button2_pressed = false;

    connect(m_button1, SIGNAL(pressed()), this, SLOT(button_1_clicked()));
    connect(m_button2, SIGNAL(pressed()), this, SLOT(button_2_clicked()));
}

SlidingBar::~SlidingBar()
{
    delete ui;
}


void SlidingBar::resizeEvent(QResizeEvent *event)
{
    //qDebug() << this->geometry().width();
    float x = m_start * ((float)this->geometry().width() - 14) + 7;
    float y = (this->geometry().height() + ui->label->height())/2 - m_button1->height();
    m_button1->move((int)x, (int)y);

    x = m_end * ((float)this->geometry().width() - 14) + 7;
    y = (this->geometry().height() - ui->label->height())/2;
    m_button2->move((int)x, (int)y);

}

void SlidingBar::mouseReleaseEvent(QMouseEvent *event)
{
    m_button1_pressed = false;
    m_button2_pressed = false;
}

void SlidingBar::mouseMoveEvent(QMouseEvent *event)
{
    int pos = event->x();
    if (pos < 7 || pos > this->geometry().width() - 7)
        return ;
    if (m_button1_pressed == true) {
        int x = event->x();
        if (x >= m_button2->x())
            return ;
        int y = (this->geometry().height() + ui->label->height())/2 - m_button1->height();
        m_button1->move(x, y);
        m_start = (float)(x - 7) / (float)(this->geometry().width() - 14);
        emit start_changed(m_start);
    } else if (m_button2_pressed == true) {
        int x = event->x();
        if (x <= m_button1->x())
            return ;
        int y = (this->geometry().height() - ui->label->height())/2;
        m_button2->move(x, y);
        m_end = (float)(x - 7) / (float)(this->geometry().width() - 14);
        emit end_changed(m_end);
    }

}

//bool SlidingBar::eventFilter(QObject *watched, QEvent *event)
//{
//    qDebug() << "q";
//
//}

void SlidingBar::button_1_clicked()
{
    m_button1_pressed = true;
}

void SlidingBar::button_2_clicked()
{
    m_button2_pressed = true;
}

void SlidingBar::set_start(float p)
{
    if (p >= m_end || p < 0 || p > 1)
        return;
    m_start = p;
    float x = m_start * ((float)this->geometry().width() - 14) + 7;
    float y = (this->geometry().height() + ui->label->height())/2 - m_button1->height();
    m_button1->move((int)x, (int)y);
}

void SlidingBar::set_end(float p)
{
    if (p <= m_start || p < 0 || p > 1)
        return;
    m_end = p;
    float x = m_end * ((float)this->geometry().width() - 14) + 7;
    float y = (this->geometry().height() - ui->label->height())/2;
    m_button2->move((int)x, (int)y);
}
