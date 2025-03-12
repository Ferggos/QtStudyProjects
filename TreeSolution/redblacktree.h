#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <string>
#include <QString>
using namespace std;

enum Color { RED, BLACK };

class RedBlackTree {
public:

    RedBlackTree();

    void insert(int key);
    QString printTree();

    struct Node {
        int data;
        Color color;
        Node* parent;
        Node* left;
        Node* right;

        Node(int value)
            : data(value), color(RED), parent(nullptr), left(nullptr), right(nullptr) {}
    };

    Node* root;

private:
    void rotateLeft(Node*& node);
    void rotateRight(Node*& node);
    void fixInsert(Node*& node);
    void printHelper(Node* root, std::string indent, bool last, QString& result);

};

#endif
