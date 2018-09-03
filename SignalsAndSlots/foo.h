/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
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
