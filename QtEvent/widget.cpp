/* Copyright (©) 2018 CVTE All rights reserved.
 * Author: zhangfan3427 <zhangfan3427@cvte.com>
 *
 * -*- coding: uft-8 -*-
 */

#include "widget.h"
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Widget A");
    resize(400, 400);
    label_b_ = new MyLabel("Label B", this);
    label_b_->setFrameShape(QFrame::Box);
    label_b_->setGeometry(50, 50, 300, 300);
    label_b_->setAlignment(Qt::AlignBottom | Qt::AlignHCenter);

    label_c_ = new MyLabel("Label C", label_b_);
    label_c_->setFrameShape(QFrame::Box);
    label_c_->setGeometry(50, 50, 200, 50);

    button_c_ = new MyButton("Button C", label_b_);
    button_c_->setGeometry(50, 150, 200, 50);
}

Widget::~Widget() {}

bool Widget::event(QEvent *event) {
    if (event->type() == QEvent::Close) {
        bool exit = QMessageBox::question(
                            this, tr("Quit"),
                            tr("Are you sure to quit this application?"),
                            QMessageBox::Yes | QMessageBox::No,
                            QMessageBox::No) == QMessageBox::Yes;
        if (exit) {
            event->accept();
        } else {
            event->ignore();
        }
        return true;
    }
    return QWidget::event(event);
}

void Widget::mousePressEvent(QMouseEvent *event) {
    qDebug() << "Widget mousePressEvent";
    QWidget::mousePressEvent(event);
}

void Widget::mouseReleaseEvent(QMouseEvent *event) {
    qDebug() << "Widget mouseReleaseEvent";
    QWidget::mouseReleaseEvent(event);
}

void Widget::closeEvent(QCloseEvent *event) {
    bool exit =
            QMessageBox::question(this, tr("Quit"),
                                  tr("Are you sure to quit this application?"),
                                  QMessageBox::Yes | QMessageBox::No,
                                  QMessageBox::No) == QMessageBox::Yes;
    if (exit) {
        event->accept();
    } else {
        event->ignore();
    }
}
