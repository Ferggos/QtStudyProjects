#ifndef TREEWINDOW_H
#define TREEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include "bstree.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class TreeWindow;
}
QT_END_NAMESPACE

class TreeWindow : public QMainWindow
{
    Q_OBJECT

public:
    TreeWindow(QWidget *parent = nullptr);
    ~TreeWindow();
    void DrawTree(BSTree::TreeNode* node, int x, int y, int hGap, QGraphicsScene* scene);
    int CalculateInitialHGap(int treeHeight);
    int GetTreeHeight(BSTree::TreeNode* node);
    void DrawBPlusTree(BPlusTree::Node* node, int x, int y, int hGap, QGraphicsScene* scene);
    void DrawRedBlackTree(RedBlackTree::Node* node, int x, int y, int hGap, QGraphicsScene* scene);

private slots:
    void OnBPlusButtonClicked();
    void OnRBTreeButtonClicked();
private:
    Ui::TreeWindow *ui;
    BSTree myTree;
};
#endif
