#ifndef GAUSS_JORDAN_HPP
#define GAUSS_JORDAN_HPP

#include <vector>

class GaussJordan
{
public:
    GaussJordan(std::vector<std::vector<double>> matrix);
    void eliminate();
    void displayResult();

private:
    std::vector<std::vector<double>> mat;
    int n;
};

#endif // GAUSS_JORDAN_HPP
