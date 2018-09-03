/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include "mylabel.h"
#include <QDebug>

void MyLabel::mousePressEvent(QMouseEvent *event) {
    qDebug() << "MyLabel mousePressEvent";
    QLabel::mousePressEvent(event);
}

void MyLabel::mouseReleaseEvent(QMouseEvent *event) {
    qDebug() << "MyLabel mouseReleaseEvent";
    if (event->buttons() & Qt::LeftButton) {
        emit onClick();
    }
    QLabel::mouseReleaseEvent(event);
}
