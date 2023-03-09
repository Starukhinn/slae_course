#include "vector_matrix.h"


vector<float> operator*(const float &number, const vector<float> &numbers){
    vector<float> new_vector;
    new_vector.reserve(numbers.size());
    for(size_t number_element = 0; number_element < numbers.size(); ++number_element){
        new_vector.push_back(numbers[number_element] * number);
    }
    return new_vector;
}

vector<float> operator/(const vector<float> &numbers, const float &number){
    vector<float> new_vector;
    new_vector.reserve(numbers.size());
    for(size_t number_element = 0; number_element < numbers.size(); ++number_element){
        new_vector.push_back(numbers[number_element] / number);
    }
    return new_vector;
}

vector<float> operator+(const vector<float> &first_vector, const vector<float> &second_vector){
    vector<float> new_vector;
    for(int number_element = 0; number_element < first_vector.size(); ++number_element){
        float new_element = first_vector[number_element] + second_vector[number_element];
        new_vector.push_back(new_element);
    }
    return new_vector;
}

vector<float> operator-(const vector<float> &first_vector, const vector<float> &second_vector){
    vector<float> new_vector;
    for(int number_element = 0; number_element < first_vector.size(); ++number_element){
        float new_element = first_vector[number_element]- second_vector[number_element];
        new_vector.push_back(new_element);
    }
    return new_vector;
}

float operator*(const vector<float> &first_vector, const vector<float> &second_vector){
    float new_element = 0;
    for(int number_element = 0; number_element < first_vector.size(); ++number_element){
        new_element += first_vector[number_element] * second_vector[number_element];
    }
    return new_element;
}

float GiveVectorLength(const vector<float> &vector){
    return sqrt(vector * vector);
}