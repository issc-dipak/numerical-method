#include "gaussian.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>

GaussianElimination::GaussianElimination(const std::string &inputFile)
{
    readInput(inputFile);
}

void GaussianElimination::readInput(const std::string &inputFile)
{
    std::ifstream inFile(inputFile);
    if (!inFile)
    {
        throw std::runtime_error("Error opening input file.");
    }

    inFile >> n;
    augmentedMatrix.resize(n, std::vector<double>(n + 1));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            inFile >> augmentedMatrix[i][j];
        }
    }

    inFile.close();
}

void GaussianElimination::partialPivot(int k)
{
    int maxRow = k;
    double maxVal = std::abs(augmentedMatrix[k][k]);

    for (int i = k + 1; i < n; ++i)
    {
        if (std::abs(augmentedMatrix[i][k]) > maxVal)
        {
            maxVal = std::abs(augmentedMatrix[i][k]);
            maxRow = i;
        }
    }

    if (maxRow != k)
    {
        std::swap(augmentedMatrix[k], augmentedMatrix[maxRow]);
    }
}

void GaussianElimination::backSubstitution()
{
    solution.resize(n);
    for (int i = n - 1; i >= 0; --i)
    {
        solution[i] = augmentedMatrix[i][n];
        for (int j = i + 1; j < n; ++j)
        {
            solution[i] -= augmentedMatrix[i][j] * solution[j];
        }
        solution[i] /= augmentedMatrix[i][i];
    }
}

void GaussianElimination::solve()
{
    // Forward elimination with partial pivoting
    for (int k = 0; k < n - 1; ++k)
    {
        partialPivot(k);

        if (std::abs(augmentedMatrix[k][k]) < 1e-10)
        {
            throw std::runtime_error("Matrix is singular or nearly singular.");
        }

        for (int i = k + 1; i < n; ++i)
        {
            double factor = augmentedMatrix[i][k] / augmentedMatrix[k][k];
            for (int j = k; j <= n; ++j)
            {
                augmentedMatrix[i][j] -= factor * augmentedMatrix[k][j];
            }
        }
    }

    // Check if the system has a unique solution
    if (std::abs(augmentedMatrix[n - 1][n - 1]) < 1e-10)
    {
        throw std::runtime_error("Matrix is singular or nearly singular.");
    }

    // Back substitution
    backSubstitution();
}

void GaussianElimination::printMatrix() const
{
    std::cout << "\nAugmented Matrix:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            std::cout << std::setw(10) << std::setprecision(4) << augmentedMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void GaussianElimination::printSolution() const
{
    std::cout << "\nSolution:\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << "x[" << i << "] = " << std::setprecision(8) << solution[i] << "\n";
    }
}