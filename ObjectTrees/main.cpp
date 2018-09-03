/* Copyright (©) 2018 CVTE All rights reserved.
 * Author: zhangfan3427 <zhangfan3427@cvte.com>
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
