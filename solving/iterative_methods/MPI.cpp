#include "MPI.h"

pair<vector<double>, int> MPI(const CSRMatrix &a_matrix, const vector<double> &x_0,
                              const vector<double> &b, const double &tolerance, const double &tau,
                              const string &file_path) {
    std::ofstream outfile;
    outfile.open(file_path, std::ofstream::out | std::ofstream::app);
    vector<double> x = x_0;
    vector<double> delta_solve = a_matrix * x - b;
    int number_iteration = 0;
    while (GiveVectorLength(delta_solve) >= tolerance) {
        x = x - tau * delta_solve;
        delta_solve = a_matrix * x - b;
        ++number_iteration;
        if (number_iteration % 10000 == 0) {
            outfile << log(GiveVectorLength(delta_solve)) << " " << number_iteration << "\n";
        }
    }
    outfile.close();
    return {x, number_iteration};
}
