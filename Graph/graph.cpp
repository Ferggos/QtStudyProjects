#include "graph.h"
#include <random>

Graph::Graph() : a(SIZE, std::vector<int>(SIZE)), d(SIZE), v(SIZE), distMatrix(SIZE, std::vector<int>(SIZE)), next(SIZE, std::vector<int>(SIZE)){
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            a[i][j] = (i == j) ? 0 : INF;
        }
    }
}

int Graph::GetDebugInfo()
{
    return numOfIt;
}

void Graph::GetDijkstraDistances(int* distances)
{
    for (size_t i = 0; i < d.size(); ++i) distances[i] = d[i];
}
std::vector<std::vector<int>> Graph::GetFloydDistances()
{
    return distMatrix;
}

void Graph::InitMatrix(const std::vector<std::vector<int>>& matrix) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            a[i][j] = matrix[i][j];
        }
    }
}

void Graph::DijkstraAlgorithm(int start_node) {
    numOfIt = 0;
    int temp, minindex, min;
    begin_index = start_node - 1;
    for (int i = 0; i < SIZE; ++i) {
        d[i] = INF;
        v[i] = 1;
    }
    d[begin_index] = 0;

    do {
        minindex = min = INF;
        for (int i = 0; i < SIZE; ++i) {
            if (v[i] == 1 && d[i] < min) {
                minindex = i;
                min = d[i];
            }
        }

        if (minindex != INF) {
            for (int i = 0; i < SIZE; ++i) {
                if (a[minindex][i] > 0 && a[minindex][i] < INF) {
                    temp = min + a[minindex][i];
                    if (temp < d[i]) {
                        d[i] = temp;
                    }
                }
            }
            v[minindex] = 0;
        }
        numOfIt++;
    } while (minindex < INF);
}

void Graph::FloydWarshallAlgorithm() {
    numOfIt = 0;
    std::vector<std::vector<int>> dist = a;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (a[i][j] != INF && i != j) {
                next[i][j] = j;
            } else {
                next[i][j] = -1;
            }
        }
    }

    for (int k = 0; k < SIZE; ++k) {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
                numOfIt++;
            }
        }

    }

    this->distMatrix = dist;
}

int Graph::GetWayFloyd(int start, int end, int* path) {
    if (next[start][end] == -1) {
        return 0;
    }

    int pathLen = 0;
    path[pathLen++] = start + 1;

    while (start != end) {
        start = next[start][end];
        if (start == -1) {
            return 0;
        }
        path[pathLen++] = start + 1;
    }

    return pathLen;
}

int Graph::GetWay(int* arr, int end_index) {
    arr[0] = end_index + 1;
    int pathLen = 1;
    int weight = d[end_index];
    while (end_index != begin_index) {
        for (int i = 0; i < SIZE; ++i) {
            if (a[i][end_index] > 0) {
                int temp = weight - a[i][end_index];
                if (temp == d[i]) {
                    weight = temp;
                    end_index = i;
                    arr[pathLen] = i + 1;
                    pathLen++;
                }
            }
        }
    }
    return pathLen;
}

void Graph::generateRandomPermutation(std::vector<int>& permutation, int start) {
    permutation.clear();
    for (int i = 0; i < SIZE; i++) {
        if (i != start) permutation.push_back(i);
    }
    std::shuffle(permutation.begin(), permutation.end(), std::mt19937{std::random_device{}()});
}

void Graph::reconstructPath(int u, int v, std::vector<int>& path) {
    while (u != v) {
        u = next[u][v];
        path.push_back(u + 1);
    }
}

void Graph::findOptimizedPath(int start, std::vector<int>& bestPath, int& bestWeight) {
    FloydWarshallAlgorithm();

    bestWeight = std::numeric_limits<int>::max();
    bestPath.clear();

    std::vector<int> vertices;
    for (int i = 0; i < SIZE; i++) {
        if (i != start) {
            vertices.push_back(i);
        }
    }

    do {
        int currentWeight = 0;
        int currentVertex = start;
        std::vector<int> currentPath = {start + 1};
        bool validPath = true;

        for (int nextVertex : vertices) {
            if (next[currentVertex][nextVertex] == -1) {
                validPath = false;
                break;
            }

            currentWeight += distMatrix[currentVertex][nextVertex];
            reconstructPath(currentVertex, nextVertex, currentPath);
            currentVertex = nextVertex;
        }

        if (validPath && distMatrix[currentVertex][start] != INF) {
            currentWeight += distMatrix[currentVertex][start];
            reconstructPath(currentVertex, start, currentPath);

            if (currentWeight < bestWeight) {
                bestWeight = currentWeight;
                bestPath = currentPath;
            }
        }
    } while (std::next_permutation(vertices.begin(), vertices.end()));

    if (bestWeight == std::numeric_limits<int>::max()) {
        bestWeight = -1;
        bestPath.clear();
    }
}



