#include <vector>
#include <memory>
#include <QString>
#include <QDebug>
#include "redblacktree.h"
using namespace std;

class BPlusTree {
public:
    BPlusTree(int degree): root(nullptr), t(degree){rbTree = make_unique<RedBlackTree>();}

    struct Node {
        bool isLeaf;
        vector<int> keys;
        vector<Node*> children;
        Node* next;

        Node(bool leaf = false)
            : isLeaf(leaf)
            , next(nullptr)
        {
        }
    };

    Node* root;

    unique_ptr<RedBlackTree> rbTree;

    void Insert(int key);
    void PrintTree();
    void convertToRedBlackTree();
private:

    int t = 5;

    void splitChild(Node* parent, int index, Node* child);

    void insertNonFull(Node* node, int key);

    void printTree(Node* node, int level);

    void convertNodeToRedBlackTree(Node* node);
};
