#include "lu_decomposition.hpp"
#include <iostream>
#include <iomanip>

// Constructor
LUDecomposition::LUDecomposition(std::vector<std::vector<double>> matrix)
{
    n = matrix.size();
    L = std::vector<std::vector<double>>(n, std::vector<double>(n, 0));
    U = matrix;
}

// Perform LU Decomposition
void LUDecomposition::decompose()
{
    for (int i = 0; i < n; i++)
    {
        L[i][i] = 1; // Set diagonal of L to 1
        for (int j = i + 1; j < n; j++)
        {
            double factor = U[j][i] / U[i][i];
            L[j][i] = factor;
            for (int k = i; k < n; k++)
            {
                U[j][k] -= factor * U[i][k];
            }
        }
    }
}

// Display L and U Matrices
void LUDecomposition::displayLU()
{
    std::cout << "L Matrix:\n";
    for (const auto &row : L)
    {
        for (double val : row)
        {
            std::cout << std::setw(10) << val << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nU Matrix:\n";
    for (const auto &row : U)
    {
        for (double val : row)
        {
            std::cout << std::setw(10) << val << " ";
        }
        std::cout << "\n";
    }
}

// Get L Matrix
std::vector<std::vector<double>> LUDecomposition::getL() const
{
    return L;
}

// Get U Matrix
std::vector<std::vector<double>> LUDecomposition::getU() const
{
    return U;
}
