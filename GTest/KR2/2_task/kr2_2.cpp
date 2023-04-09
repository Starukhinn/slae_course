#pragma once

#include "../../../solving/CSR_Matrix/csr_matrix.h"
#include "../../../solving/iterative_methods/MPI.h"
#include "../../../solving/iterative_methods/MPI_fast.h"
#include "../../../solving/iterative_methods/steepest_descent.h"
#include "../../../solving/iterative_methods/symmetric_GZ.h"
#include "gtest/gtest.h"

TEST(FirstTask, First) {
    map<Indexes, double> matrix_data{
        {{0, 0}, 19.0},
        {{1, 1}, 22.0},
        {{2, 2}, 25.0},
        {{3, 3}, 28.5}};
    CSRMatrix matrix_a(matrix_data, 4, 4);
    vector<double> free_column(4, 6.0);
    vector<double> x_0(4, 0.0);
    double tau = 0.9 * 2.0 / 28.5;
    vector<double> answer =
        MPI(matrix_a, x_0, free_column, 1e-13, tau,
            "/Users/dmitrystarukhin/slae_course/GTest/KR2/2_task/kr2_2_MPI1.txt")
            .first;
    vector<double> delta_solve = matrix_a * answer - free_column;
    for (int i = 0; i < 2; ++i) {
        ASSERT_NEAR(delta_solve[i], 0, 1e-13);
    }
}

TEST(FirstTask, Second) {
    map<Indexes, double> matrix_data{
        {{0, 0}, 19.0},
        {{1, 1}, 22.0},
        {{2, 2}, 25.0},
        {{3, 3}, 28.5}};
    CSRMatrix matrix_a(matrix_data, 4, 4);
    vector<double> free_column(4, 3.0);
    vector<double> x_0(4, 0.0);
    double tau = 2 / (19.0 + 28.5);
    vector<double> answer =
        MPI(matrix_a, x_0, free_column, 1e-13, tau,
            "/Users/dmitrystarukhin/slae_course/GTest/KR2/2_task/kr2_2_MPI1.txt")
            .first;
    vector<double> delta_solve = matrix_a * answer - free_column;
    for (int i = 0; i < 2; ++i) {
        ASSERT_NEAR(delta_solve[i], 0, 1e-13);
    }
}

TEST(FirstTask, Fourth) {
    map<Indexes, double> matrix_data{
        {{0, 0}, 19.0},
        {{1, 1}, 22.0},
        {{2, 2}, 25.0},
        {{3, 3}, 28.5}};
    CSRMatrix matrix_a(matrix_data, 4, 4);
    vector<double> free_column(4, 6.0);
    vector<double> x_0(4, 0.0);
    double min_lambda = 19.0;
    double max_lambda = 28.5;
    vector<double> answer =
            MpiFast(matrix_a, x_0, free_column, 1e-13, 3, min_lambda, max_lambda).first;
    vector<double> delta_solve = matrix_a * answer - free_column;
    for (int i = 0; i < 2; ++i) {
        ASSERT_NEAR(delta_solve[i], 0, 1e-13);
    }
}