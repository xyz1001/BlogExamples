/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
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
