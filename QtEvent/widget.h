/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#ifndef WIDGET_H
#define WIDGET_H

#include <QCloseEvent>
#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>
#include <QWidget>

#include "mybutton.h"
#include "mylabel.h"

class Widget : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    bool event(QEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

private:
    QPushButton *button_c_;
    QLabel *label_c_;

    QLabel *label_b_;
};

#endif  // WIDGET_H
