#include "gauss_elimination.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile)
    {
        cerr << "Error: Cannot open input.txt" << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);

    // Read matrix from file
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inputFile >> A[i][j];
        }
        inputFile >> b[i];
    }
    inputFile.close();

    // Solve using Gauss Elimination
    GaussElimination solver(A, b);
    vector<double> solution = solver.solve();

    // Print the solution
    cout << "Solution:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i + 1 << "] = " << solution[i] << endl;
    }

    return 0;
}
