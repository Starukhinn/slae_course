#include "/Users/dmitrystarukhin/slae_course/ThreeDiagonalMatrix/progonka.h"
#include <iostream>

int main() {
    try {
        int number_rows;
        cin >> number_rows;
        ThreeDiagonalMatrix matrix = MakeMatrix(number_rows);
        matrix.Display();
        NumbersColumn free_members_column(number_rows);
        NumbersColumn unknown_column(number_rows);
        free_members_column = MakeNumbersColumn(number_rows);
        cout << '\n';
        free_members_column.Display();
        NumbersColumn answer_column = Progonka(matrix, free_members_column);
        cout << "\n";
        answer_column.Display();
    }
    catch (int a) {
        std::cerr << a << "is big number";
    }
    return 0;
}