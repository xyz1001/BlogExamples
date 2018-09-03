/* Copyright (©) 2018 CVTE All rights reserved.
 * Author: zhangfan3427 <zhangfan3427@cvte.com>
 *
 * -*- coding: uft-8 -*-
 */

#include "mybutton.h"
#include <QDebug>

void MyButton::mousePressEvent(QMouseEvent *event) {
    qDebug() << "MyButton mousePressEvent";
    QPushButton::mousePressEvent(event);
}

void MyButton::mouseReleaseEvent(QMouseEvent *event) {
    qDebug() << "MyButton mouseReleaseEvent";
    QPushButton::mouseReleaseEvent(event);
}
