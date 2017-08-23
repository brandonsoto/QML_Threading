#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QThread>
#include <QQmlEngine>
#include <QQmlContext>

#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    Worker worker;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("theworker", &worker);

    worker.start();

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
