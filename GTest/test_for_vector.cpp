#include "gtest/gtest.h"
#include "../solving/Vector/vector_matrix.h"

TEST(Vector, Operations) {
    vector<float> null_vector({0.0, 0.0, 0.0, 0.0, 0.0, 0.0});
    vector<float> vector1({1.08, 2.802, 3.949, 4.0, 0.799, -92.9});
    vector<float> vector2({0.77, 2.33, 0.99, -5.089, 2.13, -0.9});
    vector<float> vector3({11.23, 23.11, 33.77, 54.995, 88.8594, 99.494, 22.49959, -1.9});
    vector<float> vector4({-11.23, 3.09, 56.86, 9.11, -4.45, 213.888, 31.0, -1.9});
    vector<float> vector5({14.9, 21.99, -83.83, 11.7, 0.0, -1.111});
    vector<float> vector6({-33.3, 34.88, 11.2, -11.7, 100.77, 1.091});


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

    vector<float> answer_plus_0_1 = null_vector + vector1;
    vector<float> check_answer_plus_0_1 = {1.08, 2.802, 3.949, 4.0, 0.799, -92.9};
    vector<float> answer_plus_0_2 = null_vector + vector2;
    vector<float> answer_plus_2_0 = vector2 + null_vector;
    vector<float> check_answer_plus_0_2 = {0.77, 2.33, 0.99, -5.089, 2.13, -0.9};
    vector<float> answer_plus_3_4 = vector3 + vector4;
    vector<float> answer_plus_4_3 = vector4 + vector3;
    vector<float> check_answer_plus_3_4 = {0.0, 26.2, 90.63, 64.10499999999999, 84.40939999999999, 313.382, 53.49959, -3.8};
    vector<float> answer_plus_5_6 = vector5 + vector6;
    vector<float> answer_plus_6_5 = vector6 + vector5;
    vector<float> check_answer_plus_5_6= {-18.4, 56.870000000000005, -72.63, 0.0, 100.77, -0.020000000000000018};

    vector<float> answer_minus_0_1 = null_vector - vector1;
    vector<float> check_answer_minus_0_1 = {-1.08, -2.802, -3.949, -4.0, -0.799, 92.9};
    vector<float> answer_minus_0_2 = null_vector - vector2;
    vector<float> check_answer_minus_0_2 = {-0.77, -2.33, -0.99, 5.089, -2.13, 0.9};
    vector<float> answer_minus_2_0 = vector2 - null_vector;
    vector<float> check_answer_minus_2_0 = {0.77, 2.33, 0.99, -5.089, 2.13, -0.9};
    vector<float> answer_minus_3_4 = vector3 - vector4;
    vector<float> check_answer_minus_3_4 = {22.46, 20.02, -23.089999999999996, 45.885, 93.3094, -114.394, -8.500409999999999, 0.0};
    vector<float> answer_minus_4_3 = vector4 - vector3;
    vector<float> check_answer_minus_4_3 = {-22.46, -20.02, 23.089999999999996, -45.885, -93.3094, 114.394, 8.500409999999999, 0.0};
    vector<float> answer_minus_5_6 = vector5 - vector6;
    vector<float> check_answer_minus_5_6 = {48.199999999999996, -12.890000000000004, -95.03, 23.4, -100.77, -2.202};
    vector<float> answer_minus_6_5 = vector6 - vector5;
    vector<float> check_answer_minus_6_5 = {-48.199999999999996, 12.890000000000004, 95.03, -23.4, 100.77, 2.202};

    vector<float> answer_multiply_0 = 3.9 * null_vector;
    vector<float> check_answer_multiply_0 = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    vector<float> answer_multiply_2 = 0.0 * vector2;
    vector<float> check_answer_multiply_2 = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    vector<float> answer_multiply_3 = -6.5 * vector3;
    vector<float> check_answer_multiply_3 = {-72.995, -150.215, -219.50500000000002, -357.4675, -577.5861, -646.711, -146.24733500000002, 12.35};
    vector<float> answer_multiply_4 = -1.0 * vector4;
    vector<float> check_answer_multiply_4 = {11.23, -3.09, -56.86, -9.11, 4.45, -213.888, -31.0, 1.9};
    vector<float> answer_multiply_5 = 3.56 * vector5;
    vector<float> check_answer_multiply_5 = {53.044000000000004, 78.28439999999999, -298.4348, 41.652, 0.0, -3.9551600000000002};
    vector<float> answer_multiply_6 = -34.8885 * vector6;
    vector<float> check_answer_multiply_6 = {1161.78705, -1216.9108800000001, -390.7512, 408.19545, -3515.714145, -38.0633535};





    ASSERT_NEAR(answer_multiply_0_1, check_answer_multiply_0_1, 0.0001);
    ASSERT_NEAR(answer_multiply_0_2, check_answer_multiply_0_2, 0.0001);
    ASSERT_NEAR(answer_multiply_1_2, check_answer_multiply_1_2, 0.0001);
    ASSERT_NEAR(answer_multiply_2_1, check_answer_multiply_1_2, 0.0001);
    ASSERT_NEAR(answer_multiply_3_4, check_answer_multiply_3_4, 0.01);
    ASSERT_NEAR(answer_multiply_4_3, check_answer_multiply_3_4, 0.01);
    ASSERT_NEAR(answer_multiply_5_6, check_answer_multiply_5_6, 0.1);
    ASSERT_NEAR(answer_multiply_6_5, check_answer_multiply_5_6, 0.1);


    for(auto number_element = 0; number_element < answer_plus_0_1.size(); ++number_element){
        ASSERT_NEAR(answer_plus_0_1[number_element], check_answer_plus_0_1[number_element], 0.0001);
    }
    for(auto number_element = 0; number_element < answer_plus_0_2.size(); ++number_element){
        ASSERT_NEAR(answer_plus_0_2[number_element], check_answer_plus_0_2[number_element], 0.0001);
    }
    for(auto number_element = 0; number_element < answer_plus_0_2.size(); ++number_element){
        ASSERT_NEAR(answer_plus_2_0[number_element], check_answer_plus_0_2[number_element], 0.0001);
    }
    for(auto number_element = 0; number_element < answer_plus_3_4.size(); ++number_element){
        ASSERT_NEAR(answer_plus_3_4[number_element], check_answer_plus_3_4[number_element], 0.0001);
    }
    for(auto number_element = 0; number_element < answer_plus_3_4.size(); ++number_element){
        ASSERT_NEAR(answer_plus_4_3[number_element], check_answer_plus_3_4[number_element], 0.0001);
    }
    for(auto number_element = 0; number_element < answer_plus_5_6.size(); ++number_element){
        ASSERT_NEAR(answer_plus_5_6[number_element], check_answer_plus_5_6[number_element], 0.0001);
    }
    for(auto number_element = 0; number_element < answer_plus_5_6.size(); ++number_element){
        ASSERT_NEAR(answer_plus_6_5[number_element], check_answer_plus_5_6[number_element], 0.0001);
    }


    for(auto number_element = 0; number_element < answer_minus_0_1.size(); ++number_element){
        ASSERT_NEAR(answer_minus_0_1[number_element], check_answer_minus_0_1[number_element], 0.0001);
    }
    for(auto number_element = 0; number_element < answer_minus_0_2.size(); ++number_element){
        ASSERT_NEAR(answer_minus_0_2[number_element], check_answer_minus_0_2[number_element], 0.0001);
    }
    for(auto number_element = 0; number_element < answer_minus_2_0.size(); ++number_element){
        ASSERT_NEAR(answer_minus_2_0[number_element], check_answer_minus_2_0[number_element], 0.0001);
    }
    for(auto number_element = 0; number_element < answer_minus_3_4.size(); ++number_element){
        ASSERT_NEAR(answer_minus_3_4[number_element], check_answer_minus_3_4[number_element], 0.0001);
    }
    for(auto number_element = 0; number_element < answer_minus_4_3.size(); ++number_element){
        ASSERT_NEAR(answer_minus_4_3[number_element], check_answer_minus_4_3[number_element], 0.0001);
    }
    for(auto number_element = 0; number_element < answer_minus_5_6.size(); ++number_element){
        ASSERT_NEAR(answer_minus_5_6[number_element], check_answer_minus_5_6[number_element], 0.0001);
    }
    for(auto number_element = 0; number_element < answer_minus_6_5.size(); ++number_element){
        ASSERT_NEAR(answer_minus_6_5[number_element], check_answer_minus_6_5[number_element], 0.0001);
    }


    for(auto number_element = 0; number_element < answer_multiply_0.size(); ++number_element){
        ASSERT_NEAR(answer_multiply_0[number_element], check_answer_multiply_0[number_element], 0.0001);
    }
    for(auto number_element = 0; number_element < answer_multiply_2.size(); ++number_element){
        ASSERT_NEAR(answer_multiply_2[number_element], check_answer_multiply_2[number_element], 0.0001);
    }
    for(auto number_element = 0; number_element < answer_multiply_3.size(); ++number_element){
        ASSERT_NEAR(answer_multiply_3[number_element], check_answer_multiply_3[number_element], 0.0001);
    }
    for(auto number_element = 0; number_element < answer_multiply_4.size(); ++number_element){
        ASSERT_NEAR(answer_multiply_4[number_element], check_answer_multiply_4[number_element], 0.0001);
    }
    for(auto number_element = 0; number_element < answer_multiply_5.size(); ++number_element){
        ASSERT_NEAR(answer_multiply_5[number_element], check_answer_multiply_5[number_element], 0.0001);
    }
    for(auto number_element = 0; number_element < answer_minus_5_6.size(); ++number_element){
        ASSERT_NEAR(answer_minus_5_6[number_element], check_answer_minus_5_6[number_element], 0.0001);
    }
    for(auto number_element = 0; number_element < answer_multiply_6.size(); ++number_element){
        ASSERT_NEAR(answer_multiply_6[number_element], check_answer_multiply_6[number_element], 0.001);
    }
}