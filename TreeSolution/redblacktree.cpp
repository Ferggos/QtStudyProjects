#include "redblacktree.h"

RedBlackTree::RedBlackTree() : root(nullptr) {}

void RedBlackTree::rotateLeft(Node*& node) {
    Node* child = node->right;
    node->right = child->left;
    if (node->right != nullptr)
        node->right->parent = node;
    child->parent = node->parent;
    if (node->parent == nullptr)
        root = child;
    else if (node == node->parent->left)
        node->parent->left = child;
    else
        node->parent->right = child;
    child->left = node;
    node->parent = child;
}

void RedBlackTree::rotateRight(Node*& node) {
    Node* child = node->left;
    node->left = child->right;
    if (node->left != nullptr)
        node->left->parent = node;
    child->parent = node->parent;
    if (node->parent == nullptr)
        root = child;
    else if (node == node->parent->right)
        node->parent->right = child;
    else
        node->parent->left = child;
    child->right = node;
    node->parent = child;
}

void RedBlackTree::fixInsert(Node*& node) {
    Node* parent = nullptr;
    Node* grandparent = nullptr;
    while (node != root && node->color == RED && node->parent->color == RED) {
        parent = node->parent;
        grandparent = parent->parent;
        if (parent == grandparent->left) {
            Node* uncle = grandparent->right;
            if (uncle != nullptr && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                if (node == parent->right) {
                    rotateLeft(parent);
                    node = parent;
                    parent = node->parent;
                }
                rotateRight(grandparent);
                swap(parent->color, grandparent->color);
                node = parent;
            }
        } else {
            Node* uncle = grandparent->left;
            if (uncle != nullptr && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                if (node == parent->left) {
                    rotateRight(parent);
                    node = parent;
                    parent = node->parent;
                }
                rotateLeft(grandparent);
                swap(parent->color, grandparent->color);
                node = parent;
            }
        }
    }
    root->color = BLACK;
}

void RedBlackTree::insert(int key) {
    Node* node = new Node(key);
    Node* parent = nullptr;
    Node* current = root;
    while (current != nullptr) {
        parent = current;
        if (node->data < current->data)
            current = current->left;
        else
            current = current->right;
    }
    node->parent = parent;
    if (parent == nullptr)
        root = node;
    else if (node->data < parent->data)
        parent->left = node;
    else
        parent->right = node;
    fixInsert(node);
}

QString RedBlackTree::printTree() {
    QString result;
    if (root == nullptr)
        result += "Tree is empty.\n";
    else {
        result +=  "Красно-Чёрное дерево: \n";
        printHelper(root, "", true, result);
    }
    return result;
}

void RedBlackTree::printHelper(Node* root, std::string indent, bool last, QString& result) {
    if (root != nullptr) {
        result += indent;
        if (last) {
            result += "R----";
            indent += "   ";
        }
        else {
            result += "L----";
            indent += "|  ";
        }
        std::string sColor = (root->color == RED) ? "RED" : "BLACK";
        result +=  QString::number(root->data) + "(" + QString::fromStdString(sColor) + ")\n";
        printHelper(root->left, indent, false, result);
        printHelper(root->right, indent, true, result);
    }
}
