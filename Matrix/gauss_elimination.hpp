#ifndef GAUSS_ELIMINATION_HPP
#define GAUSS_ELIMINATION_HPP

#include <vector>

using namespace std;

class GaussElimination
{
public:
    GaussElimination(vector<vector<double>> A, vector<double> b);
    vector<double> solve();

private:
    int n;
    vector<vector<double>> A;
    vector<double> b;

    void forwardElimination();
    vector<double> backSubstitution();
};

#endif
