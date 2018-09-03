/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include "widget.h"
#include <QDebug>
#include <QLabel>
#include <QNetworkInterface>
#include <QPushButton>
#include <algorithm>

Widget::Widget(QWidget *parent) : QWidget(parent) {
    button_ = new QPushButton("Button", this);

    frame_ = new QFrame(this);
    frame_->setGeometry(0, 50, 150, 50);
    label_ = new QLabel("Label", frame_);
    edit_ = new QLineEdit(frame_);
    edit_->move(50, 0);
    edit_->setText("Edit");

    // 打印当前组件信息
    dumpObjectInfo();
    // 打印以当前节点为根节点的对象树，其是整个对象树的一颗子树
    dumpObjectTree();
}

Widget::~Widget() {}
