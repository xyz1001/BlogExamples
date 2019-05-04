#include "timer.h"

#include <QTimer>

#include "qeventloop_thread.h"

Timer::Timer(std::shared_ptr<IListener> listener) : listener_(listener) {
    timer_ = new QTimer;
}

Timer::~Timer() {
    // Qt 5.10之前版本
    // QMetaObject::invokeMethod(timer_, "stop", Qt::BlockingQueuedConnection);
    // Qt 5.10及之后版本
    QMetaObject::invokeMethod(timer_, &QTimer::stop,
                              Qt::BlockingQueuedConnection);
    delete timer_;
}

void Timer::Start(int msec) {
    timer_->moveToThread(&QEventLoopThread::GetInstance());
    QObject::connect(timer_, &QTimer::timeout,
                     [this] { listener_->OnTimeout(); });
    QMetaObject::invokeMethod(timer_, "start", Qt::QueuedConnection,
                              Q_ARG(int, msec));
}

void Timer::Stop() {
    QMetaObject::invokeMethod(timer_, "stop", Qt::QueuedConnection);
}
