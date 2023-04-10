#include "MPI.h"


pair<vector<double>, int> MPI(const CSRMatrix &a_matrix, const vector<double> &x_0,
                              const vector<double> &b, const double &tolerance, const double &tau,
                              const string &file_path) {
    std::ofstream outfile;
    outfile.open(file_path, std::ofstream::out | std::ofstream::app);
    vector<double> x = x_0;
    vector<double> delta_solve = a_matrix * x - b;
    int number_iteration = 0;
    outfile << delta_solve[0] << " " << delta_solve[1] << "\n";
    while (GiveVectorLength(delta_solve) >= tolerance) {
        x = x - tau * delta_solve;
        delta_solve = a_matrix * x - b;
        ++number_iteration;
        outfile << delta_solve[0] << " " << delta_solve[1] << "\n";
    }
    outfile.close();
    return {x, number_iteration};
}
