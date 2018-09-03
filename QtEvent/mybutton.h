/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QMouseEvent>
#include <QPushButton>

class MyButton : public QPushButton {
    Q_OBJECT
public:
    using QPushButton::QPushButton;

signals:

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

public slots:
};

#endif  // MYBUTTON_H
