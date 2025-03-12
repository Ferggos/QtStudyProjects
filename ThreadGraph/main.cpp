#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "graphalgorithm.h"
#include "hungarianalgorithm.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    GraphAlgorithm graphAlgorithm;
    engine.rootContext()->setContextProperty("graphAlgorithm", &graphAlgorithm);

    std::vector<std::vector<double>> costMatrix = {
        {24, 18, 25, 17, 21},
        {31, 22, 23, 24, 30},
        {17, 19, 21, 15, 17},
        {30, 20, 20, 25, 28},
        {19, 20, 24, 23, 19}
    };

    HungarianAlgorithm maximizationAlg(costMatrix, true);
    HungarianAlgorithm minimizationAlg(costMatrix, false);


    // Solve both problems
    double maxCost = maximizationAlg.solve();
    double minCost = minimizationAlg.solve();


    engine.rootContext()->setContextProperty("minimizationAlg", &minimizationAlg);
    engine.rootContext()->setContextProperty("maximizationAlg", &maximizationAlg);

    qDebug() << "Total min cost:" << minCost;
    qDebug() << "Total max cost:" << maxCost;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection
        );

    engine.loadFromModule("ThreadGraph", "Main");

    return app.exec();
}
