#ifndef LECANON_H
#define LECANON_H

#include<QWidget>
#include<QMouseEvent>
#include<QtCore>
#include<QTimer>
#include<QObject>
#include<QMainWindow>
#include<QPushButton>
#include<QSlider>
#include<QLCDNumber>
#include<QLineEdit>
#include<QDoubleSpinBox>
#include<QTextDocument>
#include<QTextLayout>
#include<QLabel>
#include<QVector>


class leCanon : public QWidget
{

    Q_OBJECT

public:
    explicit leCanon(QWidget *parent =0);
    double f(double x,double y);
    double RK(double(*f)(double,double), double x1, double x0, double y0);
    ~leCanon();
    void dessiner();


protected:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *);


private:
    int Ox,Oy;
    bool ismoving;
    QTimer timer;
    double z;
    QPushButton *w;
    QPushButton *q;
    QPushButton *b;
    QPushButton *r;
    QSlider *s;
    QDoubleSpinBox *l;
    QDoubleSpinBox *o;
    QDoubleSpinBox *p;
    QDoubleSpinBox *nbo;
    QLabel *c;
    QLabel *d;
    QLabel *g;
    QLabel *a;
    QLabel *nbobine;
    double nbob;
    double i;
    double n;
    double m;
    double posChamp;
    QVector<int>posi;


public slots:
    void updatez();
    void on_pushButtonclicked();
    void on_pushButton_2_clicked();
    void setI(double a);
    void setN(double a);
    void setM(double a);
    void setNbob(double a);
//    void recommencer();

};










#endif // LECANON_H
