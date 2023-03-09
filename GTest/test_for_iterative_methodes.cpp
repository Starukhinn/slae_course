#include "gtest/gtest.h"
#include "../solving/CSR_Matrix/csr_matrix.h"
#include "../solving/Vector/vector_matrix.h"
#include "../solving/iterative_methods/MPI.h"
#include "../solving/iterative_methods/GZ.h"
#include "../solving/iterative_methods/jacobi.cpp"

TEST(ITTERATIONS, GAUS_ZEIDEL) {
    CSRMatrix matrix_a({
        {{0,0}, 16.0},
        {{0,1}, 3.0},
        {{1,0}, 7.0},
        {{1, 1}, -11.0}
                       },
                       2, 2);
    vector<float> b{11.0, 13.0};
    vector<float> x{1.0, 1.0};
    float tolerance = 1e-7;
    vector<float> result = GZ(matrix_a, x, b, tolerance);
    vector<float> delta_solve = matrix_a * result - b;
    for (int i = 0; i < 2; i++) {
        ASSERT_NEAR(delta_solve[i], 0, 1e-3);
    }
}

TEST(ITTERATIONS, JACOBI) {
    CSRMatrix matrix_a({
                           {{0,0}, 16.0},
                           {{0,1}, 3.0},
                           {{1,0}, 7.0},
                           {{1, 1}, -11.0}
                       },
                       2, 2);
    vector<float> b{11.0, 13.0};
    vector<float> x{1.0, 1.0};
    float tolerance = 1e-7;
    vector<float> result = Jacobi(matrix_a, x, b, tolerance);
    vector<float> delta_solve = matrix_a * result - b;
    for (int i = 0; i < 2; i++) {
        ASSERT_NEAR(delta_solve[i], 0, 1e-3);
    }
}

TEST(ITTERATIONS, MPI) {
    CSRMatrix matrix_a({
                           {{0,0}, 10.0},
                           {{0,1}, -0.5},
                           {{1,0}, -0.5},
                           {{1, 1}, 10.0}
                       },
                       2, 2);
    vector<float> b{1, 3};
    vector<float> x{1, 1};
    float tolerance = 1e-5;
    float tau = 1e-2;
    vector<float> result = MPI(matrix_a, x, b, tolerance, tau);
    vector<float> delta_solve = matrix_a * result - b;
    for (int i = 0; i < 2; i++) {
        ASSERT_NEAR(delta_solve[i], 0, 1e-3);
    }
}