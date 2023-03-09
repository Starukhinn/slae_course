#include "MPI.h"
#include <iomanip>
#include <fstream>

vector<float> MPI(const CSRMatrix &a_matrix, const vector<float> &x_0, const vector<float> &b,
                  float tolerance, float tau) {
    std::ofstream outfile;
    outfile.open("/Users/dmitrystarukhin/slae_course/solving/iterative_methods/data_graphs/MPI.txt",
                 std::ofstream::out | std::ofstream::app);
    vector<float> x = x_0;
    vector<float> delta_solve = a_matrix * x - b;
    int number_iteration = 0;
    while (GiveVectorLength(delta_solve) >= tolerance) {
        x = x - tau * delta_solve;
        delta_solve = a_matrix * x - b;
        if (number_iteration % 10000 == 0) {
            outfile << log(GiveVectorLength(delta_solve)) << " " << number_iteration << "\n";
        }
        ++number_iteration;
    }
    outfile.close();
    return x;
}

