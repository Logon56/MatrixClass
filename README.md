Class Matrix (v 1.0)
Класс Matrix — это класс, реализующий работу с таким математическим объектом, как матрицы.
Для удобной работы в классе определены различные методы и их перегрузки. В дальнейшем будут добавляться новые методы и улучшаться существующие. Matrix является шаблонным классом и предназначен для работы с такими типами, как int, double, long, short, float и подобными.
Этот проект активно развивается — заходите чаще и следите за обновлениями! 😊

Работа с Matrix
Установка
Чтобы начать работу с матрицами, необходимо скачать файл Matrix.h и в директиве #include указать полный или относительный путь до файла. Например, если есть папка MyProject, содержащая папку Matrix, подключение будет выглядеть так:

cpp
#include "MyProject/Matrix/Matrix.h"
Создание объекта
В классе объявлены и определены несколько конструкторов:

cpp
Matrix() // Конструктор по умолчанию

Matrix(int rows, int columns, const T value = T()); // rows и columns — количество строк и столбцов, value — значение для заполнения матрицы

Matrix(const Matrix<T> &mat); // Конструктор копирования

Matrix(const pair<int, int> size, const T value = T()); // size.first — строки, size.second — столбцы
<details> <summary><strong>Пример создания объектов</strong></summary>
cpp
#include "Matrix.h"
int main() {
    Matrix<int> mat1;
    Matrix<int> mat2(3, 3, 3);
    Matrix<int> mat3(mat2);
    Matrix<int> mat4(pair<int, int>(3, 3), 4);
    return 0;
}
</details>
Доступ к элементам
Для доступа к элементам в классе Matrix перегружен оператор ():

cpp
T &operator()(int row, int column); // Перегрузка оператора ()
Этот оператор удобен для заполнения и вывода матриц.

<details> <summary><strong>Пример заполнения и вывода матрицы</strong></summary>
cpp
#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
    int rows = 3;    // Количество строк
    int columns = 3; // Количество столбцов
    Matrix<int> mat1(rows, columns);

    // Заполнение матрицы
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> mat1(i, j);
        }
    }

    // Вывод матрицы
    cout << "Матрица mat1:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << mat1(i, j) << " ";
        }
        cout << endl;
    }
    return 0;
}
<details> <summary><b>Входные данные</b></summary>
1 2 3 4 5 6 7 8 9
</details><details> <summary><b>Вывод в консоль</b></summary>
Матрица mat1:
1 2 3 
4 5 6 
7 8 9 
</details> </details>
Размеры: как узнать, установить или изменить
Для работы с размерами матрицы определены несколько методов.

Получение размеров
Метод size() возвращает текущие размеры матрицы:

cpp
pair<int, int> size();
Возвращаемый объект pair содержит:

first — количество строк,

second — количество столбцов.

<details> <summary><strong>Пример работы <code>size()</code></strong></summary>
cpp
#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
    Matrix<double> mat1(3, 3);
    pair<int, int> size = mat1.size();
    cout << "Количество строк в mat1: " << size.first 
         << "\nКоличество столбцов в mat1: " << size.second << endl;
    return 0;
}
<details> <summary><b>Вывод в консоль</b></summary>
Количество строк в mat1: 3
Количество столбцов в mat1: 3
</details> </details>
Изменение размеров
Методы setSize() позволяют изменить размеры матрицы:

cpp
void setSize(int rows, int columns); // rows — строки, columns — столбцы
void setSize(const pair<int, int> new_size); // new_size.first — строки, new_size.second — столбцы
При изменении размеров:

Если новые размеры больше текущих, добавляются строки/столбцы, заполненные значениями по умолчанию.

Если новые размеры меньше, лишние строки и столбцы удаляются справа и снизу.

<details> <summary><strong>Пример работы <code>setSize</code></strong></summary>
cpp
#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
    Matrix<float> mat1(5, 5, 1); // Матрица 5×5, заполненная единицами
    Matrix<float> mat2;          // Пустая матрица

    // Установка размеров 2×2
    mat2.setSize(pair<int, int>(2, 2));
    cout << "mat2 после изменения размеров (2×2):" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << mat2(i, j) << " ";
        }
        cout << endl;
    }

    // Изменение размеров mat1 с 5×5 до 3×7
    cout << "\nmat1 до изменения размеров (5×5):" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << mat1(i, j) << " ";
        }
        cout << endl;
    }

    mat1.setSize(3, 7);
    cout << "\nmat1 после изменения размеров (3×7):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            cout << mat1(i, j) << " ";
        }
        cout << endl;
    }
    return 0;
}
<details> <summary><b>Вывод в консоль</b></summary>
mat2 после изменения размеров (2×2):
0 0 
0 0 

mat1 до изменения размеров (5×5):
1 1 1 1 1 
1 1 1 1 1 
1 1 1 1 1 
1 1 1 1 1 
1 1 1 1 1 

mat1 после изменения размеров (3×7):
1 1 1 1 1 0 0 
1 1 1 1 1 0 0 
1 1 1 1 1 0 0 
</details> </details>
Арифметические операторы и операторы присваивания
Для удобной работы перегружены операторы:

Арифметические: +, -, *

Присваивания: =, +=, -=, *=

cpp
Matrix<T> operator+(const Matrix<T> &mat) const;
Matrix<T> operator-(const Matrix<T> &mat) const;
Matrix<T> operator*(const Matrix<T> &mat) const;
Matrix<T> operator*(const T scalar) const; // Умножение на скаляр

Matrix<T>& operator=(const Matrix<T> &mat);
Matrix<T>& operator+=(const Matrix<T> &mat);
Matrix<T>& operator-=(const Matrix<T> &mat);
Matrix<T>& operator*=(const Matrix<T> &mat);
Matrix<T>& operator*=(const T scalar); // Умножение на скаляр с присваиванием
<details> <summary><strong>Пример работы операторов</strong></summary>
cpp
#include <iostream>
#include "Matrix.h"
using namespace std;

template <typename T>
void printMatrix(const Matrix<T> &mat, const string &name = "") {
    auto size = mat.size();
    cout << "Матрица " << name << " (" << size.first << "×" << size.second << "):\n";
    for (int i = 0; i < size.first; i++) {
        for (int j = 0; j < size.second; j++) {
            cout << mat(i, j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    Matrix<int> A(2, 2, 1);
    Matrix<int> B(2, 2, 2);

    // Сложение
    Matrix<int> C = A + B;
    printMatrix(C, "A + B");

    // Умножение на скаляр
    Matrix<int> D = A * 3;
    printMatrix(D, "A * 3");

    // Умножение матриц
    Matrix<int> E = A * B;
    printMatrix(E, "A * B");

    return 0;
}
<details> <summary><b>Вывод в консоль</b></summary>
Матрица A + B (2×2):
3 3 
3 3 

Матрица A * 3 (2×2):
3 3 
3 3 

Матрица A * B (2×2):
2 2 
2 2 
</details> </details>
Заключение
Это основные возможности класса Matrix. Ниже перечислены все реализованные методы с примерами их использования.
Спасибо за внимание! Следите за обновлениями!

<details> <a id="PublicMetods"></a> <summary><h2>Публичные методы</h2></summary> </details>
