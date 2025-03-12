#include <QObject>
#include <vector>

class HungarianAlgorithm : public QObject {
    Q_OBJECT
    Q_PROPERTY(QList<QList<double>> initialMatrix READ getInitialMatrix NOTIFY initialMatrixChanged)
    Q_PROPERTY(QList<QList<double>> resultMatrix READ getResultMatrix NOTIFY resultMatrixChanged)
    Q_PROPERTY(double totalCost READ getTotalCost NOTIFY totalCostChanged)

public:
    HungarianAlgorithm(std::vector<std::vector<double>> costMatrix, bool isMaximization);
    double solve();

    QList<QList<double>> getInitialMatrix() const;
    QList<QList<double>> getResultMatrix() const;
    double getTotalCost() const;

signals:
    void initialMatrixChanged();
    void resultMatrixChanged();
    void totalCostChanged();

private:
    void runHungarianAlgorithm();
    double calculateTotalCost();
    void printMatrix(const std::string& message, const std::vector<std::vector<double>>& matrix);
    void printResult();
    void updateMatrices();

    std::vector<std::vector<double>> initialMatrix;
    std::vector<std::vector<double>> costMatrix;
    std::vector<std::vector<double>> resultMatrix;
    int n;
    std::vector<bool> rowCover;
    std::vector<bool> colCover;
    std::vector<int> assignment;
    double totalCost;
    bool isMaximization;
};
