#include "gtest/gtest.h"
#include "../CSR_Matrix/csr_matrix.h"


TEST(Matrix, Constructor) {
    CSRMatrix matrix({
                      {{0, 0}, 1},
                      {{0, 1}, 0},
                      {{0, 2}, 19.1},
                      {{0, 3}, 0},
                      {{0, 4}, 0},
                      {{0, 5}, 99.5},
                      {{0, 6}, 0},
                      {{1, 0}, 0},
                      {{1, 1}, 1.98},
                      {{1, 2}, 2.009},
                      {{1, 3}, 3.11},
                      {{1, 4}, 0},
                      {{1, 5}, 0},
                      {{1, 6}, 0},
                      {{2, 0}, 0},
                      {{2, 1}, 0},
                      {{2, 2}, 0},
                      {{2, 3}, 0},
                      {{2, 4}, 9.999},
                      {{2, 5}, 0},
                      {{2, 6}, 0},
                      {{3, 0}, 0},
                      {{3, 1}, 0},
                      {{3, 2}, 8.0},
                      {{3, 3}, 11.1},
                      {{3, 4}, 0},
                      {{3, 5}, 0},
                      {{3, 6}, 6.0006}
    });
    vector<double>  values = {1.0, 19.1, 99.5, 1.98, 2.009, 3.11, 9.999, 8.0, 11.1, 6.0006};
    vector<size_t> columns_indexes = {0, 2, 5, 1, 2, 3, 4, 2, 3, 6};
    vector<int> number_rows_non_0_elements = {0, 3, 6, 7, 10};
    vector<float> column1_for_multiplication = {1.0, 2.99, 3.0001, 11.21, 31.1, 26.878, 4.0};
    vector<float> check_answer1 = {2732.66291, 46.8105009, 310.9689, 172.4342};
    vector<float> column2_for_multiplication = {0, 0, 0, 1, 0, 0, 0};
    vector<float> check_answer2 = {0, 3.11, 0, 11.1};
    vector<float> column3_for_multiplication = {0, 0, 1, 0, 0, 0, 0};
    vector<float> check_answer3 = {19.1, 2.009, 0, 8};
    vector<float> column4_for_multiplication = {0, 1, 0, 0, 0, 0, 0};
    vector<float> check_answer4 = {0, 1.98, 0, 11.1};
    vector<float> column5_for_multiplication = {1, 0, 0, 0, 0, 0, 0};
    vector<float> check_answer5 = {1, 0, 0, 0};
    vector<float> column6_for_multiplication = {0, 0, 0, 0, 1, 0, 0};
    vector<float> check_answer6 = {0, 0, 9.999, 0};
    vector<float> column7_for_multiplication = {0, 0, 0, 0, 0, 1, 0};
    vector<float> check_answer7 = {99.5, 0, 0, 0};
    vector<float> column8_for_multiplication = {0, 0, 0, 0, 0, 0, 1};
    vector<float> check_answer8 = {0, 0, 0, 6.0006};
    vector<float> column9_for_multiplication = {2.78, 1.56, 0, 23.88, 6.09, 45.765, 8.654};
    vector<float> check_answer9 = {4556.3975, 77.3556, 60.89391, 316.9971924};
    vector<float> zero_column_for_multiplication = {0, 0, 0, 0, 0, 0, 0};
    vector<float> zero_check_answer = {0, 0, 0, 0};


    float first_non_0_element_of_matrix = matrix.GiveElement(1, 3);
    float second_non_0_element_of_matrix = matrix.GiveElement(3, 3);
    float third_non_0_element_of_matrix = matrix.GiveElement(0, 5);
    float first_0_element_of_matrix = matrix.GiveElement(3, 5);
    float second_0_element_of_matrix = matrix.GiveElement(1, 0);
    float third_0_element_of_matrix = matrix.GiveElement(0, 1);
    vector<float> answer1 = matrix.MultiplyByColumn(column1_for_multiplication);
    vector<float> answer2 = matrix.MultiplyByColumn(column2_for_multiplication);
    vector<float> answer3 = matrix.MultiplyByColumn(column3_for_multiplication);
    vector<float> answer4 = matrix.MultiplyByColumn(column4_for_multiplication);
    vector<float> answer5 = matrix.MultiplyByColumn(column5_for_multiplication);
    vector<float> answer6 = matrix.MultiplyByColumn(column6_for_multiplication);
    vector<float> answer7 = matrix.MultiplyByColumn(column7_for_multiplication);
    vector<float> answer8 = matrix.MultiplyByColumn(column8_for_multiplication);
    vector<float> answer9 = matrix.MultiplyByColumn(column9_for_multiplication);
    vector<float> zero_answer = matrix.MultiplyByColumn(zero_column_for_multiplication);


    ASSERT_FALSE(matrix.GiveInformation().values.empty());
    ASSERT_FALSE(matrix.GiveInformation().columns_indexes.empty());
    ASSERT_FALSE(matrix.GiveInformation().number_rows_non_0_elements.empty());
    ASSERT_TRUE(matrix.GiveInformation().values == values);
    ASSERT_TRUE(matrix.GiveInformation().columns_indexes == columns_indexes);
    ASSERT_TRUE(matrix.GiveInformation().number_rows_non_0_elements == number_rows_non_0_elements);
    ASSERT_TRUE(first_non_0_element_of_matrix == 3.11);
    ASSERT_TRUE(second_non_0_element_of_matrix == 11.1);
    ASSERT_TRUE(third_non_0_element_of_matrix == 99.5);
    ASSERT_TRUE(first_0_element_of_matrix == 0);
    ASSERT_TRUE(second_0_element_of_matrix == 0);
    ASSERT_TRUE(third_0_element_of_matrix == 0);
    ASSERT_EQ(answer1, check_answer1);
    ASSERT_EQ(answer2, check_answer2);
    ASSERT_EQ(answer3, check_answer3);
    ASSERT_EQ(answer3, check_answer4);
    ASSERT_EQ(answer5, check_answer5);
    ASSERT_EQ(answer6, check_answer6);
    ASSERT_EQ(answer7, check_answer7);
    ASSERT_EQ(answer8, check_answer8);
    ASSERT_EQ(answer9, check_answer9);
    ASSERT_EQ(zero_answer, zero_check_answer);
}
