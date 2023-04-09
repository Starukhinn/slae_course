#pragma once

#include "../../../solving/CSR_Matrix/csr_matrix.h"
#include "../../../solving/iterative_methods/MPI.h"
#include "../../../solving/iterative_methods/MPI_fast.h"
#include "../../../solving/iterative_methods/steepest_descent.h"
#include "../../../solving/iterative_methods/symmetric_GZ.h"
#include "gtest/gtest.h"

using std::map;
using std::vector;

TEST(FirstTask, First) {
    map<Indexes, double> matrix_data;
    double a = 19.0;
    double b = 43.0;
    int l = 17;
    for (int i = 0; i < 289; ++i) {
        for (int j = 0; j < 289; ++j) {
            if (i == j) {
                Indexes indexes = {static_cast<size_t>(i), static_cast<size_t>(j)};
                matrix_data[indexes] = 2 * b;
            } else if (j == i + 1 or j == i + l or i == j + l or i == j + 1) {
                Indexes indexes = {static_cast<size_t>(i), static_cast<size_t>(j)};
                matrix_data[indexes] = a;
            }
        }
    }
    CSRMatrix matrix_a(matrix_data, 289, 289);
    vector<double> free_column(289, 4.0);
    vector<double> x_0(289, 0.0);
    vector<double> answer = MPI(matrix_a, x_0, free_column, 1e-13, 1 / 160.154610771072186,
                                "/Users/dmitrystarukhin/slae_course/GTest/KR2/1_task/kr2_1_MPI1.txt")
                                .first;
    vector<double> delta_solve = matrix_a * answer - free_column;
    for (int i = 0; i < 2; ++i) {
        ASSERT_NEAR(delta_solve[i], 0, 1e-13);
    }
}

TEST(FirstTask, Second) {
    map<Indexes, double> matrix_data;
    double a = 19.0;
    double b = 43.0;
    int l = 17;
    for (int i = 0; i < 289; ++i) {
        for (int j = 0; j < 289; ++j) {
            if (i == j) {
                Indexes indexes = {static_cast<size_t>(i), static_cast<size_t>(j)};
                matrix_data[indexes] = 2 * b;
            } else if (j == i + 1 or j == i + l or i == j + l or i == j + 1) {
                Indexes indexes = {static_cast<size_t>(i), static_cast<size_t>(j)};
                matrix_data[indexes] = a;
            }
        }
    }
    CSRMatrix matrix_a(matrix_data, 289, 289);
    vector<double> free_column(289, 4.0);
    vector<double> x_0(289, 0.0);
    double min_lambda = 2 * (b - 2 * a * std::cos(M_PI / (l + 1)));
    double max_lambda = 2 * (b + 2 * a * std::cos(M_PI / (l + 1)));
    double tau = 2 / (min_lambda + max_lambda);
    vector<double> answer = MPI(matrix_a, x_0, free_column, 1e-13, tau,
                                "/Users/dmitrystarukhin/slae_course/GTest/KR2/1_task/kr2_1_MPI2.txt")
                                .first;
    vector<double> delta_solve = matrix_a * answer - free_column;
    for (int i = 0; i < 2; ++i) {
        ASSERT_NEAR(delta_solve[i], 0, 1e-13);
    }
}

TEST(FirstTask, Third) {
    map<Indexes, double> matrix_data;
    double a = 19.0;
    double b = 43.0;
    int l = 17;
    for (int i = 0; i < 289; ++i) {
        for (int j = 0; j < 289; ++j) {
            if (i == j) {
                Indexes indexes = {static_cast<size_t>(i), static_cast<size_t>(j)};
                matrix_data[indexes] = 2 * b;
            } else if (j == i + 1 or j == i + l or i == j + l or i == j + 1) {
                Indexes indexes = {static_cast<size_t>(i), static_cast<size_t>(j)};
                matrix_data[indexes] = a;
            }
        }
    }
    CSRMatrix matrix_a(matrix_data, 289, 289);
    vector<double> free_column(289, 4.0);
    vector<double> x_0(289, 0.0);
    double min_lambda = 2 * (b - 2 * a * std::cos(M_PI / (l + 1)));
    double max_lambda = 2 * (b + 2 * a * std::cos(M_PI / (l + 1)));
    auto answer =
        MpiFast(matrix_a, x_0, free_column, 1e-13, 3, min_lambda, max_lambda);
    vector<double> delta_solve = matrix_a * answer.first - free_column;
    std::cout<< answer.second;
    for (int i = 0; i < 2; ++i) {
        ASSERT_NEAR(delta_solve[i], 0, 1e-13);
    }
}

TEST(FirstTask, Fourth) {
    map<Indexes, double> matrix_data;
    double a = 19.0;
    double b = 43.0;
    int l = 17;
    for (int i = 0; i < 289; ++i) {
        for (int j = 0; j < 289; ++j) {
            if (i == j) {
                Indexes indexes = {static_cast<size_t>(i), static_cast<size_t>(j)};
                matrix_data[indexes] = 2 * b;
            } else if (j == i + 1 or j == i + l or i == j + l or i == j + 1) {
                Indexes indexes = {static_cast<size_t>(i), static_cast<size_t>(j)};
                matrix_data[indexes] = a;
            }
        }
    }
    CSRMatrix matrix_a(matrix_data, 289, 289);
    vector<double> free_column(289, 4.0);
    vector<double> x_0(289, 0.0);
    vector<double> answer = SymmetricGZ(matrix_a, x_0, free_column, 1 / 1.5, 1e-13, "/Users/dmitrystarukhin/slae_course/GTest/KR2/1_task/gz_symmetric_data.txt").first;
    vector<double> delta_solve = matrix_a * answer - free_column;
    for (int i = 0; i < 2; i++) {
        ASSERT_NEAR(delta_solve[i], 0, 1e-13);
    }
}


TEST(FirstTask, Fiveth) {
    map<Indexes, double> matrix_data;
    double a = 19.0;
    double b = 43.0;
    int l = 17;
    for (int i = 0; i < 289; ++i) {
        for (int j = 0; j < 289; ++j) {
            if (i == j) {
                Indexes indexes = {static_cast<size_t>(i), static_cast<size_t>(j)};
                matrix_data[indexes] = 2 * b;
            } else if (j == i + 1 or j == i + l or i == j + l or i == j + 1) {
                Indexes indexes = {static_cast<size_t>(i), static_cast<size_t>(j)};
                matrix_data[indexes] = a;
            }
        }
    }
    CSRMatrix matrix_a(matrix_data, 289, 289);
    vector<double> free_column(289, 4.0);
    vector<double> x_0(289, 0.0);
    double min_lambda = 2 * (b - 2 * a * std::cos(M_PI / (l + 1)));
    double max_lambda = 2 * (b + 2 * a * std::cos(M_PI / (l + 1)));
    std::ofstream outfile;
    outfile.open("/Users/dmitrystarukhin/slae_course/GTest/KR2/1_task/MPI_fast_data.txt", std::ofstream::out | std::ofstream::app);
    for(double intermediate_lambda = 150.4; intermediate_lambda < max_lambda;
             intermediate_lambda += 0.05){
        int number_iterations =
            MpiFast(matrix_a, x_0, free_column, 1e-13, 3, min_lambda, intermediate_lambda).second;
        outfile << intermediate_lambda << " " << number_iterations << "\n";
    }
}