#ifndef GRAPHALGORITHM_H
#define GRAPHALGORITHM_H

#include <QObject>
#include <QVariant>
#include <vector>
#include <QString>

class GraphAlgorithm : public QObject {
    Q_OBJECT
    Q_PROPERTY(int maxFlow READ maxFlow NOTIFY maxFlowChanged)
    Q_PROPERTY(QString minCut READ minCut NOTIFY minCutChanged)

public:
    explicit GraphAlgorithm(QObject *parent = nullptr);

    Q_INVOKABLE void calculateMaxFlow();

    int maxFlow() const { return m_maxFlow; }
    QString minCut() const { return m_minCut; }
    Q_INVOKABLE QVariantList getMinCutEdges() const;

signals:
    void maxFlowChanged();
    void minCutChanged();

private:
    int m_maxFlow = 0;
    QString m_minCut;
    static const int V = 9;
    int graph[V][V];
    int rGraph[V][V];

    bool dfs(int rGraph[V][V], int source, int sink, int parent[]);
    int fordFulkerson(int graph[V][V], int source, int sink);
};

#endif
