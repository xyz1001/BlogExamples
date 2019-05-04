#pragma once

#include <QCoreApplication>
#include <QThread>

class QEventLoopThread : public QThread {
public:
    // 单例
    QEventLoopThread(const QEventLoopThread &) = delete;
    QEventLoopThread operator=(const QEventLoopThread &) = delete;

    ~QEventLoopThread();

public:
    static QEventLoopThread &GetInstance();

protected:
    void run() override;

private:
    explicit QEventLoopThread(QObject *parent = nullptr);

private:
    QCoreApplication *app_{};
};
