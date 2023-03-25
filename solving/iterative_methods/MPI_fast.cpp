#include "MPI_fast.h"

vector<double> MakePolynomialRoots(const double &min_lambda, const double &max_lambda,
                                   const double &sin_a, const double &cos_a, double &sin_b,
                                   const size_t &number_polynomial_roots) {
    vector<double> polynomial_roots(number_polynomial_roots, 0);
    polynomial_roots[0] = cos(M_PI / (2 * number_polynomial_roots));
    for (int number_root = 1; number_root < number_polynomial_roots; ++number_root) {
        polynomial_roots[number_root] = polynomial_roots[number_root - 1] * cos_a - sin_a * sin_b;
        sin_b = polynomial_roots[number_root - 1] * sin_a + sin_b * cos_a;
        polynomial_roots[number_root - 1] =
            (min_lambda + max_lambda) / 2 +
            (max_lambda - min_lambda) / 2 * polynomial_roots[number_root - 1];
    }
    polynomial_roots[number_polynomial_roots - 1] =
        (max_lambda + min_lambda) / 2 +
        (max_lambda - min_lambda) / 2 * polynomial_roots[number_polynomial_roots - 1];
    return polynomial_roots;
}

vector<size_t> MakeIndexSequence(const size_t &number_polynomial_roots, const int &r_parameter) {
    vector<size_t> indexes(number_polynomial_roots, 0);
    indexes[static_cast<size_t>(pow(2, r_parameter - 1))] = 1;
    for (int i = 2; i <= r_parameter; ++i) {
        int step = static_cast<int>(pow(2, r_parameter - i));
        for (int j = 0; j < number_polynomial_roots; j += 2 * step) {
            indexes[j + step] = static_cast<size_t>(pow(2, i)) - indexes[j] - 1;
        }
    }
    return indexes;
}

pair<vector<double>, int> FastMPIAlgorithm(const CSRMatrix &a_matrix, const vector<double> &x_0,
                                           const vector<double> &b, const double &tolerance,
                                           const size_t &number_polynomial_roots,
                                           const vector<double> &polynomial_roots,
                                           const vector<size_t> &indexes) {
    vector<double> solve = a_matrix * x_0 - b;
    vector<double> x = x_0;
    int number_iterations = 0;
    while (GiveVectorLength(solve) > tolerance) {
        for (size_t number_root = 0; number_root < number_polynomial_roots; ++number_root) {
            x = x - 1 / polynomial_roots[indexes[number_root]] * solve;
            solve = a_matrix * x_0 - b;
            ++number_iterations;
        }
    }
    return {solve, number_polynomial_roots};
}

pair<vector<double>, int> MpiFast(const CSRMatrix &a_matrix, const vector<double> &x_0,
                                  const vector<double> &b, const double &tolerance,
                                  const int &r_parameter, const double &min_lambda,
                                  const double &max_lambda) {
    size_t number_polynomial_roots = static_cast<size_t>(pow(2, r_parameter));
    double sin_a = sin(M_PI / number_polynomial_roots);
    double cos_a = cos(M_PI / number_polynomial_roots);
    double sin_b = sin(M_PI / (2 * number_polynomial_roots));
    vector<double> polynomial_roots =
        MakePolynomialRoots(min_lambda, max_lambda, sin_a, cos_a, sin_b, number_polynomial_roots);
    vector<size_t> indexes = MakeIndexSequence(number_polynomial_roots, r_parameter);
    return FastMPIAlgorithm(a_matrix, x_0, b, tolerance, number_polynomial_roots, polynomial_roots,
                            indexes);
}
