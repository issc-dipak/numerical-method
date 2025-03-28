#ifndef GAUSSIAN_HPP
#define GAUSSIAN_HPP

#include <vector>
#include <string>
#include <stdexcept>

class GaussianElimination
{
public:
    // Constructor that takes input file path
    GaussianElimination(const std::string &inputFile);

    // Perform Gaussian elimination with partial pivoting
    void solve();

    // Print the augmented matrix
    void printMatrix() const;

    // Print the solution vector
    void printSolution() const;

private:
    std::vector<std::vector<double>> augmentedMatrix;
    std::vector<double> solution;
    int n; // Number of equations/variables

    // Helper functions
    void readInput(const std::string &inputFile);
    void partialPivot(int k);
    void backSubstitution();
};

#endif // GAUSSIAN_HPP