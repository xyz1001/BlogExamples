/* Copyright (©) 2018 CVTE All rights reserved.
 * Author: zhangfan3427 <zhangfan3427@cvte.com>
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
