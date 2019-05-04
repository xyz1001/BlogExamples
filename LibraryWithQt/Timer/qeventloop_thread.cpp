#include "qeventloop_thread.h"

QEventLoopThread::QEventLoopThread(QObject *parent) : QThread(parent) {
    start();
}

QEventLoopThread::~QEventLoopThread() {
    app_->quit();
    // delete app_;  // 会导致崩溃，原因不明
    quit();
    wait();
}

QEventLoopThread &QEventLoopThread::GetInstance() {
    static QEventLoopThread event_loop;
    return event_loop;
}

void QEventLoopThread::run() {
    // 如果已经是Qt程序，则不再创建QCoreApplication对象
    if (app_) {
        return;
    }
    // 开启事件循环
    int argc{};
    char *argv{};
    app_ = new QCoreApplication(argc, &argv);
    app_->exec();
}
