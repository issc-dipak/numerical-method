#include "lu_decomposition.hpp"
#include <iostream>
#include <vector>
#include <fstream>

// Function to Read Matrix from File
std::vector<std::vector<double>> readMatrixFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }

    int n;
    file >> n;

    std::vector<std::vector<double>> matrix(n, std::vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            file >> matrix[i][j];

    file.close();
    return matrix;
}

// Main Function
int main()
{
    std::string filename = "matrix.txt";
    std::vector<std::vector<double>> matrix = readMatrixFromFile(filename);

    LUDecomposition lu(matrix);
    lu.decompose();
    lu.displayLU();

    return 0;
}
