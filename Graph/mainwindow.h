#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QDebug>
#include <vector>

#include "graph.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Graph graph;
    QComboBox* targetComboBox;
    QPushButton* visualizeButton;
    std::vector<int> shortestPath;
    std::string algorithm;

    std::map<std::pair<int, int>, QLineEdit*> edge_inputs;
    std::map<int, std::pair<int, int>> nodes;

    void drawGraph();
    void getMatrixFromInput();
    void calculateDijkstra();
    void onVisualizeButtonClicked();
    void visualizeShortestPath(int targetNode);
    void visualizeShortestPath(int startNode, int targetNode);
    void onFloydButtonClicked();
    void visualizeShortestPathCycle();
};
#endif
