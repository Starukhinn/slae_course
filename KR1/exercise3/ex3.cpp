#include <fstream>
#include <iomanip>

#include "../../solving/iterative_methods/MPI.h"

int main() {
    std::ofstream outfile;
    outfile.open("/Users/dmitrystarukhin/slae_course/KR1/exercise3/MPI3.txt",
                 std::ofstream::out | std::ofstream::app);
    CSRMatrix matrix_a(
        {{{0, 0}, 10.0}, {{0, 1}, 1.0}, {{1, 0}, 1.0}, {{1, 1}, 7.0}, {{2, 1}, 0.1}, {{2, 2}, 1.0}},
        3, 3);
    vector<double> b{20, 30, 1};
    vector<double> x{0, 0, 0};
    double tolerance = 1e-12;
    double tau = 1e-3;
    for (int number_search = 0; number_search < 100; number_search++) {
        int number_iterations =
            MPI(matrix_a, x, b, tolerance, tau,
                "/Users/dmitrystarukhin/slae_course/KR1/exercise3/MPI_information.txt")
                .second;
        outfile << number_iterations << " " << tau << '\n';
        tau += 1e-4;
    }
    return 0;
}