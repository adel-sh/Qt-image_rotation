#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPainter>

int couner = 0;
bool on_off = true;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(":/new/prefix1/car"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_3_clicked()
{
    on_off = false;
    QApplication::exit();
}

void Widget::on_pushButton_clicked()
{
    on_off = true;
    while(on_off == true){

    QApplication::processEvents();

    QPixmap ship(":/new/prefix1/car");
    QPixmap rotate(ship.size());

    QPainter p(&rotate);
    p.setRenderHint(QPainter::Antialiasing);
    p.setRenderHint(QPainter::SmoothPixmapTransform);
    p.setRenderHint(QPainter::HighQualityAntialiasing);
    p.translate(rotate.size().width() / 2, rotate.size().height() / 2);
    p.rotate(couner);
    p.translate(-rotate.size().width() / 2, -rotate.size().height() / 2);

    p.drawPixmap(0, 0, ship);
    p.end();

    ui->label->setPixmap(rotate);

    couner++;
    }
}

void Widget::on_pushButton_2_clicked()
{
    on_off = false;
}
