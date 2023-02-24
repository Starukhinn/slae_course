#include "vector_matrix.h"

vector<float> VectorMatrix::GiveVector() const {
    return numbers_;
}
vector<float> VectorMatrix::MultiplicationByNumber(const float& number) {
    vector<float> new_vector;
    for(auto element: numbers_){
        element *= number;
        new_vector.push_back(element);
    }
    return new_vector;
}
float VectorMatrix::GiveElement(const int& number_element) const {
    return numbers_[number_element];
}
VectorMatrix::VectorMatrix() {
    numbers_ ={};
}
VectorMatrix::VectorMatrix(const vector<float> &elements) {
    numbers_ = elements;
}

VectorMatrix operator+(const VectorMatrix &first_vector, const VectorMatrix &second_vector){
    vector<float> new_vector;
    for(int number_element = 0; number_element < first_vector.GiveVector().size(); ++number_element){
        float new_element = first_vector.GiveElement(number_element) + second_vector.GiveElement(number_element);
        new_vector.push_back(new_element);
    }
    return {new_vector};
}

VectorMatrix operator-(const VectorMatrix &first_vector, const VectorMatrix &second_vector){
    vector<float> new_vector;
    for(int number_element = 0; number_element < first_vector.GiveVector().size(); ++number_element){
        float new_element = first_vector.GiveElement(number_element) - second_vector.GiveElement(number_element);
        new_vector.push_back(new_element);
    }
    return {new_vector};
}

float operator*(const VectorMatrix &first_vector, const VectorMatrix &second_vector){
    float new_element = 0;
    for(int number_element = 0; number_element < first_vector.GiveVector().size(); ++number_element){
        new_element += first_vector.GiveElement(number_element) * second_vector.GiveElement(number_element);
    }
    return new_element;
}