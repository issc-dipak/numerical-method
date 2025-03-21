#include "gauss_jordan.hpp"
#include <iostream>
#include <iomanip>

// Constructor
GaussJordan::GaussJordan(std::vector<std::vector<double>> matrix)
{
    n = matrix.size();
    mat = matrix;
}

// Perform Gauss-Jordan Elimination
void GaussJordan::eliminate()
{
    for (int i = 0; i < n; i++)
    {
        // Make diagonal element 1
        double diag = mat[i][i];
        for (int j = 0; j < n; j++)
        {
            mat[i][j] /= diag;
        }

        // Make other column elements 0
        for (int k = 0; k < n; k++)
        {
            if (k != i)
            {
                double factor = mat[k][i];
                for (int j = 0; j < n; j++)
                {
                    mat[k][j] -= factor * mat[i][j];
                }
            }
        }
    }
}

// Display the Resulting Matrix
void GaussJordan::displayResult()
{
    std::cout << "Reduced Row Echelon Form:\n";
    for (const auto &row : mat)
    {
        for (double val : row)
        {
            std::cout << std::setw(10) << val << " ";
        }
        std::cout << "\n";
    }
}
