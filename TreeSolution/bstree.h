#ifndef BSTREE_H
#define BSTREE_H

#include <memory>
#include <vector>
#include <unordered_map>
#include <climits>
#include "bplustree.h"

#include <QString>
#include <QMap>


class BSTree {
public:
    BSTree() : root(nullptr), bPlusTree(nullptr) {}

    std::shared_ptr<BPlusTree> bPlusTree;

    void Insert(int val);
    QString PrintHierarchical();

    QString Print(int choose);
    int FindSumAndProd(int& prod);
    QString FindNodesWithUnequalLeftRightDescendants();
    QString FindNodesWithUnequalSubtreeHeights();
    int CountOccurrences(int x);
    int FindMaxElement();
    int CountMaxOccurrences(int maxVal);
    bool HasDuplicate();
    int FindMaxDuplicateCount();
    bool IsSymmetric();
    bool IsBinarySearchTree();
    QString GetLeavesInAscendingOrder();
    std::pair<BSTree, BSTree> CreateBalancedTreesFromPosNeg();
    QString FindMinWeightPaths();
    int FindLastLevelWithPositive();
    QString FindMaxAtEachLevel();
    QString CountInternalAndLeafNodes();
    int SumOddLevelElements();
    QString FindMinMaxLeafPaths();
    int RemoveNodesToMakeStrictBinaryTree();
    void ConvertToBPlusTree();

    struct TreeNode {
        TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}

        int data;
        std::unique_ptr<TreeNode> left;
        std::unique_ptr<TreeNode> right;


    };

    std::unique_ptr<TreeNode> root;

private:
    void PrefixPrint(std::unique_ptr<TreeNode>& node, QString& result);
    void InfixPrint(std::unique_ptr<TreeNode>& node, QString& result);
    void PostfixPrint(std::unique_ptr<TreeNode>& node, QString& result);
    void SubFindSumAndProduct(int& sum, int& prod, std::unique_ptr<TreeNode>& node);

    void Insert(int val, std::unique_ptr<TreeNode>& root);

    void printNodeHierarchical(std::unique_ptr<TreeNode>& node, int depth, QString& result);

    void CountDescendants(std::unique_ptr<TreeNode>& node, int& count);
    int GetDescendantCount(std::unique_ptr<TreeNode>& node);
    void FindNodesWithUnequalLeftRightDescendants(std::unique_ptr<TreeNode>& node, std::vector<int>& result);


    int GetHeight(std::unique_ptr<TreeNode>& node);
    void FindNodesWithUnequalSubtreeHeights(std::unique_ptr<TreeNode>& node, std::vector<int>& result);
    int CountOccurrences(int x, std::unique_ptr<TreeNode>& node);
    int FindMaxElement(std::unique_ptr<TreeNode>& node);
    int CountMaxOccurrences(std::unique_ptr<TreeNode>& node, int maxVal);
    bool HasDuplicate(std::unique_ptr<TreeNode>& node, std::unordered_map<int, int>& countMap);
    int FindMaxDuplicateCount(std::unique_ptr<TreeNode>& node, std::unordered_map<int, int>& countMap);
    bool IsSymmetric(std::unique_ptr<TreeNode>& leftNode, std::unique_ptr<TreeNode>& rightNode);
    bool IsBinarySearchTree(std::unique_ptr<TreeNode>& node, int min, int max);
    void GetLeavesInOrder(std::unique_ptr<TreeNode>& node, std::vector<int>& leaves);
    void CollectNodes(std::unique_ptr<TreeNode>& node, std::vector<int>& negatives, std::vector<int>& nonNegatives);
    std::unique_ptr<TreeNode> BuildBalancedTree(const std::vector<int>& elements, int start, int end);
    void FindMinWeightPaths(std::vector<int>& path, int currentSum, int& minSum, std::vector<std::vector<int>>& minPaths, std::unique_ptr<TreeNode>& node);
    void FindLastLevelWithPositive(std::vector<int>& result, int level, std::unique_ptr<TreeNode>& node);
    void FindMaxAtEachLevel(std::vector<int>& result, int level, std::unique_ptr<TreeNode>& node);
    void CountNodesPerLevel(int level, QMap<int, int>& internalNodes, QMap<int, int>& leafNodes, std::unique_ptr<TreeNode>& node);
    void SumOddLevelElements(int level, int& sum, std::unique_ptr<TreeNode>& node);
    void FindMinMaxLeafPaths(std::vector<int>& path, int currentSum, int& minSum, int& maxSum, std::vector<std::vector<int>>& minPaths, std::vector<std::vector<int>>& maxPaths, std::unique_ptr<TreeNode>& node);
    int RemoveNodesToMakeStrictBinaryTree(std::unique_ptr<TreeNode>& node);
    void InOrderTraversal(std::unique_ptr<TreeNode>& node, std::vector<int>& elements);
};

#endif // BSTREE_H
