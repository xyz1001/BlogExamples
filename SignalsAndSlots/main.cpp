/* Copyright (©) 2018 CVTE All rights reserved.
 * Author: zhangfan3427 <zhangfan3427@cvte.com>
 *
 * -*- coding: uft-8 -*-
 */

#include <QCoreApplication>

#include <iostream>

#include "foo.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Foo foo;
    emit foo.Hello(10);

    return a.exec();
}
