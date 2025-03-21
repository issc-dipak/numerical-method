#ifndef LU_DECOMPOSITION_HPP
#define LU_DECOMPOSITION_HPP

#include <vector>

class LUDecomposition
{
public:
    LUDecomposition(std::vector<std::vector<double>> matrix);
    void decompose();
    void displayLU();
    std::vector<std::vector<double>> getL() const;
    std::vector<std::vector<double>> getU() const;

private:
    std::vector<std::vector<double>> L, U;
    int n;
};

#endif // LU_DECOMPOSITION_HPP
