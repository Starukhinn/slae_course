//#include "gtest/gtest.h"
//#include "../solving/iterative_methods/MPI_fast.h"
//
//TEST(CSR_matrix_tests, SIM_Chebyshev_acceleration) {
//    // Symmetrical m > 0 matrix
//    CSRMatrix matrix ({
//        {{{0, 0}, 12},
//         {{0, 1}, 17},
//         {{0, 2}, 3},
//         {{1, 0}, 17},
//         {{1, 1}, 15825},
//         {{1, 2}, 28},
//         {{2, 0}, 3},
//         {{2, 1}, 28},
//         {{2, 2}, 238}},
//        3, 3})
//        ;
//    vector<double> x0(3, 1);
//    vector<double> b {1, 2, 3};
//    vector<double> r {0.0804084117, 0.0000194982, 0.0115891967};
//    double accuracy = pow(10, -12);
//    // Result w/ Chebyshev acceleration
//    size_t R = 5;
//    double eig_min = 11.8;
//    double eig_max = 15825.1;
//    auto resFast = m.SIM_Chebyshev_acceleration(x0, b, R, eig_min, eig_max, accuracy);
//    // Result w/o Chebyshev acceleration
//    double tau = 0.0001;
//    auto res = m.Simple_iteration_method(x0, b, tau, accuracy);
//    // Testing results
//    for (int i = 0; i < r.size(); ++i) {
//        ASSERT_NEAR(res.first[i], r[i], pow(10, -10));
//        ASSERT_NEAR(resFast.first[i], r[i], pow(10, -10));
//    }
//    // Number of iterations made
//    std::cout << "FPI with acceleration: " << resFast.second.first << " iterations made" << std::endl;
//    std::cout << "Common FPI: " << res.second.first << " iterations made" << std::endl;
//}
