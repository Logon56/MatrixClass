#include <iostream>
#include "Matrix.h"

using namespace std;

void printMatrix(const Matrix<int> &mat)
{
    auto size = mat.size();
    for (int i = 0; i < size.first; i++)
    {
        for (int j = 0; j < size.second; j++)
        {
            cout << mat(i, j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void star_test()
{
    // Тестирование конструкторов
    cout << "Testing constructors:" << endl;
    Matrix<int> mat1(2, 3, 5); // Конструктор с размерами и значением
    cout << "mat1 (2x3 filled with 5):" << endl;
    printMatrix(mat1);

    Matrix<int> mat2(make_pair(3, 2), 2); // Конструктор с pair и значением
    cout << "mat2 (3x2 filled with 2):" << endl;
    printMatrix(mat2);

    Matrix<int> mat3(mat1); // Конструктор копирования
    cout << "mat3 (copy of mat1):" << endl;
    printMatrix(mat3);

    Matrix<int> mat4; // Конструктор по умолчанию
    mat4 = mat2;      // Оператор присваивания
    cout << "mat4 (assigned from mat2):" << endl;
    printMatrix(mat4);

    // Тестирование операторов
    cout << "Testing operators:" << endl;
    Matrix<int> mat_sum = mat1 + mat3; // Оператор +
    cout << "mat1 + mat3:" << endl;
    printMatrix(mat_sum);

    Matrix<int> mat_diff = mat1 - mat3; // Оператор -
    cout << "mat1 - mat3 (should be all zeros):" << endl;
    printMatrix(mat_diff);

    Matrix<int> mat_prod = mat1 * mat2; // Оператор * (умножение матриц)
    cout << "mat1 * mat2:" << endl;
    printMatrix(mat_prod);

    Matrix<int> mat_scalar = mat1 * 3; // Оператор * (умножение на скаляр)
    cout << "mat1 * 3:" << endl;
    printMatrix(mat_scalar);

    // Тестирование составных операторов
    cout << "Testing compound operators:" << endl;
    mat1 += mat3; // Оператор +=
    cout << "mat1 += mat3:" << endl;
    printMatrix(mat1);

    mat1 -= mat3; // Оператор -=
    cout << "mat1 -= mat3 (should return to original):" << endl;
    printMatrix(mat1);

    mat1 *= 2; // Оператор *= (умножение на скаляр)
    cout << "mat1 *= 2:" << endl;
    printMatrix(mat1);

    Matrix<int> mat5(3, 3, 1);
    Matrix<int> mat6(3, 3, 2);
    mat5 *= mat6; // Оператор *= (умножение матриц)
    cout << "mat5 *= mat6:" << endl;
    printMatrix(mat5);

    // Тестирование методов
    cout << "Testing methods:" << endl;
    cout << "mat1 size: " << mat1.size().first << "x" << mat1.size().second << endl;

    mat1.fill(10); // Метод fill
    cout << "mat1 after fill(10):" << endl;
    printMatrix(mat1);

    // Тестирование доступа к элементам
    cout << "Testing element access:" << endl;
    mat1(1, 1) = 7;
    cout << "mat1(1,1) = 7:" << endl;
    printMatrix(mat1);
}
void test_add()
{
    // Создаём матрицу 2x3 и заполняем её значениями 1
    Matrix<int> mat(2, 3, 1);
    cout << "Initial matrix:" << endl;
    printMatrix(mat);

    // Добавляем 2 строки
    mat.addRows(2);
    cout << "After adding 2 rows:" << endl;
    printMatrix(mat);

    // Добавляем 3 столбца
    mat.addColumns(3);
    cout << "After adding 3 columns:" << endl;
    printMatrix(mat);

    // Создаём другую матрицу 3x2 с разными значениями
    Matrix<int> mat2(3, 2);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            mat2(i, j) = i * 2 + j + 1;
        }
    }
    cout << "Second matrix:" << endl;
    printMatrix(mat2);

    // Добавляем 1 строку и 1 столбец
    mat2.addRows(1);
    mat2.addColumns(1);
    cout << "Second matrix after adding 1 row and 1 column:" << endl;
    printMatrix(mat2);
}
void test_remove()
{
    cout << "=== Testing removeRows and removeColumns ===" << endl;

    // Создаем матрицу 4x5 и заполняем её значениями от 1 до 20
    Matrix<int> mat(4, 5);
    int counter = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            mat(i, j) = counter++;
        }
    }

    cout << "Initial matrix:" << endl;
    printMatrix(mat);

    // Удаляем 2 строки
    mat.removeRows(2);
    cout << "After removing 2 rows:" << endl;
    printMatrix(mat);

    // Удаляем 3 столбца
    mat.removeColumns(3);
    cout << "After removing 3 columns:" << endl;
    printMatrix(mat);

    // Тест 2: Попытка удалить больше строк/столбцов, чем есть
    Matrix<int> smallMat(2, 2, 5);
    cout << "Small matrix before removal:" << endl;
    printMatrix(smallMat);

    // Удаляем 1 строку (останется 1 строка)
    smallMat.removeRows(1);
    cout << "After removing 1 row:" << endl;
    printMatrix(smallMat);

    // Удаляем 1 столбец (матрица станет 1x1)
    smallMat.removeColumns(1);
    cout << "After removing 1 column:" << endl;
    printMatrix(smallMat);

    cout << "=== Removal tests completed ===" << endl
         << endl;
}
void test_setSize()
{
    cout << "=== Testing setSize ===" << endl;

    // Тест 1: Уменьшение размера матрицы
    Matrix<int> mat1(4, 5);
    cout << "Initial matrix 1 (4x5):" << endl;
    printMatrix(mat1);

    mat1.setSize(2, 3); // Уменьшаем до 2x3
    cout << "After setSize(2, 3):" << endl;
    printMatrix(mat1);

    // Тест 2: Увеличение размера матрицы
    Matrix<int> mat2(2, 2, 5); // 2x2, заполнена 5
    cout << "Initial matrix 2 (2x2):" << endl;
    printMatrix(mat2);

    mat2.setSize(3, 4); // Увеличиваем до 3x4
    cout << "After setSize(3, 4):" << endl;
    printMatrix(mat2);

    // Тест 3: Изменение только строк
    Matrix<int> mat3(3, 3, 10); // 3x3, заполнена 10
    cout << "Initial matrix 3 (3x3):" << endl;
    printMatrix(mat3);

    mat3.setSize(5, 3); // Увеличиваем строки до 5
    cout << "After setSize(5, 3):" << endl;
    printMatrix(mat3);

    // Тест 4: Изменение только столбцов
    Matrix<int> mat4(2, 2, 7); // 2x2, заполнена 7
    cout << "Initial matrix 4 (2x2):" << endl;
    printMatrix(mat4);

    mat4.setSize(2, 4); // Увеличиваем столбцы до 4
    cout << "After setSize(2, 4):" << endl;
    printMatrix(mat4);

    // Тест 5: Очистка матрицы (установка размера 0x0)
    Matrix<int> mat5(2, 2, 3);
    cout << "Initial matrix 5 (2x2):" << endl;
    printMatrix(mat5);

    mat5.setSize(0, 0);
    cout << "After setSize(0, 0):" << endl;
    printMatrix(mat5);

    cout << "=== setSize tests completed ===" << endl
         << endl;
}
int main()
{
    // star_test();
    // test_add();
    // test_remove();
    // test_setSize();
    return 0;
}