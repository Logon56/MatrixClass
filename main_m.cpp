#include <iostream>
#include "Matrix.h"
using namespace std;
int main()
{
    Matrix<int> mat(3, 3, 3);
    cout << "mat до применения удаления столбцов" << endl;
    for (int i = 0; i < mat.size().first; i++)
    {
        for (int j = 0; j < mat.size().second; j++)
        {
            cout << mat(i, j) << " ";
        }
        cout << endl;
    }
    mat.removeColumns(2); // Удяляем 3 столбца
    cout << "mat после удаления" << endl;
    for (int i = 0; i < mat.size().first; i++)
    {
        for (int j = 0; j < mat.size().second; j++)
        {
            cout << mat(i, j) << " ";
        }
        cout << endl;
    }
}