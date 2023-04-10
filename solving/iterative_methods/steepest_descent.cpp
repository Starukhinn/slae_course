#include "steepest_descent.h"

pair<vector<double>, int> SteepestDescentIteration(const CSRMatrix &matrix_a, const vector<double> &x0, const vector<double> &b, const double tolerance) {
    std::ofstream outfile;
    outfile.open("/Users/dmitrystarukhin/slae_course/GTest/KR2/2_task/steepest_descent.txt", std::ofstream::out | std::ofstream::app);
    vector<double> x = x0;
    vector<double> delta_solve = matrix_a * x - b;
    double alpha;
    int number_iterations = 0;
    outfile << delta_solve[0] << " " << delta_solve[1] << "\n";
    while (GiveVectorLength(delta_solve) > tolerance) {
        alpha = delta_solve * delta_solve / (delta_solve * (matrix_a * delta_solve));
        x = x - alpha * delta_solve;
        delta_solve = matrix_a * x - b;
        ++number_iterations;
        outfile << delta_solve[0] << " " << delta_solve[1] << "\n";
    }
    return {x, number_iterations};
}