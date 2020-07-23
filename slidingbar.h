#ifndef SLIDINGBAR_H
#define SLIDINGBAR_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>
#include <QtUiPlugin/QDesignerExportWidget>
#include <QDebug>

namespace Ui {
class SlidingBar;
}

class QDESIGNER_WIDGET_EXPORT SlidingBar : public QWidget
{
    Q_OBJECT

public:
    explicit SlidingBar(QWidget *parent = 0);
    ~SlidingBar();
    float m_start;
    float m_end;

protected:
    virtual void resizeEvent(QResizeEvent *event) override;
    //bool eventFilter(QObject *watched, QEvent *event);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

private:
    Ui::SlidingBar *ui;
    QPushButton * m_button1;
    QPushButton * m_button2;
    bool m_button1_pressed;
    bool m_button2_pressed;

private slots:
    void button_1_clicked();
    void button_2_clicked();

signals:
    void start_changed(float p);
    void end_changed(float p);

public slots:
    void set_start(float p);
    void set_end(float p);
};

#endif // SLIDINGBAR_H
