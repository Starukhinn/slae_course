//#include "gtest/gtest.h"
//#include "../solving/CSR_Matrix/csr_matrix.h"
//#include "../solving/Vector/vector_matrix.h"
//#include "../solving/iterative_methods/MPI.h"
//#include "../solving/iterative_methods/GZ.h"
//#include "../solving/iterative_methods/jacobi.cpp"
//#include "../solving/iterative_methods/MPI_fast.h"
//#include "../solving/iterative_methods/SOR.h"
//#include "../solving/iterative_methods/SSOR.h"
//#include "../solving/iterative_methods/fast_descent.h"
//
//TEST(ITTERATIONS, GAUS_ZEIDEL) {
//    CSRMatrix matrix_a({
//                           {{0,0}, 16.0},
//                           {{0,1}, 3.0},
//                           {{1,0}, 7.0},
//                           {{1, 1}, -11.0}
//                       },
//                       2, 2);
//    vector<double> b{11.0, 13.0};
//    vector<double> x{1.0, 1.0};
//    double tolerance = 1e-7;
//    vector<double> result = GZ(matrix_a, x, b, tolerance, "/Users/dmitrystarukhin/slae_course/GTest/data_graphs/GZ.txt").first;
//    vector<double> delta_solve = matrix_a * result - b;
//    for (int i = 0; i < 2; i++) {
//        ASSERT_NEAR(delta_solve[i], 0, 1e-3);
//    }
//}
//
//TEST(ITTERATIONS, JACOBI) {
//    CSRMatrix matrix_a({
//                           {{0,0}, 16.0},
//                           {{0,1}, 3.0},
//                           {{1,0}, 7.0},
//                           {{1, 1}, -11.0}
//                       },
//                       2, 2);
//    vector<double> b{11.0, 13.0};
//    vector<double> x{1.0, 1.0};
//    double tolerance = 1e-7;
//    vector<double> result = Jacobi(matrix_a, x, b, tolerance, "/Users/dmitrystarukhin/slae_course/GTest/data_graphs/Jacobi.txt").first;
//    vector<double> delta_solve = matrix_a * result - b;
//    for (int i = 0; i < 2; i++) {
//        ASSERT_NEAR(delta_solve[i], 0, 1e-3);
//    }
//}
//
//TEST(ITTERATIONS, MPI) {
//    CSRMatrix matrix_a({
//                           {{0,0}, 10.0},
//                           {{0,1}, -0.5},
//                           {{1,0}, -0.5},
//                           {{1, 1}, 10.0}
//                       },
//                       2, 2);
//    vector<double> b{1, 3};
//    vector<double> x{1, 1};
//    double tolerance = 1e-12;
//    double tau = 1e-2;
//    vector<double> result = MPI(matrix_a, x, b, tolerance, tau, "/Users/dmitrystarukhin/slae_course/GTest/data_graphs/MPI.txt").first;
//    vector<double> delta_solve = matrix_a * result - b;
//    for (int i = 0; i < 2; i++) {
//        ASSERT_NEAR(delta_solve[i], 0, 1e-3);
//    }
//}
//
//TEST(ITTERATIONS, MPI_FAST){
//    CSRMatrix matrix_a(
//        {{{0, 0}, 10.0},
//         {{0, 1}, 1.0},
//         {{1, 0}, 1.0},
//         {{1, 1}, 7.0},
//         {{2, 1}, 0.1},
//         {{2, 2}, 1.0}},
//        3, 3);
//    vector<double> b{20, 30, 1};
//    vector<double> x{0, 0, 0};
//    vector<double> result = MpiFast(matrix_a, x, b, pow(10, -12),8, 1, 10.30278).first;
//    vector<double> delta_solve = matrix_a * result - b;
//    for (int number_element = 0; number_element < delta_solve.size(); number_element++) {
//        ASSERT_NEAR(delta_solve[number_element], 0, 1e-3);
//    }
//}
//
//
//TEST(ITTERATIONS, SOR) {
//    CSRMatrix matrix_a(
//        {{{0, 0}, 10.0},
//         {{0, 1}, 1.0},
//         {{1, 0}, 1.0},
//         {{1, 1}, 7.0},
//         {{2, 1}, 0.1},
//         {{2, 2}, 1.0}},
//        3, 3);
//    vector<double> b{20, 30, 1};
//    vector<double> x{0, 0, 0};
//    vector<double> result = SOR(matrix_a, x, b, 1e-12, 1.5).first;
//
//    vector<double> delta_solve = matrix_a * result - b;
//
//    for (int number_element = 0; number_element < delta_solve.size(); number_element++) {
//        ASSERT_NEAR(delta_solve[number_element], 0, 1e-3);
//    }
//}
//
//TEST(ITTERATIONS, SSOR){
//    CSRMatrix matrix_a(
//        {{{0, 0}, 12},
//         {{0, 1}, 17},
//         {{0, 2}, 3},
//         {{1, 0}, 17},
//         {{1, 1}, 15825},
//         {{1, 2}, 28},
//         {{2, 0}, 3},
//         {{2, 1}, 28},
//         {{2, 2}, 238}},
//        3, 3);
//    vector<double> b{1, 2, 3};
//    vector<double> x{1, 1, 1};
//    vector<double> result = SSOR(matrix_a, x, b, 0.5, 15825.1, 1e-12).first;
//    vector<double> delta_solve = matrix_a * result - b;
//
//    for (int number_element = 0; number_element < delta_solve.size(); number_element++) {
//        ASSERT_NEAR(delta_solve[number_element], 0, 1e-3);
//    }
//}
//
//
//TEST(DESCENT, FIRST){
//    CSRMatrix matrix_a({{{0, 0}, 12},
//                        {{0, 1}, 17},
//                        {{0, 2}, 3},
//                        {{1, 0}, 17},
//                        {{1, 1}, 15825},
//                        {{1, 2}, 28},
//                                     {{2, 0},
//                         3}, {{2, 1}, 28},
//                        {{2, 2}, 238}},
//                       3, 3);
//    vector<double> x0(3, 1);
//    vector<double> b {1, 2, 3};
//    std::vector<double> r {0.0804084117, 0.0000194982, 0.0115891967};
//    double accuracy = 1e-12;
//    // Result w/ SIM Chebyshev acceleration
//    size_t R = 8;
//    double eig_min = 11.8;
//    double eig_max = 15825.1;
//    auto resFast = MPI_fast(first, x0, b,  accuracy, R);
//    // Result w/ Steepest descent method
//    auto res = Descent_method(first, x0, b, accuracy);
//    std::cout << res.second.second;
//    // Testing results
//    // std::cout << res.second.second;
//    for (int i = 0; i < r.size(); ++i) {
//        ASSERT_NEAR(res.first[i], r[i], 1e-10);
//        ASSERT_NEAR(resFast.first[i], r[i], 1e-10);
//    }
//    ASSERT_EQ(1, 1);
//}