#ifndef GRAPH_H
#define GRAPH_H

#define SIZE 8
#define INF 1e9
#include <vector>

class Graph{
public:
    Graph();
    void InitMatrix(const std::vector<std::vector<int>>& matrix);
    void DijkstraAlgorithm(int start_node);
    void FloydWarshallAlgorithm();
    int GetWay(int* arr, int end_index);
    int GetWayFloyd(int start, int end, int* path);
    void PrintDistances();
    int GetDebugInfo();
    int FindShortestCycle(int start, std::vector<int>& best_path);
    void GetDijkstraDistances(int* distances);
    std::vector<std::vector<int>> GetFloydDistances ();
    void reconstructPath(int u, int v, std::vector<int>& path);
    void findOptimizedPath(int start, std::vector<int>& bestPath, int& bestWeight);
    void generateRandomPermutation(std::vector<int>& permutation, int start);
    void findBestPath(int start, std::vector<int>& vertex, std::vector<std::vector<int>> dist,
                      std::vector<int>& current_path, int& min_path, int current_weight,
                      std::vector<int>& best_path, int current_vertex, std::vector<bool>& visited);
    void initializeAndFindBestPath(int start, std::vector<int>& bestPath, int& bestWeight);




private:
    std::vector<std::vector<int>> a;                // Матрица смежности
    std::vector<int> d;                            // Массив расстояний для Дейкстры
    std::vector<bool> v;                          // Вектор посещенных вершин (для Дейкстры)
    std::vector<std::vector<int>> distMatrix;    // Матрица расстояний для Флойда-Уоршелла
    std::vector<std::vector<int>> next;        // Матрица для восстановления пути в алгоритме Флойда-Уоршелла
    int begin_index;                           // Стартовый узел
    int numOfIt;
};

#endif
