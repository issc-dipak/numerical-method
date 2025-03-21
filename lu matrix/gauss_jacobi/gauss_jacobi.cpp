#include "gauss_jacobi.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

// Constructor
GaussJacobi::GaussJacobi(std::vector<std::vector<double>> A, std::vector<double> B, double tol, int maxIter)
{
    this->A = A;
    this->B = B;
    this->tolerance = tol;
    this->maxIterations = maxIter;
    this->n = A.size();
    this->X.assign(n, 0.0);
    this->prevX.assign(n, 0.0);
}

// Gauss-Jacobi Iteration
void GaussJacobi::solve()
{
    int iter = 0;
    bool converged = false;

    while (iter < maxIterations && !converged)
    {
        converged = true;

        for (int i = 0; i < n; i++)
        {
            double sum = 0.0;
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    sum += A[i][j] * prevX[j];
                }
            }
            X[i] = (B[i] - sum) / A[i][i];

            if (std::fabs(X[i] - prevX[i]) > tolerance)
            {
                converged = false;
            }
        }

        prevX = X;
        iter++;
    }
}

// Display Solution
void GaussJacobi::displaySolution()
{
    std::cout << "Solution (Gauss-Jacobi Method):\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << "x" << i + 1 << " = " << std::setprecision(6) << X[i] << "\n";
    }
}
