#include "lecanon.h"
#include<QPainter>
#include<QMouseEvent>
#include<QTimer>
#include<iostream>
#include<QPushButton>

using namespace std;

leCanon::leCanon(QWidget *parent):QWidget(parent),timer(this)
{
   setGeometry(0,0,1500,790);
   setMinimumSize(1400,650);

   Ox = 320;
   Oy = 260;
   z = 320;
   nbob=1;
   posChamp=Ox+(800/(nbob+1))-((800/(nbob+1))/(nbob+1))/2;
   posi.push_back(posChamp);


   QPushButton *w = new QPushButton(this);
   w->setToolTip("Commencer la simulation");
   w->setCursor(Qt::PointingHandCursor);
   w->setGeometry(420,700,200,55);
   w->setText("Start");


   QPushButton *b = new QPushButton(this);
   b->setToolTip("Arreter la simulation");
   b->setCursor(Qt::PointingHandCursor);
   b->setGeometry(620,700,200,55);
   b->setText("Stop");


   QPushButton *q = new QPushButton(this);
   q->setToolTip("Quitter le programme");
   q->setCursor(Qt::PointingHandCursor);
   q->setGeometry(820,700,200,55);
   q->setText("Quit");

    l = new QDoubleSpinBox(this);  //intensite
    l->move(160, 390);
    l->setRange(1,20);
    c= new QLabel(this);
    c->setText("Intensité:");
    c->move(30,393);

    o = new QDoubleSpinBox(this);  //nombre de spires
    o->move(160, 430);
    o->setRange(1,20);
    d= new QLabel(this);
    d->setText("Nombre de Spires:");
    d->move(30,433);

    p = new QDoubleSpinBox(this);  //masse
    p->move(160, 350);
    p->setRange(1,18);
    g= new QLabel(this);
    g->setText("Masse:");
    g->move(30,353);

    nbo = new QDoubleSpinBox(this);  //pour Nb Bobine
    nbo->move(160, 470);
    nbo->setRange(1,4);
    nbobine= new QLabel(this);
    nbobine->setText("Nombre de Bobines:");
    nbobine->move(30,473);


    a = new QLabel (this);
    a->move (310 , 35);
    a->setText ("<font color = black>  Le Canon Magnetique </font> ");
    a->setFont (QFont ("Times new Roman" , 90));



//   QPushButton *r = new QPushButton(this);  reset
//   r->setToolTip("Recommencer le programme");
//   r->setCursor(Qt::PointingHandCursor);
//   r->setGeometry(330,180,50,20);
//   r->setText("Reset");


   connect(l,SIGNAL(valueChanged(double)),this,SLOT(setI(double)));
   connect(o,SIGNAL(valueChanged(double)),this,SLOT(setN(double)));
   connect(p,SIGNAL(valueChanged(double)),this,SLOT(setM(double)));
   connect(q,SIGNAL(clicked()),this,SLOT(close()));
   connect(w,SIGNAL(clicked()),this,SLOT(on_pushButtonclicked()));
   connect(b,SIGNAL(clicked()),this,SLOT(on_pushButton_2_clicked()));
   connect(nbo,SIGNAL(valueChanged(double)),this,SLOT(setNbob(double)));

//   connect(r,SIGNAL(clicked()),this,SLOT(reset()));  reset
   setMouseTracking(true);
   ismoving=false;
}

void leCanon::setI(double a)
{
    i=a;
}

void leCanon::setN(double a)
{
    n=a;
}

void leCanon::setM(double a)
{
    m=a;
}

void leCanon::setNbob(double a)
{
    nbob=a;
    int size=(800/(nbob+1))/(nbob+1);
    posChamp=Ox+(800/(nbob+1))-((800/(nbob+1))/(nbob+1))/2;
    posi.clear();
    for(int i=0,k=0;i<nbob;i++,k+=(nbob+1)*size){
        posi.push_back(posChamp+k);
    }
    repaint();
}

leCanon::~leCanon()
{}

void leCanon::paintEvent(QPaintEvent *)
{
    QPainter painter(this);




    painter.drawLine(Ox,Oy-1.5,Ox+800,Oy-1.5);//canon
    painter.drawLine(Ox,Oy+31,Ox+800,Oy+31);
    painter.drawLine(Ox,Oy-2.5,Ox+800,Oy-2.5);
    painter.drawLine(Ox,Oy+32,Ox+800,Oy+32);
    painter.drawLine(Ox-1,Oy-2,Ox-1,Oy+32);

    painter.drawLine(Ox,Oy-1,Ox+800,Oy-1);//canon
    painter.drawLine(Ox,Oy+30.5,Ox+800,Oy+30.5);
    painter.drawLine(Ox,Oy,Ox,Oy+30);



    QBrush brush(QColor(75,20,0));//haddiya
    painter.fillRect(Ox+15,Oy+30,25,280,brush);
    painter.fillRect(Ox+760,Oy+30,25,280,brush);

    painter.drawLine(Ox-30,Oy+250,Ox+860,Oy+250);//ared
    painter.drawLine(Ox-50,Oy+370,Ox+850,Oy+370);
    painter.setPen(QColor(128,128,128));
    for(int i=Ox-48;i<Ox+850;i+=10)
    {
        if (i== Ox+12 || i== Ox+22 || i == Ox+752 || i == Ox+762)
        {
        painter.drawLine(i+10,Oy+310,i,Oy+370);
        }
        else if(i== Ox+2) {

            painter.drawLine(i+12,Oy+300,i,Oy+370);
        }
        else if (i==Ox+742)
        {
            painter.drawLine(i+18,Oy+270,i,Oy+370);
        }
        else {

          painter.drawLine(i+20,Oy+250,i,Oy+370);
        }

    }


    int size=(800/(nbob+1))/(nbob+1);    //bobine
    for(int k=0,j=0;j<nbob;j++,k+=(nbob+1)*size){
      for(int i=0;i<=size+2;i+=10){
          double posX=Ox+(800/(nbob+1))-size/2+k;
          painter.drawEllipse(posX+i,Oy-11,20,60);
          painter.drawLine(posX,Oy+150,posX,Oy-10);
          painter.drawLine(posX+size+20,Oy+150,posX+size+20,Oy-10);
          painter.drawLine(posX,Oy+150,posX+size/2,Oy+150);
          painter.drawLine(posX+(size+20)/2,Oy+150,posX+size+20,Oy+150);
          painter.drawLine(posX+size/2,Oy+165,posX+size/2,Oy+135);
          painter.drawLine(posX+(size+20)/2,Oy+157,posX+(size+20)/2,Oy+143);
      }
    }
//    painter.drawLine(Ox+300,Oy+150,Ox+300,Oy-10);//generateur
//    painter.drawLine(Ox+520,Oy+150,Ox+520,Oy-10);
//    painter.drawLine(Ox+300,Oy+150,Ox+395,Oy+150);
//    painter.drawLine(Ox+405,Oy+150,Ox+520,Oy+150);
//    painter.drawLine(Ox+395,Oy+165,Ox+395,Oy+135);
//    painter.drawLine(Ox+405,Oy+157,Ox+405,Oy+143);


    painter.setPen(QColor(100,0,0,200));//sphere
    painter.setBrush(QBrush(Qt::red));
    painter.drawEllipse(z,Oy,30,30);

}



void leCanon::mouseMoveEvent(QMouseEvent *e)
{
    if(ismoving)
    {
        if(e->pos().x()>=320)
        {
        z=e->pos().x();
        repaint();
        }
    }
}

void leCanon::mousePressEvent(QMouseEvent *e){
    int dx=e->pos().x();
    int dy=e->pos().y();
    if (dx>=Ox && (dy>=Oy && dy<=Oy+30))
    {
        ismoving=true;
    }
}

void leCanon::mouseReleaseEvent(QMouseEvent *){
    ismoving=false;
}
double leCanon::f(double x, double y){
    return (-n*n*i*i*5.54+ 4.36)*exp((-1.279*m)*x) + n*n*i*i*4.33 + 4.36 ;
}

void leCanon::updatez()
{

    double x0 = 10;
    float y0 = 0;
    double x1;
    for (int i = 0; i<1; ++i)
    {
    x1 = x0 + 0.8*rand() / RAND_MAX;
    double K1 = f(x0, y0);
    double dx = x1 - x0;
    double K2 = f(x0 + dx / 2, y0 + dx / 2 * K1);
    double K3 = f(x0 + dx, y0 + dx*K2);
    z += y0 + dx / 6 * (K1 + 4 * K2 + K3);
    x0 = x1;
    y0 = z;
    for(int i=1;i<=posi.size();i++){
        if(z>=posi[i-1])
            z+=3*i;
    }
    repaint();
    }

}

void leCanon::on_pushButtonclicked()
{
    timer.start(20);
    timer.setInterval(10);
    connect(&timer,SIGNAL(timeout()),this,SLOT(updatez()));
}


void ::leCanon::on_pushButton_2_clicked()
{
    timer.stop();
    z=320;
    repaint();
}






//void leCanon::recommencer()
//{
//    z=250;
//    timer.stop();
//}
