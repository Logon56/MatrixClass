# MatrixClass
**Класс Matrix** - класс, реализующий работу с таким математическим объектом как матрицы.
Для удобной работы в классе определены различные методы и их перегрузки (о [методах рассказано ниже]()). В дальнейшем будут добавлятся новые методы и улучаться старые. Matrix является шаблоным классом и удобен для таких типов, как *int, double, long, short, float и похожие*.
Данный проект не заброшен, заходите по чаще и следите за обновлениями😊
## Работа с Matrix
### Установка
Чтобы начать работу с матрицами, необходимо скачать файл Matrix.h и в `#include` указать полный или относительный путь до файла. Наприме, допустип есть папка *MyProject*, в ней содержится папка *Matrix*, тогда подключение матриц будет выглядеть так: `#include "Myproject\Matrix\Matrix.h"`.
### Создание объекта
Для создание объекта, в классе объявлены и определенны несколько конструкторов:

```cpp
Matrix() // Конструктор по умолчанию

Matrix(int rows, int columns, const T value = T()); // rows и columns - количество строк и столбцов, value - значение заполнения матрицы

Matrix(const Matrix<T> &mat); // Конструктор копирования

Matrix(const pair<int, int> size, const T value = T()); // size.first - строки, size.second - столбцы
```

<details>
<summary><strong>Пример</strong></summary>
    
```cpp
#include "Matrix.h"
int main()
{
    Matrix<int> mat1;
    Matrix<int> mat2(3, 3, 3);
    Matrix<int> mat3(mat2);
    Matrix<int> mat4(pair<int, int>(3, 3), 4);
    return 0;
}
```
</details>

### Доступ к элементам
Для доступа к элементам в класса Matrix перегружен оператор `()`:

```cpp
T &operator()(int row, int column) //Перегрузка оператора ()
```
С помощью данного оператора удобно заполнять и выводить матрицы.
<details>
<summary>Приме заполнения и вывода патрицы</summary>

```cpp
#include <iostream>
#include "Matrix.h"
using namespace std;
int main()
{
    int rows = 3;
    int columns = 3;
    Matrix<int> mat1(rows, columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> mat1(i, j);
        }
    }
    cout << "Матрица mat1:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << mat1(i, j) << " ";
        }
        cout << endl;
    }
    return 0;
}
```

<details>
<summary>Входные данные</summary>
    
1 2 3 4 5 6 7 8 9

</details>

<details>
<summary>Вывод матрицы</summary>
    
1 2 3
4 5 6
7 8 9

</details>
</details>


