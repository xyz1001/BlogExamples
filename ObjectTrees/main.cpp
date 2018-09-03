/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include <QApplication>
#include <QTimer>
#include <QWidget>
#include "widget.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QTimer timer;
    Widget w;
    timer.setParent(&w);

    w.show();

    return a.exec();
    // 程序退出时会崩溃，timer重复析构
}
