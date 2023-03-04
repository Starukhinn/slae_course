#include "gtest/gtest.h"
#include "../solving/Vector/vector_matrix.h"

TEST(Vector, Constructor) {
    VectorMatrix empty_vector;
    VectorMatrix null_vector({0.0, 0.0, 0.0, 0.0, 0.0, 0.0});
    VectorMatrix vector1({1.08, 2.802, 3.949, 4.0});
    VectorMatrix vector2({11.23, 23.11, 33.77, 54.995, 88.8594, 99.494, 22.49959, -1.9});
    vector<float> check_empty_vector = {};
    vector<float> check_null_vector = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    vector<float> check_vector1 = {1.08, 2.802, 3.949, 4.0};
    vector<float> check_vector2 = {11.23, 23.11, 33.77, 54.995, 88.8594, 99.494, 22.49959, -1.9};



    ASSERT_TRUE(empty_vector.GiveSize() == 0);
    ASSERT_EQ(empty_vector.GiveVector(), check_empty_vector);
    ASSERT_TRUE(null_vector.GiveSize() == check_null_vector.size());
    ASSERT_EQ(null_vector.GiveVector(), check_null_vector);
    ASSERT_TRUE(vector1.GiveSize() == check_vector1.size());
    ASSERT_EQ(vector1.GiveVector(), check_vector1);
    ASSERT_TRUE(vector2.GiveSize() == check_vector2.size());
    ASSERT_EQ(vector2.GiveVector(), check_vector2);
    ASSERT_NEAR(null_vector.GiveElement(1) , 0.0, 0.0001);
    ASSERT_NEAR(null_vector.GiveElement(5) , 0.0, 0.0001);
    ASSERT_NEAR(null_vector.GiveElement(3) , 0.0, 0.0001);
    ASSERT_NEAR(vector1.GiveElement(0) , 1.08, 0.0001);
    ASSERT_NEAR(vector1.GiveElement(3) , 4.0, 0.0001);
    ASSERT_NEAR(vector1.GiveElement(2) , 3.949, 0.0001);
    ASSERT_NEAR(vector2.GiveElement(1) , 23.11, 0.0001);
    ASSERT_NEAR(vector2.GiveElement(3) , 54.995, 0.0001);
    ASSERT_NEAR(vector2.GiveElement(7) , -1.9, 0.0001);
}

TEST(Vector, Operations) {
    VectorMatrix null_vector({0.0, 0.0, 0.0, 0.0, 0.0, 0.0});
    VectorMatrix vector1({1.08, 2.802, 3.949, 4.0, 0.799, -92.9});
    VectorMatrix vector2({0.77, 2.33, 0.99, -5.089, 2.13, -0.9});
    VectorMatrix vector3({11.23, 23.11, 33.77, 54.995, 88.8594, 99.494, 22.49959, -1.9});
    VectorMatrix vector4({-11.23, 3.09, 56.86, 9.11, -4.45, 213.888, 31.0, -1.9});
    VectorMatrix vector5({14.9, 21.99, -83.83, 11.7, 0.0, -1.111});
    VectorMatrix vector6({-33.3, 34.88, 11.2, -11.7, 100.77, 1.091});


    float answer_multiply_0_1 = null_vector * vector1;
    float check_answer_multiply_0_1 = 0.0;
    float answer_multiply_0_2 = null_vector * vector1;
    float check_answer_multiply_0_2 = 0.0;
    float answer_multiply_1_2 = vector1 * vector2;
    float answer_multiply_2_1 = vector2 * vector1;
    float check_answer_multiply_1_2 = 76.22564;
    float answer_multiply_3_4 = vector3 * vector4;
    float answer_multiply_4_3 = vector4 * vector3;
    float check_answer_multiply_3_4 = 23952.709282;
    float answer_multiply_5_6 = vector5 * vector6;
    float answer_multiply_6_5 = vector6 * vector5;
    float check_answer_multiply_5_6 = -806.156901;

    VectorMatrix answer_plus_0_1 = null_vector + vector1;
    VectorMatrix check_answer_plus_0_1 = VectorMatrix({1.08, 2.802, 3.949, 4.0, 0.799, -92.9});
    VectorMatrix answer_plus_0_2 = null_vector + vector2;
    VectorMatrix answer_plus_2_0 = vector2 + null_vector;
    VectorMatrix check_answer_plus_0_2 = VectorMatrix({0.77, 2.33, 0.99, -5.089, 2.13, -0.9});
    VectorMatrix answer_plus_3_4 = vector3 + vector4;
    VectorMatrix answer_plus_4_3 = vector4 + vector3;
    VectorMatrix check_answer_plus_3_4 = VectorMatrix({0.0, 26.2, 90.63, 64.10499999999999, 84.40939999999999, 313.382, 53.49959, -3.8});
    VectorMatrix answer_plus_5_6 = vector5 + vector6;
    VectorMatrix answer_plus_6_5 = vector6 + vector5;
    VectorMatrix check_answer_plus_5_6= VectorMatrix({-18.4, 56.870000000000005, -72.63, 0.0, 100.77, -0.020000000000000018});

    VectorMatrix answer_minus_0_1 = null_vector - vector1;
    VectorMatrix check_answer_minus_0_1 = VectorMatrix({-1.08, -2.802, -3.949, -4.0, -0.799, 92.9});
    VectorMatrix answer_minus_0_2 = null_vector - vector2;
    VectorMatrix check_answer_minus_0_2 = VectorMatrix({-0.77, -2.33, -0.99, 5.089, -2.13, 0.9});
    VectorMatrix answer_minus_2_0 = vector2 - null_vector;
    VectorMatrix check_answer_minus_2_0 = VectorMatrix({0.77, 2.33, 0.99, -5.089, 2.13, -0.9});
    VectorMatrix answer_minus_3_4 = vector3 - vector4;
    VectorMatrix check_answer_minus_3_4 = VectorMatrix({22.46, 20.02, -23.089999999999996, 45.885, 93.3094, -114.394, -8.500409999999999, 0.0});
    VectorMatrix answer_minus_4_3 = vector4 - vector3;
    VectorMatrix check_answer_minus_4_3 = VectorMatrix({-22.46, -20.02, 23.089999999999996, -45.885, -93.3094, 114.394, 8.500409999999999, 0.0});
    VectorMatrix answer_minus_5_6 = vector5 - vector6;
    VectorMatrix check_answer_minus_5_6 = VectorMatrix({48.199999999999996, -12.890000000000004, -95.03, 23.4, -100.77, -2.202});
    VectorMatrix answer_minus_6_5 = vector6 - vector5;
    VectorMatrix check_answer_minus_6_5 = VectorMatrix({-48.199999999999996, 12.890000000000004, 95.03, -23.4, 100.77, 2.202});

    VectorMatrix answer_multiply_0 = 3.9 * null_vector;
    VectorMatrix check_answer_multiply_0 = VectorMatrix({0.0, 0.0, 0.0, 0.0, 0.0, 0.0});
    VectorMatrix answer_multiply_2 = 0.0 * vector2;
    VectorMatrix check_answer_multiply_2 = VectorMatrix({0.0, 0.0, 0.0, 0.0, 0.0, 0.0});
    VectorMatrix answer_multiply_3 = -6.5 * vector3;
    VectorMatrix check_answer_multiply_3 = VectorMatrix({-72.995, -150.215, -219.50500000000002, -357.4675, -577.5861, -646.711, -146.24733500000002, 12.35});
    VectorMatrix answer_multiply_4 = -1.0 * vector4;
    VectorMatrix check_answer_multiply_4 = VectorMatrix({11.23, -3.09, -56.86, -9.11, 4.45, -213.888, -31.0, 1.9});
    VectorMatrix answer_multiply_5 = 3.56 * vector5;
    VectorMatrix check_answer_multiply_5 = VectorMatrix({53.044000000000004, 78.28439999999999, -298.4348, 41.652, 0.0, -3.9551600000000002});
    VectorMatrix answer_multiply_6 = -34.8885 * vector6;
    VectorMatrix check_answer_multiply_6 = VectorMatrix({1161.78705, -1216.9108800000001, -390.7512, 408.19545, -3515.714145, -38.0633535});





    ASSERT_NEAR(answer_multiply_0_1, check_answer_multiply_0_1, 0.0001);
    ASSERT_NEAR(answer_multiply_0_2, check_answer_multiply_0_2, 0.0001);
    ASSERT_NEAR(answer_multiply_1_2, check_answer_multiply_1_2, 0.0001);
    ASSERT_NEAR(answer_multiply_2_1, check_answer_multiply_1_2, 0.0001);
    ASSERT_NEAR(answer_multiply_3_4, check_answer_multiply_3_4, 0.01);
    ASSERT_NEAR(answer_multiply_4_3, check_answer_multiply_3_4, 0.01);
    ASSERT_NEAR(answer_multiply_5_6, check_answer_multiply_5_6, 0.1);
    ASSERT_NEAR(answer_multiply_6_5, check_answer_multiply_5_6, 0.1);


    for(auto number_element = 0; number_element < answer_plus_0_1.GiveSize(); ++number_element){
        ASSERT_NEAR(answer_plus_0_1.GiveElement(number_element), check_answer_plus_0_1.GiveElement(number_element), 0.0001);
    }
    for(auto number_element = 0; number_element < answer_plus_0_2.GiveSize(); ++number_element){
        ASSERT_NEAR(answer_plus_0_2.GiveElement(number_element), check_answer_plus_0_2.GiveElement(number_element), 0.0001);
    }
    for(auto number_element = 0; number_element < answer_plus_0_2.GiveSize(); ++number_element){
        ASSERT_NEAR(answer_plus_2_0.GiveElement(number_element), check_answer_plus_0_2.GiveElement(number_element), 0.0001);
    }
    for(auto number_element = 0; number_element < answer_plus_3_4.GiveSize(); ++number_element){
        ASSERT_NEAR(answer_plus_3_4.GiveElement(number_element), check_answer_plus_3_4.GiveElement(number_element), 0.0001);
    }
    for(auto number_element = 0; number_element < answer_plus_3_4.GiveSize(); ++number_element){
        ASSERT_NEAR(answer_plus_4_3.GiveElement(number_element), check_answer_plus_3_4.GiveElement(number_element), 0.0001);
    }
    for(auto number_element = 0; number_element < answer_plus_5_6.GiveSize(); ++number_element){
        ASSERT_NEAR(answer_plus_5_6.GiveElement(number_element), check_answer_plus_5_6.GiveElement(number_element), 0.0001);
    }
    for(auto number_element = 0; number_element < answer_plus_5_6.GiveSize(); ++number_element){
        ASSERT_NEAR(answer_plus_6_5.GiveElement(number_element), check_answer_plus_5_6.GiveElement(number_element), 0.0001);
    }


    for(auto number_element = 0; number_element < answer_minus_0_1.GiveSize(); ++number_element){
        ASSERT_NEAR(answer_minus_0_1.GiveElement(number_element), check_answer_minus_0_1.GiveElement(number_element), 0.0001);
    }
    for(auto number_element = 0; number_element < answer_minus_0_2.GiveSize(); ++number_element){
        ASSERT_NEAR(answer_minus_0_2.GiveElement(number_element), check_answer_minus_0_2.GiveElement(number_element), 0.0001);
    }
    for(auto number_element = 0; number_element < answer_minus_2_0.GiveSize(); ++number_element){
        ASSERT_NEAR(answer_minus_2_0.GiveElement(number_element), check_answer_minus_2_0.GiveElement(number_element), 0.0001);
    }
    for(auto number_element = 0; number_element < answer_minus_3_4.GiveSize(); ++number_element){
        ASSERT_NEAR(answer_minus_3_4.GiveElement(number_element), check_answer_minus_3_4.GiveElement(number_element), 0.0001);
    }
    for(auto number_element = 0; number_element < answer_minus_4_3.GiveSize(); ++number_element){
        ASSERT_NEAR(answer_minus_4_3.GiveElement(number_element), check_answer_minus_4_3.GiveElement(number_element), 0.0001);
    }
    for(auto number_element = 0; number_element < answer_minus_5_6.GiveSize(); ++number_element){
        ASSERT_NEAR(answer_minus_5_6.GiveElement(number_element), check_answer_minus_5_6.GiveElement(number_element), 0.0001);
    }
    for(auto number_element = 0; number_element < answer_minus_6_5.GiveSize(); ++number_element){
        ASSERT_NEAR(answer_minus_6_5.GiveElement(number_element), check_answer_minus_6_5.GiveElement(number_element), 0.0001);
    }


    for(auto number_element = 0; number_element < answer_multiply_0.GiveSize(); ++number_element){
        ASSERT_NEAR(answer_multiply_0.GiveElement(number_element), check_answer_multiply_0.GiveElement(number_element), 0.0001);
    }
    for(auto number_element = 0; number_element < answer_multiply_2.GiveSize(); ++number_element){
        ASSERT_NEAR(answer_multiply_2.GiveElement(number_element), check_answer_multiply_2.GiveElement(number_element), 0.0001);
    }
    for(auto number_element = 0; number_element < answer_multiply_3.GiveSize(); ++number_element){
        ASSERT_NEAR(answer_multiply_3.GiveElement(number_element), check_answer_multiply_3.GiveElement(number_element), 0.0001);
    }
    for(auto number_element = 0; number_element < answer_multiply_4.GiveSize(); ++number_element){
        ASSERT_NEAR(answer_multiply_4.GiveElement(number_element), check_answer_multiply_4.GiveElement(number_element), 0.0001);
    }
    for(auto number_element = 0; number_element < answer_multiply_5.GiveSize(); ++number_element){
        ASSERT_NEAR(answer_multiply_5.GiveElement(number_element), check_answer_multiply_5.GiveElement(number_element), 0.0001);
    }
    for(auto number_element = 0; number_element < answer_minus_5_6.GiveSize(); ++number_element){
        ASSERT_NEAR(answer_minus_5_6.GiveElement(number_element), check_answer_minus_5_6.GiveElement(number_element), 0.0001);
    }
    for(auto number_element = 0; number_element < answer_multiply_6.GiveSize(); ++number_element){
        ASSERT_NEAR(answer_multiply_6.GiveElement(number_element), check_answer_multiply_6.GiveElement(number_element), 0.001);
    }
}