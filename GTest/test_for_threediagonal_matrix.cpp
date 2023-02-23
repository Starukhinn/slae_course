#include "gtest/gtest.h"
#include "../solving/ThreeDiagonalMatrix/progonka.h"


TEST(Matrix, Constructor) {
    ThreeDiagonalMatrix nan_matrix;
    ThreeDiagonalMatrix empty_matrix{};
    ThreeDiagonalMatrix not_empty_matrix({{7, 1,  0},
                                          {0, 5,  2},
                                          {3, 16, 27},
                                          {8, 1,  9},
                                          {2, 7,  2},
                                          {0, 6,  2}});

    vector<DiagonalElementsLine> check_matrix_elements = {{7, 1,  0},
                                                          {0, 5,  2},
                                                          {3, 16, 27},
                                                          {8, 1,  9},
                                                          {2, 7,  2},
                                                          {0, 6,  2}};


    ASSERT_TRUE(not_empty_matrix.GiveMatrix() == check_matrix_elements);
    ASSERT_EQ(nan_matrix.GiveMatrix().size(), 0);
    ASSERT_TRUE(empty_matrix.GiveMatrix().empty());
    ASSERT_EQ(not_empty_matrix, not_empty_matrix);
    ASSERT_TRUE(not_empty_matrix.GetSize() == 6);
    ASSERT_EQ(not_empty_matrix.GiveElement(0, 2), 0);
    ASSERT_EQ(not_empty_matrix.GiveElement(1, 1), 5);
    ASSERT_EQ(not_empty_matrix.GiveElement(4, 1), 7);
}


TEST(Progonka, CheckAnswer) {
    ThreeDiagonalMatrix matrix_1({{9.0, 7.0, 0.0},
                                  {1.0, 89.0, 2.0},
                                  {0.0, 33.0, 2.0}});
    NumbersColumn free_members_1({1.0, 5.0, 5.0});
    NumbersColumn answer_1({8.0/71.0, -1.0/497.0, 1259.0/497.0});
    ThreeDiagonalMatrix matrix_2({{3.0, 4.0, 0.0},
                                  {1.0, 7.0, 5.0},
                                  {5.0, 19.0, 8.0},
                                  {0.0, 78.0, 8.0}});
    NumbersColumn free_members_2({2.0, 8.0, 5.0, 9.0});
    NumbersColumn answer_2({-466.0 / 539.0, 619.0 / 539.0, 89.0 / 539.0, -2091.0 / 4312.0});
    ThreeDiagonalMatrix matrix_3({{1.0, 8.0, 0.0},
                                  {2.0, 6.0, 3.0},
                                  {8.0, 18.0, 9.0},
                                  {2.0, 7.0, 1.0},
                                  {0.0, 7.0, 5.0}});
    NumbersColumn free_members_3({2.0, 8.0, 5.0, 9.0, 2.0});
    NumbersColumn answer_3({2400.0 / 401.0, -799.0 / 1604.0, -787.0 / 2406.0, 1988.0 / 1203.0, -2302.0 / 1203.0});

    NumbersColumn answer_column_1 = Progonka(matrix_1, free_members_1);
    NumbersColumn answer_column_2 = Progonka(matrix_2, free_members_2);
    NumbersColumn answer_column_3 = Progonka(matrix_3, free_members_3);


    for(auto number_element = 0; number_element < answer_column_1.GiveSize(); ++ number_element){
        ASSERT_NEAR(answer_column_1.GiveElement(number_element), answer_1.GiveElement(number_element), 0.0001);
    }
    for(auto number_element = 0; number_element < answer_column_2.GiveSize(); ++ number_element){
        ASSERT_NEAR(answer_column_2.GiveElement(number_element), answer_2.GiveElement(number_element), 0.0001);
    }
    for(auto number_element = 0; number_element < answer_column_3.GiveSize(); ++ number_element){
        ASSERT_NEAR(answer_column_3.GiveElement(number_element), answer_3.GiveElement(number_element), 0.0001);
    }
}