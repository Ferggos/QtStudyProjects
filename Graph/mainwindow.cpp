    #include "mainwindow.h"
    #include "./ui_mainwindow.h"
    #include <QGraphicsEllipseItem>
    #include <QGraphicsLineItem>
    #include <QGraphicsProxyWidget>
    #include <QGraphicsTextItem>
    #include <QLineEdit>
    #include <QPen>
    #include <QComboBox>
    #include <QPushButton>

    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
        , scene(new QGraphicsScene(this))
    {
        ui->setupUi(this);

        ui->graphicsView->setScene(scene);
        ui->graphicsView->setRenderHint(QPainter::Antialiasing);

        targetComboBox = new QComboBox(this);
        for (int i = 1; i <= 8; ++i) {
            targetComboBox->addItem(QString::number(i));
        }
        targetComboBox->setGeometry(20, 400, 100, 30);

        visualizeButton = new QPushButton("Показать путь", this);
        visualizeButton->setGeometry(130, 400, 100, 30);

        connect(visualizeButton, &QPushButton::clicked, this, &MainWindow::onVisualizeButtonClicked);

        drawGraph();
    }
    MainWindow::~MainWindow()
    {
        delete ui;
    }

    void MainWindow::getMatrixFromInput()
    {
        std::vector<std::vector<int>> matrix(SIZE, std::vector<int>(SIZE, INF));
        for (const auto& edge : edge_inputs) {
            int weight = edge.second->text().toInt();
            int start_node = edge.first.first;
            int end_node = edge.first.second;
            matrix[start_node - 1][end_node - 1] = weight;
            matrix[end_node - 1][start_node - 1] = weight;
        }

        graph.InitMatrix(matrix);
    }

    void MainWindow::onVisualizeButtonClicked()
    {
        int targetNode = targetComboBox->currentText().toInt();
        if (algorithm == "Dijkstra")
            visualizeShortestPath(targetNode);
        else
        {
            int startNodeFloyd = ui->startNodeInput->text().toInt();
            visualizeShortestPath(startNodeFloyd, targetNode);
        }

    }

    void MainWindow::drawGraph()
    {
        // Координаты узлов
        std::map<int, std::pair<int, int>> node_positions = {
            {1, {150, 50}},
            {2, {300, 100}},
            {3, {350, 200}},
            {4, {300, 300}},
            {5, {150, 350}},
            {6, {50, 300}},
            {7, {0, 200}},
            {8, {50, 100}}
        };


        // Список рёбер (стартовый узел, конечный узел)
        std::vector<std::pair<int, int>> edges = {
            {1, 2}, {1, 8}, {1, 5}, {1, 6}, {2, 8}, {2, 3}, {2, 4},
            {3, 4}, {4, 5}, {4, 6}, {6, 7}, {6, 8}, {7, 8}
        };

        for (const auto& node : node_positions) {
            int id = node.first;
            int x = node.second.first;
            int y = node.second.second;

            nodes[id] = {x + 15, y + 15};
        }

        QMap<QPair<int, int>, int> initial_weights = {
            {{1, 2}, 1}, {{1, 3}, 4}, {{1, 4}, 3}, {{1, 6}, 3}, {{1, 5}, 4}, {{1, 8}, 5},
            {{2, 3}, 7}, {{2, 4}, 6}, {{2, 8}, 2}, {{3, 4}, 8}, {{4, 5}, 3},
            {{5, 6}, 2}, {{4, 6}, 2},
            {{6, 7}, 5}, {{6, 8}, 1}, {{7, 8}, 4}
        };

        for (const auto& edge : edges) {
            int start_node = edge.first;
            int end_node = edge.second;
            auto start_pos = nodes[start_node];
            auto end_pos = nodes[end_node];

            QGraphicsLineItem* line = scene->addLine(start_pos.first, start_pos.second, end_pos.first, end_pos.second, QPen(Qt::black, 2));

            int mid_x = (start_pos.first + end_pos.first) / 2;
            int mid_y = (start_pos.second + end_pos.second) / 2;

            QLineEdit* input_box = new QLineEdit();
            input_box->setFixedWidth(40);
            input_box->setStyleSheet("border: 1px solid black; background: white; color: black;");

            QPair<int, int> edge_key = {start_node, end_node};
            if (initial_weights.contains(edge_key)) {
                input_box->setText(QString::number(initial_weights[edge_key]));
            }

            QGraphicsProxyWidget* proxy_widget = scene->addWidget(input_box);
            proxy_widget->setPos(mid_x - 20, mid_y - 10);

            edge_inputs[{start_node, end_node}] = input_box;

            connect(input_box, &QLineEdit::textChanged, this, [=](const QString& text){
                edge_inputs[{start_node, end_node}] = input_box;
            });
        }

        for (const auto& node : node_positions) {
            int id = node.first;
            int x = node.second.first;
            int y = node.second.second;

            QGraphicsEllipseItem* ellipse = scene->addEllipse(x, y, 30, 30, QPen(Qt::black, 2), QBrush(Qt::white));

            QGraphicsTextItem* text = scene->addText(QString::number(id));
             text->setDefaultTextColor(Qt::black);

            text->setPos(x + 10, y + 5);
        }
        connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::calculateDijkstra);
        connect(ui->floydButton, &QPushButton::clicked, this, &MainWindow::onFloydButtonClicked);
        connect(ui->salesmanSolution, &QPushButton::clicked, this, &MainWindow::visualizeShortestPathCycle);
    }

    void MainWindow::onFloydButtonClicked()
    {
        std::vector<std::vector<int>> distances;
        algorithm = "Floyd";
        getMatrixFromInput();
        int startNode = ui->startNodeInput->text().toInt();
        graph.FloydWarshallAlgorithm();
        distances = graph.GetFloydDistances();
        QString pathString;
        pathString += "Кратчайшие пути до вершин:\n";

        for (int i = 0; i < SIZE; ++i) {
            if (distances[startNode - 1][i] != INF) {
                pathString += "Вершина " + QString::number(i + 1) + ": " + QString::number(distances[startNode - 1][i]) + "\n";
            } else {
                pathString += "Вершина " + QString::number(i + 1) + ": Нет пути\n";
            }
        }

        ui->Label->setText(pathString);

        qDebug() << "Кол-во итераций Флойда: " << graph.GetDebugInfo();
    }

    void MainWindow::calculateDijkstra()
    {
        int distances[SIZE];
        algorithm = "Dijkstra";
        getMatrixFromInput();
        int startNode = ui->startNodeInput->text().toInt();
        graph.DijkstraAlgorithm(startNode);

        QString pathString;
        pathString += "Кратчайшие пути до вершин:\n";
        graph.GetDijkstraDistances(distances);
        for (int i = 0; i < SIZE; ++i) {
            if (distances[i] != INF) {
                pathString += "Вершина " + QString::number(i + 1) + ": " + QString::number(distances[i]) + "\n";
            } else {
                pathString += "Вершина " + QString::number(i + 1) + ": Нет пути\n";
            }
        }

        ui->Label->setText(pathString);

        qDebug() << "Кол-во итераций Дейкстры: " << graph.GetDebugInfo();
    }

    void MainWindow::visualizeShortestPath(int targetNode)
    {
        int path[SIZE];
        int pathLen = 0;

        pathLen = graph.GetWay(path, targetNode - 1);

        scene->clear();
        drawGraph();

        for (int i = 0; i < pathLen - 1; ++i) {
            int start = path[i];
            int end = path[i + 1];

            if (start == 0 || end == 0)
                break;

            auto start_pos = nodes[start];
            auto end_pos = nodes[end];

            scene->addLine(start_pos.first, start_pos.second, end_pos.first, end_pos.second, QPen(Qt::blue, 3));
        }
    }

    void MainWindow::visualizeShortestPath(int startNode, int targetNode)
    {
        int path[SIZE];
        int pathLen = 0;
        pathLen = graph.GetWayFloyd(startNode - 1, targetNode - 1, path);

        scene->clear();
        drawGraph();

        for (int i = 0; i < pathLen - 1; ++i) {
            int start = path[i];
            int end = path[i + 1];

            auto start_pos = nodes[start];
            auto end_pos = nodes[end];

            scene->addLine(start_pos.first, start_pos.second, end_pos.first, end_pos.second, QPen(Qt::blue, 3));
        }
    }

    void MainWindow::visualizeShortestPathCycle()
    {
        getMatrixFromInput();
        int startNode = ui->startNodeInput->text().toInt();
        std::vector<int> bestPath(SIZE);
        int bestWeight = 0;
        graph.findOptimizedPath(startNode - 1, bestPath, bestWeight);

        scene->clear();
        drawGraph();

        QString pathString;
        for (size_t i = 0; i < bestPath.size(); ++i) {
            pathString += QString::number(bestPath[i]);
            if (i < bestPath.size() - 1) {
                pathString += " -> ";
            }
        }
        pathString += "\n Цена пути: " + QString::number(bestWeight);

        ui->Label->setText(pathString);

        for (size_t i = 0; i < bestPath.size() - 1; ++i) {
            int start = bestPath[i];
            int end = bestPath[i + 1];

            auto start_pos = nodes[start];
            auto end_pos = nodes[end];

            scene->addLine(start_pos.first, start_pos.second, end_pos.first, end_pos.second, QPen(Qt::blue, 3));
        }
    }





