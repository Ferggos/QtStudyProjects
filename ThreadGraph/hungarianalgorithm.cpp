#include "hungarianalgorithm.h"
#include <iostream>
#include <limits>
#include <vector>

HungarianAlgorithm::HungarianAlgorithm(std::vector<std::vector<double>> _costMatrix, bool isMaximization)
    : costMatrix(_costMatrix), n(_costMatrix.size()), rowCover(n, false), colCover(n, false), assignment(n, -1), totalCost(0), isMaximization(isMaximization) {

    initialMatrix = costMatrix;
    if (isMaximization) {
        double maxElement = std::numeric_limits<double>::min();

        for (const auto& row : costMatrix) {
            maxElement = std::max(maxElement, *std::max_element(row.begin(), row.end()));
        }

        for (auto& row : costMatrix) {
            for (auto& element : row) {
                element = maxElement - element;
            }
        }
    }

    std::cout << "Инициализация завершена, размер: " << n << std::endl;
    printMatrix("Начальная матрица затрат:", costMatrix);
    updateMatrices();
}

double HungarianAlgorithm::solve() {
    runHungarianAlgorithm();
    totalCost = calculateTotalCost();
    emit totalCostChanged();
    return totalCost;
}

void HungarianAlgorithm::runHungarianAlgorithm() {
    std::vector<int> u(n + 1), v(n + 1), p(n + 1), way(n + 1);
    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        std::vector<int> minv(n + 1, std::numeric_limits<int>::max());
        std::vector<char> used(n + 1, false);
        do {
            used[j0] = true;
            int i0 = p[j0], delta = std::numeric_limits<int>::max(), j1;
            for (int j = 1; j <= n; ++j) {
                if (!used[j]) {
                    int cur = costMatrix[i0 - 1][j - 1] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for (int j = 0; j <= n; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            std::cout << "Промежуточные значения delta: " << delta << std::endl;
            std::cout << "Обновленные значения u: ";
            for (int k = 1; k <= n; ++k) {
                std::cout << u[k] << " ";
            }
            std::cout << "\nОбновленные значения v: ";
            for (int k = 1; k <= n; ++k) {
                std::cout << v[k] << " ";
            }
            std::cout << std::endl;


            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }

    for (int j = 1; j <= n; ++j) {
        assignment[p[j] - 1] = j - 1;
    }
    printResult();
    updateMatrices();
}


double HungarianAlgorithm::calculateTotalCost() {
    double totalCost = 0;
    if (!isMaximization){
        for (int i = 0; i < n; ++i) {
            if (assignment[i] != -1) {
                totalCost += costMatrix[i][assignment[i]];
            }
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            if (assignment[i] != -1) {
                totalCost += initialMatrix[i][assignment[i]];
            }
        }
    }

    return totalCost;
}

void HungarianAlgorithm::printMatrix(const std::string& message, const std::vector<std::vector<double>>& matrix) {
    std::cout << message << std::endl;
    for (const auto& row : matrix) {
        for (double value : row) {
            std::cout << value << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void HungarianAlgorithm::printResult() {
    resultMatrix.assign(n, std::vector<double>(n, 0));
    for (int i = 0; i < n; ++i) {
        if (assignment[i] != -1) {
            resultMatrix[i][assignment[i]] = initialMatrix[i][assignment[i]];
        }
    }
    printMatrix("Результирующая матрица назначений:", resultMatrix);
}

void HungarianAlgorithm::updateMatrices() {
    emit initialMatrixChanged();
    emit resultMatrixChanged();
}

QList<QList<double>> HungarianAlgorithm::getInitialMatrix() const {
    QList<QList<double>> matrix;
    for (const auto& row : costMatrix) {
        QList<double> qRow;
        for (double val : row) {
            qRow.append(val);
        }
        matrix.append(qRow);
    }
    return matrix;
}

QList<QList<double>> HungarianAlgorithm::getResultMatrix() const {
    QList<QList<double>> matrix;
    for (const auto& row : resultMatrix) {
        QList<double> qRow;
        for (double val : row) {
            qRow.append(val);
        }
        matrix.append(qRow);
    }
    return matrix;
}

double HungarianAlgorithm::getTotalCost() const {
    return totalCost;
}
