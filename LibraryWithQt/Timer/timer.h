#pragma once

#include <memory>

class QTimer;

class IListener {
public:
    virtual ~IListener() = default;

public:
    virtual void OnTimeout() = 0;
};

class Timer {
public:
    Timer(std::shared_ptr<IListener> listener);
    ~Timer();

public:
    void Start(int msec);
    void Stop();

public:
    std::shared_ptr<IListener> listener_;
    QTimer *timer_ = nullptr;
};
