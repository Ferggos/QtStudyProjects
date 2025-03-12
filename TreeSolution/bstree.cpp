// BSTree.cpp
#include "bstree.h"

void BSTree::Insert(int val) {
    if (root == nullptr) this->root = std::make_unique<TreeNode>(val);
    else this->Insert(val, root);
}

void BSTree::Insert(int val, std::unique_ptr<TreeNode>& root) {
    if (val < root->data) {
        if (root->left == nullptr)
            root->left = std::make_unique<TreeNode>(val);
        else
            this->Insert(val, root->left);
    } else {
        if (root->right == nullptr)
            root->right = std::make_unique<TreeNode>(val);
        else
            this->Insert(val, root->right);
    }
}

QString BSTree::PrintHierarchical() {
    QString result;
    printNodeHierarchical(root, 0, result);
    return result;
}

void BSTree::printNodeHierarchical(std::unique_ptr<TreeNode>& node, int depth, QString& result) {
    if (node == nullptr) {
        return;
    }

    printNodeHierarchical(node->right, depth + 1, result);

    result += QString("          ").repeated(depth) + QString::number(node->data) + "\n";

    printNodeHierarchical(node->left, depth + 1, result);
}


QString BSTree::Print(int choose) {
    QString result;
    if (this->root != nullptr){
        switch (choose){
        case 1:
            PrefixPrint(this->root, result);
            break;
        case 2:
            InfixPrint(this->root, result);
            break;
        case 3:
            PostfixPrint(this->root, result);
            break;
        }
    }
    return result;
}

void BSTree::PrefixPrint(std::unique_ptr<TreeNode>& node, QString& result) {
    if (node == nullptr) {
        return;
    }
    result += QString::number(node->data) + " ";
    PrefixPrint(node->left, result);
    PrefixPrint(node->right, result);
}

void BSTree::InfixPrint(std::unique_ptr<TreeNode>& node, QString& result) {
    if (node == nullptr) {
        return;
    }
    InfixPrint(node->left, result);
    result += QString::number(node->data) + " ";
    InfixPrint(node->right, result);
}

void BSTree::PostfixPrint(std::unique_ptr<TreeNode>& node, QString& result) {
    if (node == nullptr) {
        return;
    }
    PostfixPrint(node->left, result);
    PostfixPrint(node->right, result);
    result += QString::number(node->data) + " ";
}


int BSTree::FindSumAndProd(int& prod) {
    int sum = 0;
    if (this->root != nullptr)
        SubFindSumAndProduct(sum, prod, this->root);
    return sum;
}

void BSTree::SubFindSumAndProduct(int& sum, int& prod, std::unique_ptr<TreeNode>& node) {
    if (node != nullptr) {
        sum += node->data;
        if (node->data % 3 == 0 && node -> data != 0) prod *= node->data;
        SubFindSumAndProduct(sum, prod, node->left);
        SubFindSumAndProduct(sum, prod, node->right);
    }
}

void BSTree::CountDescendants(std::unique_ptr<TreeNode>& node, int& count) {
    if (node == nullptr) {
        return;
    }
    count++;
    CountDescendants(node->left, count);
    CountDescendants(node->right, count);
}

int BSTree::GetDescendantCount(std::unique_ptr<TreeNode>& node) {
    int count = 0;
    CountDescendants(node, count);
    return count - 1;
}

void BSTree::FindNodesWithUnequalLeftRightDescendants(std::unique_ptr<TreeNode>& node, std::vector<int>& result) {
    if (node != nullptr) {
        int leftCount = GetDescendantCount(node->left);
        int rightCount = GetDescendantCount(node->right);

        if (leftCount != rightCount) {
            result.push_back(node->data);
        }

        FindNodesWithUnequalLeftRightDescendants(node->left, result);
        FindNodesWithUnequalLeftRightDescendants(node->right, result);
    }
}

QString BSTree::FindNodesWithUnequalLeftRightDescendants() {
    std::vector<int> result;
    QString stringRes;
    FindNodesWithUnequalLeftRightDescendants(root, result);
    for (int val : result) {
        stringRes += QString::number(val) + " ";
    }
    return stringRes;
}




int BSTree::GetHeight(std::unique_ptr<TreeNode>& node) {
    if (node == nullptr) {
        return 0;
    }
    int leftHeight = GetHeight(node->left);
    int rightHeight = GetHeight(node->right);
    return 1 + std::max(leftHeight, rightHeight);
}

void BSTree::FindNodesWithUnequalSubtreeHeights(std::unique_ptr<TreeNode>& node, std::vector<int>& result) {
    if (node != nullptr) {
        int leftHeight = GetHeight(node->left);
        int rightHeight = GetHeight(node->right);
        if (leftHeight != rightHeight) {
            result.push_back(node->data);
        }
        FindNodesWithUnequalSubtreeHeights(node->left, result);
        FindNodesWithUnequalSubtreeHeights(node->right, result);
    }
}

QString BSTree::FindNodesWithUnequalSubtreeHeights() {
    std::vector<int> result;
    QString stringRes;
    FindNodesWithUnequalSubtreeHeights(root, result);
    for (int val : result) {
        stringRes += QString::number(val) + " ";
    }
    return stringRes;
}


int BSTree::CountOccurrences(int x) {
    return CountOccurrences(x, root);
}

int BSTree::CountOccurrences(int x, std::unique_ptr<TreeNode>& node) {
    if (node == nullptr) {
        return 0;
    }
    int count = (node->data == x) ? 1 : 0;
    return count + CountOccurrences(x, node->left) + CountOccurrences(x, node->right);
}

int BSTree::FindMaxElement() {
    return FindMaxElement(root);
}

int BSTree::FindMaxElement(std::unique_ptr<TreeNode>& node) {
    if (node == nullptr) {
        throw std::runtime_error("Tree is empty");
    }
    int maxVal = node->data;
    if (node->right != nullptr) {
        maxVal = std::max(maxVal, FindMaxElement(node->right));
    }
    return maxVal;
}

int BSTree::CountMaxOccurrences(int maxVal) {
    return CountMaxOccurrences(root, maxVal);
}

int BSTree::CountMaxOccurrences(std::unique_ptr<TreeNode>& node, int maxVal) {
    if (node == nullptr) {
        return 0;
    }
    int count = (node->data == maxVal) ? 1 : 0;
    return count + CountMaxOccurrences(node->left, maxVal) + CountMaxOccurrences(node->right, maxVal);
}

bool BSTree::HasDuplicate() {
    std::unordered_map<int, int> countMap;
    return HasDuplicate(root, countMap);
}

bool BSTree::HasDuplicate(std::unique_ptr<TreeNode>& node, std::unordered_map<int, int>& countMap) {
    if (node == nullptr) {
        return false;
    }
    countMap[node->data]++;
    if (countMap[node->data] > 1) {
        return true;
    }
    return HasDuplicate(node->left, countMap) || HasDuplicate(node->right, countMap);
}

int BSTree::FindMaxDuplicateCount() {
    std::unordered_map<int, int> countMap;
    return FindMaxDuplicateCount(root, countMap);
}

int BSTree::FindMaxDuplicateCount(std::unique_ptr<TreeNode>& node, std::unordered_map<int, int>& countMap) {
    if (node == nullptr) {
        return 0;
    }
    countMap[node->data]++;
    int leftMax = FindMaxDuplicateCount(node->left, countMap);
    int rightMax = FindMaxDuplicateCount(node->right, countMap);

    return std::max({leftMax, rightMax, countMap[node->data]});
}

bool BSTree::IsSymmetric(std::unique_ptr<TreeNode>& leftNode, std::unique_ptr<TreeNode>& rightNode) {
    if (!leftNode && !rightNode) return true;
    if (!leftNode || !rightNode) return false;
    return (leftNode->data == rightNode->data) &&
           IsSymmetric(leftNode->left, rightNode->right) &&
           IsSymmetric(leftNode->right, rightNode->left);
}

bool BSTree::IsSymmetric() {
    if (!root) return true;
    return IsSymmetric(root->left, root->right);
}

bool BSTree::IsBinarySearchTree(std::unique_ptr<TreeNode>& node, int min, int max) {
    if (!node) return true;
    if (node->data <= min || node->data >= max) return false;
    return IsBinarySearchTree(node->left, min, node->data) &&
           IsBinarySearchTree(node->right, node->data, max);
}

bool BSTree::IsBinarySearchTree() {
    return IsBinarySearchTree(root, INT_MIN, INT_MAX);
}

void BSTree::GetLeavesInOrder(std::unique_ptr<TreeNode>& node, std::vector<int>& leaves) {
    if (node != nullptr) {
        if (!node->left && !node->right) {
            leaves.push_back(node->data);
        }
        GetLeavesInOrder(node->left, leaves);
        GetLeavesInOrder(node->right, leaves);
    }
}

QString BSTree::GetLeavesInAscendingOrder() {
    std::vector<int> leaves;
    QString result;
    GetLeavesInOrder(root, leaves);
    std::sort(leaves.begin(), leaves.end());
    for (int val : leaves)
        result += QString::number(val) + " ";
    return result;
}

void BSTree::CollectNodes(std::unique_ptr<TreeNode>& node, std::vector<int>& negatives, std::vector<int>& nonNegatives) {
    if (node != nullptr) {
        if (node->data < 0) {
            negatives.push_back(node->data);
        } else {
            nonNegatives.push_back(node->data);
        }
        CollectNodes(node->left, negatives, nonNegatives);
        CollectNodes(node->right, negatives, nonNegatives);
    }
}

std::unique_ptr<BSTree::TreeNode> BSTree::BuildBalancedTree(const std::vector<int>& elements, int start, int end) {
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    auto node = std::make_unique<TreeNode>(elements[mid]);
    node->left = BuildBalancedTree(elements, start, mid - 1);
    node->right = BuildBalancedTree(elements, mid + 1, end);
    return node;
}

std::pair<BSTree, BSTree> BSTree::CreateBalancedTreesFromPosNeg() {
    std::vector<int> negatives, nonNegatives;
    CollectNodes(root, negatives, nonNegatives);

    std::sort(negatives.begin(), negatives.end());
    std::sort(nonNegatives.begin(), nonNegatives.end());

    BSTree negativeTree, nonNegativeTree;
    negativeTree.root = BuildBalancedTree(negatives, 0, negatives.size() - 1);
    nonNegativeTree.root = BuildBalancedTree(nonNegatives, 0, nonNegatives.size() - 1);

    return std::make_pair(std::move(negativeTree), std::move(nonNegativeTree));
}

void BSTree::FindMinWeightPaths(std::vector<int>& path, int currentSum, int& minSum, std::vector<std::vector<int>>& minPaths, std::unique_ptr<TreeNode>& node) {
    if (!node) return;

    path.push_back(node->data);
    currentSum += node->data;

    if (!node->left && !node->right) {
        if (currentSum < minSum) {
            minSum = currentSum;
            minPaths.clear();
            minPaths.push_back(path);
        } else if (currentSum == minSum) {
            minPaths.push_back(path);
        }
    }

    FindMinWeightPaths(path, currentSum, minSum, minPaths, node->left);
    FindMinWeightPaths(path, currentSum, minSum, minPaths, node->right);

    path.pop_back();
}

QString BSTree::FindMinWeightPaths() {
    std::vector<int> path;
    int minSum = INT_MAX;
    QString result;
    std::vector<std::vector<int>> minPaths;
    FindMinWeightPaths(path, 0, minSum, minPaths, root);

    for (const auto& p : minPaths) {
        for (int val : p) {
            result += QString::number(val) + " ";
        }
        result += "\n";
    }
    return result;
}

void BSTree::FindLastLevelWithPositive(std::vector<int>& result, int level, std::unique_ptr<TreeNode>& node) {
    if (!node) return;
    if (node->data > 0) result.push_back(level);
    FindLastLevelWithPositive(result, level + 1, node->left);
    FindLastLevelWithPositive(result, level + 1, node->right);
}

int BSTree::FindLastLevelWithPositive() {
    std::vector<int> levels;
    FindLastLevelWithPositive(levels, 1, root);
    return levels.empty() ? -1 : levels.back();
}

void BSTree::FindMaxAtEachLevel(std::vector<int>& result, int level, std::unique_ptr<TreeNode>& node) {
    if (!node) return;
    if (result.size() < level) result.push_back(node->data);
    else result[level - 1] = std::max(result[level - 1], node->data);
    FindMaxAtEachLevel(result, level + 1, node->left);
    FindMaxAtEachLevel(result, level + 1, node->right);
}

QString BSTree::FindMaxAtEachLevel() {
    std::vector<int> result;
    QString resultStr;
    FindMaxAtEachLevel(result, 1, root);
    for (int val : result) {
        resultStr += QString::number(val) + " ";
    }
    return resultStr;
}

void BSTree::CountNodesPerLevel(int level, QMap<int, int>& internalNodes, QMap<int, int>& leafNodes, std::unique_ptr<TreeNode>& node) {
    if (!node) return;

    if (!internalNodes.contains(level)) internalNodes[level] = 0;
    if (!leafNodes.contains(level)) leafNodes[level] = 0;

    if (node->left || node->right) {
        internalNodes[level]++;
    } else {
        leafNodes[level]++;
    }

    CountNodesPerLevel(level + 1, internalNodes, leafNodes, node->left);
    CountNodesPerLevel(level + 1, internalNodes, leafNodes, node->right);
}


QString BSTree::CountInternalAndLeafNodes() {
    QMap<int, int> internalNodes;
    QMap<int, int> leafNodes;

    CountNodesPerLevel(1, internalNodes, leafNodes, root);

    QString result = "Распределение узлов по уровням:\n";
    for (int level : internalNodes.keys()) {
        result += "Уровень " + QString::number(level) + ": ";
        result += "Внутренние узлы: " + QString::number(internalNodes[level]) + ", ";
        result += "Листья: " + QString::number(leafNodes[level]) + "\n";
    }

    for (int level : leafNodes.keys()) {
        if (!internalNodes.contains(level)) {
            result += "Уровень " + QString::number(level) + ": ";
            result += "Внутренние узлы: 0, ";
            result += "Листья: " + QString::number(leafNodes[level]) + "\n";
        }
    }

    return result;
}


void BSTree::SumOddLevelElements(int level, int& sum, std::unique_ptr<TreeNode>& node) {
    if (!node) return;
    if (level % 2 != 0) sum += node->data;
    SumOddLevelElements(level + 1, sum, node->left);
    SumOddLevelElements(level + 1, sum, node->right);
}

int BSTree::SumOddLevelElements() {
    int sum = 0;
    SumOddLevelElements(1, sum, root);
    return sum;
}

void BSTree::FindMinMaxLeafPaths(std::vector<int>& path, int currentSum, int& minSum, int& maxSum, std::vector<std::vector<int>>& minPaths, std::vector<std::vector<int>>& maxPaths, std::unique_ptr<TreeNode>& node) {
    if (!node) return;

    path.push_back(node->data);
    currentSum += node->data;

    if (!node->left && !node->right) {
        if (currentSum < minSum) {
            minSum = currentSum;
            minPaths.clear();
            minPaths.push_back(path);
        } else if (currentSum == minSum) {
            minPaths.push_back(path);
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxPaths.clear();
            maxPaths.push_back(path);
        } else if (currentSum == maxSum) {
            maxPaths.push_back(path);
        }
    }

    FindMinMaxLeafPaths(path, currentSum, minSum, maxSum, minPaths, maxPaths, node->left);
    FindMinMaxLeafPaths(path, currentSum, minSum, maxSum, minPaths, maxPaths, node->right);

    path.pop_back();
}

QString BSTree::FindMinMaxLeafPaths() {
    std::vector<int> path;
    int minSum = INT_MAX, maxSum = INT_MIN;
    std::vector<std::vector<int>> minPaths, maxPaths;
    FindMinMaxLeafPaths(path, 0, minSum, maxSum, minPaths, maxPaths, root);

    QString result;

    result += "Минимальный путь(и):\n";
    for (const auto& p : minPaths) {
        for (int val : p) {
            result += QString::number(val) + " ";
        }
        result += "\n";
    }

    result += "Максимальный путь(и):\n";
    for (const auto& p : maxPaths) {
        for (int val : p) {
            result += QString::number(val) + " ";
        }
        result += "\n";
    }
    return result;
}

int BSTree::RemoveNodesToMakeStrictBinaryTree() {
    return RemoveNodesToMakeStrictBinaryTree(root);
}

int BSTree::RemoveNodesToMakeStrictBinaryTree(std::unique_ptr<TreeNode>& node) {
    if (!node) return 0;

    int leftRemovals = RemoveNodesToMakeStrictBinaryTree(node->left);
    int rightRemovals = RemoveNodesToMakeStrictBinaryTree(node->right);

    if (node->left && !node->right) {
        node = std::move(node->left);
        return leftRemovals + 1;
    } else if (!node->left && node->right) {
        node = std::move(node->right);
        return rightRemovals + 1;
    }

    return leftRemovals + rightRemovals;
}

void BSTree::ConvertToBPlusTree() {
    if (this->root == nullptr) {
        std::cerr << "Ошибка: Дерево пустое, невозможно преобразовать." << std::endl;
        return;
    }

    std::vector<int> elements;
    InOrderTraversal(this->root, elements);

    bPlusTree = std::make_shared<BPlusTree>(5);
    for (int elem : elements) {
        bPlusTree->Insert(elem);
    }
}


void BSTree::InOrderTraversal(std::unique_ptr<TreeNode>& node, std::vector<int>& elements) {
    if (node == nullptr) return;

    InOrderTraversal(node->left, elements);
    elements.push_back(node->data);
    InOrderTraversal(node->right, elements);
}





