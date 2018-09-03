#include "widget.h"
#include "ui_widget.h"

#include <QFileDialog>
#include <QToolButton>

#include "VLCQtCore/Common.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    setWindowTitle(tr("QtPlayer"));

    ui->open_btn_->setIcon(QIcon(":/open.png"));

    ui->pause_btn_->setCheckable(true);
    ui->pause_btn_->setChecked(false);
    ui->pause_btn_->setIcon(QIcon(":/pause.png"));
    ui->pause_btn_->setEnabled(false);

    ui->stop_btn_->setIcon(QIcon(":/stop.png"));
    ui->stop_btn_->setEnabled(false);

    video_widget_ = new VlcWidgetVideo(ui->player_);
    video_widget_->resize(ui->player_->size());

    instance_ = new VlcInstance(VlcCommon::args(), this);
    player_ = new VlcMediaPlayer(instance_);
    player_->setVideoWidget(video_widget_);

    connect(ui->open_btn_, &QToolButton::clicked, this, &Widget::Open);
    connect(ui->pause_btn_, &QToolButton::clicked, [this](bool checked) {
        if (checked) {
            ui->pause_btn_->setIcon(QIcon(":/play.png"));
            Pause();
        } else {
            ui->pause_btn_->setIcon(QIcon(":/pause.png"));
            Play();
        }
    });
    connect(ui->stop_btn_, &QToolButton::clicked, this, &Widget::Stop);
}

Widget::~Widget() {
    delete ui;
}

void Widget::Open() {
    QString file = QFileDialog::getOpenFileName(this, tr("Open file"),
                                                QDir::homePath(),
                                                tr("Video(*.mp4 *.avi *.mkv)"));
    if (file.isEmpty()) {
        return;
    }

    ui->open_btn_->setEnabled(false);
    ui->pause_btn_->setEnabled(true);
    ui->stop_btn_->setEnabled(true);

    media_ = new VlcMedia(file, true, instance_);
    player_->open(media_);
}

void Widget::Pause() {
    player_->pause();
}

void Widget::Play() {
    player_->play();
}

void Widget::Stop() {
    player_->stop();
    delete media_;
    media_ = nullptr;

    ui->open_btn_->setEnabled(true);
    ui->pause_btn_->setChecked(false);
    ui->pause_btn_->setIcon(QIcon(":/pause.png"));
    ui->pause_btn_->setEnabled(false);
    ui->stop_btn_->setEnabled(false);
}
