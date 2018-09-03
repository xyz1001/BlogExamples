/* Copyright (©) 2018 CVTE All rights reserved.
 * Author: zhangfan3427 <zhangfan3427@cvte.com>
 *
 * -*- coding: uft-8 -*-
 */

#ifndef WIDGET_H
#define WIDGET_H

#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QPushButton *button_;

    QFrame *frame_;
    QLabel *label_;
    QLineEdit *edit_;
};

#endif  // WIDGET_H
