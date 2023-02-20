#include "gtest/gtest.h"
#include "../ThreeDiagonalMatrix/progonka.h"


TEST(Matrix, Constructor) {
    ThreeDiagonalMatrix nan_matrix;
    ThreeDiagonalMatrix empty_matrix{};
    ThreeDiagonalMatrix not_empty_matrix({{7, 1,  0},
                                          {0, 5,  2},
                                          {3, 16, 27},
                                          {8, 1,  9},
                                          {2, 7,  2},
                                          {0, 6,  2}});


    ASSERT_EQ(nan_matrix.GiveMatrix().size(), 0);
    ASSERT_TRUE(empty_matrix.GiveMatrix().empty());
    ASSERT_EQ(not_empty_matrix, not_empty_matrix);
    ASSERT_TRUE(not_empty_matrix.GiveMatrix().size() == 6);
}


TEST(Progonka, CheckAnswer) {
    ThreeDiagonalMatrix matrix_1({{1, 2, 0},
                                  {1, 2, 2},
                                  {0, 2, 2}});
    NumbersColumn free_members_1({1, 5, 5});
    NumbersColumn answer_1({0, 0.5, 2});
    ThreeDiagonalMatrix matrix_2({{3, 3, 0},
                                  {1, 5, 5},
                                  {5, 8, 8},
                                  {0, 7, 8}});
    NumbersColumn free_members_2({2, 8, 5, 9});
    NumbersColumn answer_2({124 / 63, -82 / 63, -158 / 63, -77 / 72});
    ThreeDiagonalMatrix matrix_3({{1, 8, 0},
                                  {2, 6, 3},
                                  {8, 8, 9},
                                  {2, 7, 1},
                                  {0, 7, 5}});
    NumbersColumn free_members_3({2, 8, 5, 9, 2});
    NumbersColumn answer_3({3560 / 503, -1277 / 2012, -787 / 1006, 913 / 503, 1077 / 503});

    NumbersColumn answer_column_1 = Progonka(matrix_1, free_members_1);
    NumbersColumn answer_column_2 = Progonka(matrix_2, free_members_2);
    NumbersColumn answer_column_3 = Progonka(matrix_3, free_members_3);

    ASSERT_EQ(answer_column_1, answer_1);
    ASSERT_EQ(answer_column_2, answer_2);
    ASSERT_EQ(answer_column_3, answer_3);
}