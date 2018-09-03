#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "VLCQtCore/Instance.h"
#include "VLCQtCore/Media.h"
#include "VLCQtCore/MediaPlayer.h"
#include "VLCQtWidgets/WidgetVideo.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void Open();
    void Pause();
    void Play();
    void Stop();

private:
    VlcInstance *instance_;
    VlcMedia *media_;
    VlcMediaPlayer *player_;
    VlcWidgetVideo *video_widget_;

private:
    Ui::Widget *ui;
};

#endif  // WIDGET_H
