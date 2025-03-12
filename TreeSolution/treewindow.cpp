#include "treewindow.h"
#include "ui_treewindow.h"
#include <random>
#include <QString>
#include <iostream>

TreeWindow::TreeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TreeWindow)
{
    ui->setupUi(this);

    std::random_device rd;
    std::mt19937 mersenne(rd());
    std::uniform_int_distribution<int> dist(-150, 100);

    for (int i = 0; i < 15; ++i)
        myTree.Insert(dist(mersenne));


    QGraphicsScene* scene = new QGraphicsScene(this);

    QGraphicsTextItem* text = scene->addText("Бинарное дерево:", QFont("Arial", 10, QFont::Bold));
    text->setDefaultTextColor(Qt::black);
    text->setPos(0, 0);

    ui->graphicsView->setScene(scene);

    int rootX = ui->graphicsView->width() / 2;
    int rootY = 50;
    int horizontalGap = 250;
    DrawTree(myTree.root.get(), rootX, rootY, horizontalGap, scene);

    int product = 1;
    int sum = myTree.FindSumAndProd(product);
    QString lrDesc = myTree.FindNodesWithUnequalLeftRightDescendants();
    QString lrHeight = myTree.FindNodesWithUnequalSubtreeHeights();
    int X = 70;
    int resOccur = myTree.CountOccurrences(X);
    int maxVal = myTree.FindMaxElement();
    int maxValCount = myTree.CountMaxOccurrences(maxVal);
    bool hasDuplicate = myTree.HasDuplicate();
    int maxDuplVal = myTree.FindMaxDuplicateCount();
    QString hasDuplStr = hasDuplicate ? "Да" : "Нет";
    QString isSymmetric = myTree.IsSymmetric() ? "Да" : "Нет";
    QString isBinSTree = myTree.IsBinarySearchTree() ? "Да" : "Нет";
    QString leavesInOrder = myTree.GetLeavesInAscendingOrder();
    QString minWeightPaths = myTree.FindMinWeightPaths();
    int lastPosLevel = myTree.FindLastLevelWithPositive();
    QString maxAtEachLevel = myTree.FindMaxAtEachLevel();
    QString intAndLeafNodes = myTree.CountInternalAndLeafNodes();
    int sumOfOddLevels = myTree.SumOddLevelElements();
    QString MinMaxLeafPaths = myTree.FindMinMaxLeafPaths();
    ui -> textBrowser_2 -> setText("2. Сумма элеметов дерева: " + QString::number(sum) + "\n" + "3. Произведение вершин, кратных 3: " + QString::number(product) + "\n"
                               + "4. Вершины, у которых кол-во потомков поддеревьев не равны: " + lrDesc + "\n"
                               + "5. Вершины, у которых высоты поддеревьев не равны: " + lrHeight + "\n"
                               + "6. Количество входений " + QString::number(X) + " в дерево: " + QString::number(resOccur) + "\n"
                               + "7. Максимальный элемент динарного дерева: " + QString::number(maxVal) + "\nКол-во вхождений: " + QString::number(maxValCount) + "\n"
                               + "8. Есть ли в дереве хотя бы два одинаковых элемента: " + hasDuplStr + "\n"
                               + "9. Максимальное количество дубликатов в дереве: " + QString::number(maxDuplVal)
                               + "10. Является ли дерево симметричным: " + isSymmetric + "\n"
                               + "11. Является ли бинарным деревом поиска: " + isBinSTree + "\n"
                               + "12. Листья в порядке возрастания: " + leavesInOrder + "\n"
                               + "14. Пути ведущие от корня к листям: \n" + minWeightPaths
                               + "15. Последний уровень с положительными элементами: " + QString::number(lastPosLevel) + "\n"
                               + "16. Максимальный элемент на каждом уровне: " + maxAtEachLevel + "\n"
                               + "17. Количество внутренних вершин и листьев: " + intAndLeafNodes + "\n"
                               + "18. Сумма элементов всех нечётных чисел: " + QString::number(sumOfOddLevels) + "\n"
                               + "19. Минимальные и максимальные пути между листьями: \n" + MinMaxLeafPaths + "\n"
                                   + "21. Инфиксный обход: \n" + myTree.Print(2) + "\n" + "Префиксный обход: \n" + myTree.Print(1)
                                   + "\n"+ "Постфиксный обход: \n" + myTree.Print(3) + "\n" );

    auto [negTree, posTree] = myTree.CreateBalancedTreesFromPosNeg();

    scene = new QGraphicsScene(this);

    text = scene->addText("Дерево из отрицательных вершин", QFont("Arial", 10, QFont::Bold));
    text->setDefaultTextColor(Qt::black);
    text->setPos(0, 0);

    ui->graphicsView_4->setScene(scene);

    rootX = ui->graphicsView_2->width() / 2;
    rootY = 50;
    horizontalGap = 250;
    DrawTree(negTree.root.get(), rootX, rootY, horizontalGap, scene);

    scene = new QGraphicsScene(this);

    text = scene->addText("Дерево из положительных вершин", QFont("Arial", 10, QFont::Bold));
    text->setDefaultTextColor(Qt::black);
    text->setPos(0, 0);

    ui->graphicsView_3->setScene(scene);

    rootX = ui->graphicsView_2->width() / 2;
    rootY = 50;
    horizontalGap = 250;
    DrawTree(posTree.root.get(), rootX, rootY, horizontalGap, scene);

    myTree.ConvertToBPlusTree();
    myTree.bPlusTree ->PrintTree();

    int removeNodes = myTree.RemoveNodesToMakeStrictBinaryTree();
    QString strictBinaryTree = myTree.PrintHierarchical();
    scene = new QGraphicsScene(this);

    text = scene->addText("Новое дерево:", QFont("Arial", 10, QFont::Bold));
    text->setDefaultTextColor(Qt::black);
    text->setPos(0, 0);

    ui->graphicsView_2->setScene(scene);

    rootX = ui->graphicsView_2->width() / 2;
    rootY = 50;
    horizontalGap = 250;
    DrawTree(myTree.root.get(), rootX, rootY, horizontalGap, scene);

    myTree.bPlusTree ->convertToRedBlackTree();
    QString RBTree = myTree.bPlusTree -> rbTree ->printTree();

    connect(ui->BPlusButton, &QPushButton::clicked, this, &TreeWindow::OnBPlusButtonClicked);
    connect(ui->RBTreeButton, &QPushButton::clicked, this, &TreeWindow::OnRBTreeButtonClicked);
}

void TreeWindow::DrawTree(BSTree::TreeNode* node, int x, int y, int hGap, QGraphicsScene* scene) {
    if (!node) return;

    const int vGap = 60;
    const int radius = 20;

    if (node->left) {
        scene->addLine(x, y + radius, x - hGap, y + vGap - radius, QPen(Qt::black, 2));
        DrawTree(node->left.get(), x - hGap, y + vGap, hGap / 2, scene);
    }

    if (node->right) {
        scene->addLine(x, y + radius, x + hGap, y + vGap - radius, QPen(Qt::black, 2));
        DrawTree(node->right.get(), x + hGap, y + vGap, hGap / 2, scene);
    }

    QGraphicsEllipseItem* circle = scene->addEllipse(x - radius, y - radius, radius * 2, radius * 2, QPen(Qt::black, 2), QBrush(Qt::white));

    QGraphicsTextItem* text = scene->addText(QString::number(node->data), QFont("Arial", 10, QFont::Bold));
    text->setDefaultTextColor(Qt::black);
    text->setPos(x - text->boundingRect().width() / 2, y - text->boundingRect().height() / 2);
}

void TreeWindow::DrawBPlusTree(BPlusTree::Node* node, int x, int y, int hGap, QGraphicsScene* scene) {
    if (!node) return;

    const int vGap = 80;
    const int radius = 20;

    int width = node->keys.size() * 30;
    int height = 30;
    QGraphicsRectItem* rect = scene->addRect(x - width / 2, y, width, height, QPen(Qt::black, 2), QBrush(Qt::white));

    QString keysText;
    for (int key : node->keys) {
        keysText += QString::number(key) + " ";
    }
    QGraphicsTextItem* text = scene->addText(keysText.trimmed(), QFont("Arial", 10, QFont::Bold));
    text->setDefaultTextColor(Qt::black);
    text->setPos(x - text->boundingRect().width() / 2, y + (height - text->boundingRect().height()) / 2);

    if (!node->isLeaf) {
        int childX = x - (node->children.size() - 1) * hGap / 2;
        for (BPlusTree::Node* child : node->children) {
            scene->addLine(x, y + height, childX, y + vGap, QPen(Qt::black, 2));
            DrawBPlusTree(child, childX, y + vGap, hGap / 2, scene);
            childX += hGap;
        }
    }
}


void TreeWindow::OnBPlusButtonClicked() {
    QGraphicsScene* scene = new QGraphicsScene(this);

    QGraphicsTextItem* text = scene->addText("B+ дерево:", QFont("Arial", 10, QFont::Bold));
    text->setDefaultTextColor(Qt::black);
    text->setPos(0, 0);

    ui->graphicsView_2->setScene(scene);

    int rootX = ui->graphicsView_2->width() / 2;
    int rootY = 50;
    int horizontalGap = 250;
    DrawBPlusTree(myTree.bPlusTree->root, rootX, rootY, horizontalGap, scene);
}


void TreeWindow::OnRBTreeButtonClicked() {
    QGraphicsScene* scene = new QGraphicsScene(this);

    QGraphicsTextItem* text = scene->addText("Red-Black дерево:", QFont("Arial", 10, QFont::Bold));
    text->setDefaultTextColor(Qt::black);
    text->setPos(0, 0);

    ui->graphicsView->setScene(scene);

    int rootX = ui->graphicsView->width() / 2;
    int rootY = 50;
    int horizontalGap = 250;
    DrawRedBlackTree(myTree.bPlusTree -> rbTree->root, rootX, rootY, horizontalGap, scene);
}

void TreeWindow::DrawRedBlackTree(RedBlackTree::Node* node, int x, int y, int hGap, QGraphicsScene* scene) {
    if (!node) return;

    const int vGap = 80;
    const int radius = 20;

    if (node->left) {
        scene->addLine(x, y + radius, x - hGap, y + vGap - radius, QPen(Qt::black, 2));
        DrawRedBlackTree(node->left, x - hGap, y + vGap, hGap / 2, scene);
    }

    if (node->right) {
        scene->addLine(x, y + radius, x + hGap, y + vGap - radius, QPen(Qt::black, 2));
        DrawRedBlackTree(node->right, x + hGap, y + vGap, hGap / 2, scene);
    }

    QColor nodeColor = (node->color == RED) ? Qt::red : Qt::black;
    QGraphicsEllipseItem* circle = scene->addEllipse(x - radius, y - radius, radius * 2, radius * 2, QPen(nodeColor, 2), QBrush(Qt::white));

    QGraphicsTextItem* text = scene->addText(QString::number(node->data), QFont("Arial", 10, QFont::Bold));
    text->setDefaultTextColor(nodeColor);
    text->setPos(x - text->boundingRect().width() / 2, y - text->boundingRect().height() / 2);
}


int TreeWindow::CalculateInitialHGap(int treeHeight) {
    const int baseGap = 40;
    return (1 << (treeHeight - 1)) * baseGap;
}

int TreeWindow::GetTreeHeight(BSTree::TreeNode* node) {
    if (!node) return 0;
    return 1 + std::max(GetTreeHeight(node->left.get()), GetTreeHeight(node->right.get()));
}

TreeWindow::~TreeWindow()
{
    delete ui;
}
