#include <cmath>
#include <fstream>
#include <string>

#include "../../solving/CSR_Matrix/csr_matrix.h"
#include "../../solving/iterative_methods/GZ.h"
#include "../../solving/iterative_methods/jacobi.h"
#include "../../solving/iterative_methods/MPI.h"

int main() {
    CSRMatrix matrix_a({{{0, 0}, 12},
                        {{0, 1}, 17},
                        {{0, 2}, 3},
                        {{1, 0}, 17},
                        {{1, 1}, 15825},
                        {{1, 2}, 28},
                        {{2, 0}, 3},
                        {{2, 1}, 28},
                        {{2, 2}, 238}},
                       3, 3);
    vector<double> b = {1, 2, 3};
    vector<double> x = {1, 1, 1};
    pair<vector<double>, int> mpi_solution__number_iteration =
        MPI(matrix_a, x, b, pow(10, -12), pow(10, -5),
            "/Users/dmitrystarukhin/slae_course/KR1/exercise4/MPI.txt");
    pair<vector<double>, int> jacobi_solution__number_iteration =
        Jacobi(matrix_a, x, b, pow(10, -12),
               "/Users/dmitrystarukhin/slae_course/KR1/exercise4/jacobi.txt");
    pair<vector<double>, int> gz_solution__number_iteration =
        GZ(matrix_a, x, b, pow(10, -12), "/Users/dmitrystarukhin/slae_course/KR1/exercise4/GZ.txt");
    return 0;
}