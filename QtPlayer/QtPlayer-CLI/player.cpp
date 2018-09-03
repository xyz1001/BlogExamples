/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include "player.h"

#include <QFileDialog>

#include "VLCQtCore/Common.h"

Player::Player(QWidget *parent) : QWidget(parent) {
    setWindowTitle(tr("QtPlayer"));
    resize(800, 520);

    InitButtons();

    video_widget_ = new VlcWidgetVideo(this);
    video_widget_->setGeometry(0, 0, 800, 450);

    instance_ = new VlcInstance(VlcCommon::args(), this);
    player_ = new VlcMediaPlayer(instance_);
    player_->setVideoWidget(video_widget_);

    connect(open_btn_, &QToolButton::clicked, this, &Player::Open);
    connect(pause_btn_, &QToolButton::clicked, [this](bool checked) {
        if (checked) {
            pause_btn_->setIcon(QIcon(":./play.png"));
            Pause();
        } else {
            pause_btn_->setIcon(QIcon(":./pause.png"));
            Play();
        }
    });
    connect(stop_btn_, &QToolButton::clicked, this, &Player::Stop);
}

void Player::Open() {
    QString file = QFileDialog::getOpenFileName(this, tr("Open file"),
                                                QDir::homePath(),
                                                tr("Video(*.mp4 *.avi *.mkv)"));
    if (file.isEmpty()) {
        return;
    }

    open_btn_->setEnabled(false);
    pause_btn_->setEnabled(true);
    stop_btn_->setEnabled(true);

    media_ = new VlcMedia(file, true, instance_);
    player_->open(media_);
}

void Player::Pause() {
    player_->pause();
}

void Player::Play() {
    player_->play();
}

void Player::Stop() {
    player_->stop();
    delete media_;
    media_ = nullptr;

    open_btn_->setEnabled(true);
    pause_btn_->setChecked(false);
    pause_btn_->setIcon(QIcon(":./pause.png"));
    pause_btn_->setEnabled(false);
    stop_btn_->setEnabled(false);
}

void Player::InitButtons() {
    open_btn_ = new QToolButton(this);
    open_btn_->setGeometry(300, 460, 50, 50);
    open_btn_->setIcon(QIcon(":./open.png"));

    pause_btn_ = new QToolButton(this);
    pause_btn_->setGeometry(375, 460, 50, 50);
    pause_btn_->setCheckable(true);
    pause_btn_->setChecked(false);
    pause_btn_->setIcon(QIcon(":./pause.png"));
    pause_btn_->setEnabled(false);

    stop_btn_ = new QToolButton(this);
    stop_btn_->setGeometry(450, 460, 50, 50);
    stop_btn_->setIcon(QIcon(":./stop.png"));
    stop_btn_->setEnabled(false);
}
