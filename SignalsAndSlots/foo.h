/* Copyright (©) 2018 CVTE All rights reserved.
 * Author: zhangfan3427 <zhangfan3427@cvte.com>
 *
 * -*- coding: uft-8 -*-
 */

#ifndef FOO_H
#define FOO_H

#include <QObject>

class Foo : public QObject {
    Q_OBJECT
public:
    explicit Foo(QObject *parent = nullptr);

signals:
    void Hello(int i);

public slots:
    void World(int i);
    void World(double d, int i);
};

#endif  // FOO_H
