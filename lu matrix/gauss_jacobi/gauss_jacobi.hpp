#ifndef GAUSS_JACOBI_HPP
#define GAUSS_JACOBI_HPP

#include <vector>

class GaussJacobi
{
public:
    GaussJacobi(std::vector<std::vector<double>> A, std::vector<double> B, double tol, int maxIter);
    void solve();
    void displaySolution();

private:
    std::vector<std::vector<double>> A;
    std::vector<double> B, X, prevX;
    double tolerance;
    int maxIterations;
    int n;
};

#endif // GAUSS_JACOBI_HPP
