#ifndef WIDGET_H
#define WIDGET_H

#include <QPushButton>
#include <QSpinBox>
#include <QWidget>

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QSpinBox *spin_box_;
    QPushButton *button_;
};

#endif  // WIDGET_H
