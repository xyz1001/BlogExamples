#include "widget.h"
#include <QFile>

Widget::Widget(QWidget *parent) : QWidget(parent) {
    QFile file(":/example.qss");
    file.open(QFile::ReadOnly);
    QString qss = QString(file.readAll());

    this->setStyleSheet(qss);
    this->resize(100, 100);

    button_ = new QPushButton("button", this);
    button_->setCheckable(true);

    spin_box_ = new QSpinBox(this);
    spin_box_->move(0, 30);
}

Widget::~Widget() {}
