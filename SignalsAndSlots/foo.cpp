/* Copyright (©) 2018 CVTE All rights reserved.
 * Author: zhangfan3427 <zhangfan3427@cvte.com>
 *
 * -*- coding: uft-8 -*-
 */

#include "foo.h"

#include <QDebug>

void Print(int i) {
    qDebug() << i;
}

class Callable {
public:
    void operator()(int i) {
        qDebug() << "Callable " << i;
    }
};

Foo::Foo(QObject *parent) : QObject(parent) {
    // Qt4连接语法，难以确定信号和槽的合法性和有效性
    connect(this, SIGNAL(Hello(int i)), this, SLOT(World(int i)));
    // 编译不会报错
    // connect(this, SIGNAL(Helo(int i)), this, SLOT(World(int i)));

    // Qt5连接语法，在信号或槽有重载时有问题
    // connect(this, &Foo::Hello, this, &Foo::World);

    // 解决办法
    // lambda 作为槽
    connect(this, &Foo::Hello, [this](int i) { World(i); });
    // 显式创建函数指针
    void (Foo::*world_i)(int i) = &Foo::World;
    connect(this, &Foo::Hello, this, world_i);

    // 普通函数作为槽
    connect(this, &Foo::Hello, Print);
    connect(this, &Foo::Hello, Callable());
}

void Foo::World(int i) {
    qDebug() << "Hello world!" << i;
}

void Foo::World(double /*d*/, int /*i*/) {}
