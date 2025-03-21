#include "gauss_jacobi.hpp"
#include <iostream>
#include <vector>
#include <fstream>

// Function to Read Matrix from File
void readMatrixFromFile(const std::string &filename, std::vector<std::vector<double>> &A, std::vector<double> &B)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }

    int n;
    file >> n;

    A.resize(n, std::vector<double>(n));
    B.resize(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            file >> A[i][j];

    for (int i = 0; i < n; i++)
        file >> B[i];

    file.close();
}

// Main Function
int main()
{
    std::string filename = "matrix.txt";
    std::vector<std::vector<double>> A;
    std::vector<double> B;

    readMatrixFromFile(filename, A, B);

    double tolerance = 1e-6;
    int maxIterations = 100;

    GaussJacobi gj(A, B, tolerance, maxIterations);
    gj.solve();
    gj.displaySolution();

    return 0;
}
