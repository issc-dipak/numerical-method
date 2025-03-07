#include "gauss_elimination.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

GaussElimination::GaussElimination(vector<vector<double>> A, vector<double> b)
{
    this->A = A;
    this->b = b;
    this->n = A.size();
}

void GaussElimination::forwardElimination()
{
    for (int i = 0; i < n; i++)
    {
        // Partial Pivoting
        int maxRow = i;
        for (int k = i + 1; k < n; k++)
        {
            if (abs(A[k][i]) > abs(A[maxRow][i]))
            {
                maxRow = k;
            }
        }
        swap(A[i], A[maxRow]);
        swap(b[i], b[maxRow]);

        // Make elements below pivot 0
       for (int k = i + 1; k < n; k++)
        {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j < n; j++)
            {
                A[k][j] -= factor * A[i][j];
            }
        }
    }
}

vector<double> GaussElimination::backSubstitution()
{
    vector<double> x(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++)
        {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
    return x;
}

vector<double> GaussElimination::solve()
{
    forwardElimination();
    return backSubstitution();
}
