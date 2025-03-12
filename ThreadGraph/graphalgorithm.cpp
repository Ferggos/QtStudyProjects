#include "graphalgorithm.h"
#include <queue>
#include <climits>

GraphAlgorithm::GraphAlgorithm(QObject *parent)
    : QObject(parent), m_maxFlow(0), m_minCut("") {
    int initGraph[V][V] = {
        {0, 23, 0, 20, 0, 0, 0, 0, 0},
        {0, 0, 24, 0, 17, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 15, 0, 0, 0},
        {0, 22, 0, 0, 16, 0, 14, 18, 0},
        {0, 0, 0, 0, 0, 20, 0, 0, 14},
        {0, 0, 0, 0, 0, 0, 0, 0, 13},
        {0, 0, 0, 0, 0, 0, 0, 19, 0},
        {0, 0, 0, 0, 25, 0, 0, 0, 21},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    std::copy(&initGraph[0][0], &initGraph[0][0] + V * V, &graph[0][0]);
}

bool GraphAlgorithm::dfs(int rGraph[V][V], int source, int sink, int parent[]) {
    bool visited[V] = {false};
    std::vector<int> stack;
    stack.push_back(source);
    visited[source] = true;
    parent[source] = -1;

    while (!stack.empty()) {
        int u = stack.back();
        stack.pop_back();
        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                stack.push_back(v);
                parent[v] = u;
                visited[v] = true;
                if (v == sink) return true;
            }
        }
    }
    return false;
}

int GraphAlgorithm::fordFulkerson(int graph[V][V], int source, int sink) {
    std::copy(&graph[0][0], &graph[0][0] + V * V, &rGraph[0][0]);
    int parent[V];
    int maxFlow = 0;

    while (dfs(rGraph, source, sink, parent)) {
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = std::min(pathFlow, rGraph[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    bool visited[V] = {false};
    std::queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; v++) {
            if (rGraph[u][v] > 0 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    m_minCut.clear();
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (visited[u] && !visited[v] && graph[u][v]) {
                m_minCut += QString("Ребро %1 -> %2 с пропускной способностью: %3\n")
                                .arg(u + 1)
                                .arg(v + 1)
                                .arg(graph[u][v]);
            }
        }
    }

    m_maxFlow = maxFlow;
    emit maxFlowChanged();
    emit minCutChanged();
    return maxFlow;
}

QVariantList GraphAlgorithm::getMinCutEdges() const {
    std::vector<std::pair<int, int>> minCutEdges;
    bool visited[V] = {false};
    std::queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; v++) {
            if (rGraph[u][v] > 0 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (visited[u] && !visited[v] && graph[u][v]) {
                minCutEdges.emplace_back(u, v);
            }
        }
    }

    QVariantList result;
    for (const auto &edge : minCutEdges) {
        QVariantList edgePair;
        edgePair.append(edge.first);
        edgePair.append(edge.second);
        result.append(edgePair);
    }

    return result;
}


void GraphAlgorithm::calculateMaxFlow() {
    fordFulkerson(graph, 0, 8);
}
