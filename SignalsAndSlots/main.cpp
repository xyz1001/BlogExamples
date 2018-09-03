/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
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
