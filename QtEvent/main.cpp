/* Copyright (©) 2018 CVTE All rights reserved.
 * Author: zhangfan3427 <zhangfan3427@cvte.com>
 *
 * -*- coding: uft-8 -*-
 */

#include <QApplication>

#include "widget.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
