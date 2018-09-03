/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#ifndef PLAYER_H_LDRNQIXJ
#define PLAYER_H_LDRNQIXJ

#include <QToolButton>
#include <QWidget>

#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>
#include <VLCQtWidgets/WidgetVideo.h>

class Player : public QWidget {
    Q_OBJECT

public:
    explicit Player(QWidget *parent = nullptr);

private:
    void Open();
    void Pause();
    void Play();
    void Stop();

private:
    void InitButtons();

private:
    VlcInstance *instance_;
    VlcMedia *media_;
    VlcMediaPlayer *player_;
    VlcWidgetVideo *video_widget_;

private:
    QToolButton *open_btn_;
    QToolButton *pause_btn_;
    QToolButton *stop_btn_;
};

#endif  // PLAYER_H_LDRNQIXJ
