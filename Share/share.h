#ifndef SHARE_H
#define SHARE_H

#include <QObject>

class Share : public QObject{
    Q_OBJECT
public:
    explicit Share(QObject *parent = nullptr);
};

#endif // SHARE_H
