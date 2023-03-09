#include "vector_matrix.h"


vector<double> operator*(const double &number, const vector<double> &numbers){
    vector<double> new_vector;
    new_vector.reserve(numbers.size());
    for(size_t number_element = 0; number_element < numbers.size(); ++number_element){
        new_vector.push_back(numbers[number_element] * number);
    }
    return new_vector;
}

vector<double> operator/(const vector<double> &numbers, const double &number){
    vector<double> new_vector;
    new_vector.reserve(numbers.size());
    for(size_t number_element = 0; number_element < numbers.size(); ++number_element){
        new_vector.push_back(numbers[number_element] / number);
    }
    return new_vector;
}

vector<double> operator+(const vector<double> &first_vector, const vector<double> &second_vector){
    vector<double> new_vector;
    for(int number_element = 0; number_element < first_vector.size(); ++number_element){
        double new_element = first_vector[number_element] + second_vector[number_element];
        new_vector.push_back(new_element);
    }
    return new_vector;
}

vector<double> operator-(const vector<double> &first_vector, const vector<double> &second_vector){
    vector<double> new_vector;
    for(int number_element = 0; number_element < first_vector.size(); ++number_element){
        double new_element = first_vector[number_element]- second_vector[number_element];
        new_vector.push_back(new_element);
    }
    return new_vector;
}

double operator*(const vector<double> &first_vector, const vector<double> &second_vector){
    double new_element = 0;
    for(int number_element = 0; number_element < first_vector.size(); ++number_element){
        new_element += first_vector[number_element] * second_vector[number_element];
    }
    return new_element;
}

double GiveVectorLength(const vector<double> &vector){
    return sqrt(vector * vector);
}