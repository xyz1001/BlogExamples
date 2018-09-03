#include "player.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QTranslator translator;
    translator.load("./zh_CN.qm");
    a.installTranslator(&translator);

    Player w;
    w.show();

    return a.exec();
}
