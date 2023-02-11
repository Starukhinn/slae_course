#include "numbers_column.h"

NumbersColumn::NumbersColumn(const int &number_elements){
    numbers_ = {};
    numbers_.resize(number_elements, 0);
}

NumbersColumn::NumbersColumn(const vector<double> &column){
    numbers_ = column;
}

void NumbersColumn::Display() const {
    PrintNumbers();
}

void NumbersColumn::PrintNumbers() const{
    for (const auto number: numbers_) {
        cout << number << "\n";
    }
}

void NumbersColumn::ChangeElement(const int &number_element, const double &element) {
    ReplaceElement(number_element, element);
}

void NumbersColumn::ReplaceElement(const int &number_element, const double &element) {
    numbers_.at(number_element) = element;
}

void NumbersColumn::operator=(const NumbersColumn& elements){
    numbers_ = elements.numbers_;
}

double NumbersColumn::GiveElement(const int number_element) const{
    return numbers_.at(number_element);
}

vector<double> NumbersColumn::GiveColumn() const {
    return numbers_;
}

bool operator==(const NumbersColumn &first_column, const NumbersColumn &second_column){
    if(first_column.GiveColumn() == second_column.GiveColumn()){
        return true;
    }
    return false;
}

NumbersColumn MakeNumbersColumn(const int& column_size){
    NumbersColumn numbers(column_size);
    for(auto number_element = 0; number_element < column_size; ++number_element) {
        double element_of_column;
        cin >> element_of_column;
        numbers.ChangeElement(number_element, element_of_column);
    }
    return numbers;
}