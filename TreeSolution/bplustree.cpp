#include "bplustree.h"

void BPlusTree::splitChild(Node* parent, int index, Node* child) {
    Node* newChild = new Node(child->isLeaf);
    int mid = t - 1;

    newChild->keys.assign(child->keys.begin() + t, child->keys.end());
    child->keys.resize(mid);

    if (!child->isLeaf) {
        newChild->children.assign(child->children.begin() + t, child->children.end());
        child->children.resize(t);
    }

    parent->children.insert(parent->children.begin() + index + 1, newChild);
    parent->keys.insert(parent->keys.begin() + index, child->keys[mid]);
}


void BPlusTree::insertNonFull(Node* node, int key) {
    if (node->isLeaf) {
        node->keys.insert(std::upper_bound(node->keys.begin(), node->keys.end(), key), key);
    } else {
        int i = node->keys.size() - 1;
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        i++;

        if (node->children[i]->keys.size() == 2 * t - 1) {
            splitChild(node, i, node->children[i]);

            if (key > node->keys[i]) {
                i++;
            }
        }
        insertNonFull(node->children[i], key);
    }
}


void BPlusTree::printTree(Node* node, int level) {
    if (!node) return;

    qDebug().nospace() << QString(level * 2, ' ') << "Keys: ";

    for (int key : node->keys) {
        qDebug().nospace() << key << " ";
    }

    for (Node* child : node->children) {
        printTree(child, level + 1);
    }
}

void BPlusTree::PrintTree() {
    printTree(root, 0);
}

void BPlusTree::Insert(int key)
{
    if (root == nullptr) {
        root = new Node(true);
        root->keys.push_back(key);
    }
    else {
        if (root->keys.size() == 2 * t - 1) {
            Node* newRoot = new Node();
            newRoot->children.push_back(root);
            splitChild(newRoot, 0, root);
            root = newRoot;
        }
        insertNonFull(root, key);
    }
}

void BPlusTree::convertToRedBlackTree() {
    convertNodeToRedBlackTree(root);
}

void BPlusTree::convertNodeToRedBlackTree(Node* node) {
    if (node != nullptr) {
        for (int key : node->keys) {
            rbTree -> insert(key);
        }
        for (Node* child : node->children) {
            convertNodeToRedBlackTree(child);
        }
    }
}
