#include "gtest/gtest.h"
#include "/Users/dmitrystarukhin/slae_course/1st_hw/progonka.h"


TEST(Matrix, Constructor){
    TriangleMatrix nan_matrix;
    TriangleMatrix empty_matrix(5);
    TriangleMatrix not_empty_matrix({{0,  1,  2},
                                     {0,  5,  2},
                                     {3,  16, 27},
                                     {8,  1,  9},
                                     {2,  7,  2},
                                     {22, 6,  2}});


    ASSERT_EQ(nan_matrix.GiveMatrix().size(), 0);
    ASSERT_TRUE(empty_matrix.GiveMatrix().empty());
    ASSERT_EQ(not_empty_matrix, not_empty_matrix);
    ASSERT_TRUE(not_empty_matrix.GiveMatrix().size() == 6);
}


TEST(Progonka, Answer) {

}
