#include "gaussian.hpp"
#include <iostream>

int main()
{
    try
    {
        std::string inputFile = "input.txt";
        GaussianElimination solver(inputFile);

        std::cout << "Initial system:";
        solver.printMatrix();

        solver.solve();

        std::cout << "\nAfter Gaussian elimination:";
        solver.printMatrix();

        solver.printSolution();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}