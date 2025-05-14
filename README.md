# Class Matrix(v 1.0)
**Класс Matrix** - класс, реализующий работу с таким математическим объектом как матрицы.
Для удобной работы в классе определены различные методы и их перегрузки (о [методах рассказано ниже]()). В дальнейшем будут добавлятся новые методы и улучаться старые. Matrix является шаблоным классом и удобен для таких типов, как *int, double, long, short, float и похожие*.
Данный проект не заброшен, заходите по чаще и следите за обновлениями😊

## Работа с Matrix
### Установка
Чтобы начать работу с матрицами, необходимо скачать файл Matrix.h и в `#include` указать полный или относительный путь до файла. Наприме, допустип есть папка *MyProject*, в ней содержится папка *Matrix*, тогда подключение матриц будет выглядеть так: `#include "Myproject\Matrix\Matrix.h"`.

### Создание объекта
Для создание объекта, в классе объявлены и определенны несколько конструкторов:

```h
Matrix() // Конструктор по умолчанию

Matrix(int rows, int columns, const T value = T()); // rows и columns - количество строк и столбцов, value - значение заполнения матрицы

Matrix(const Matrix<T> &mat); // Конструктор копирования

Matrix(const pair<int, int> size, const T value = T()); // size.first - строки, size.second - столбцы
```

<details>
<summary><strong>Пример создание объектов</strong></summary>
    
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

```h
T &operator()(int row, int column) //Перегрузка оператора ()
```
С помощью данного оператора удобно заполнять и выводить матрицы.
<details>
<summary><strong>Приме заполнения и вывода матрицы</strong></summary>

```cpp
#include <iostream>
#include "Matrix.h"
using namespace std;
int main()
{
    int rows = 3; // Количество строк
    int columns = 3; // Количество столбцов
    Matrix<int> mat1(rows, columns);
    for (int i = 0; i < rows; i++) //Проход по строкам
    {
        for (int j = 0; j < columns; j++) //Проход по столбцам
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
<summary><b>Входные данные</b></summary>
    
`1 2 3 4 5 6 7 8 9`

</details>

<details>
<summary><b>Выходные данные</b></summary>
    
```
Матрица mat1:
1 2 3
4 5 6
7 8 9
```
</details>
</details>

### Размеры: как узнать и установить или изменить
Для работы с размерами матрицы определенны несколько методов. 
Начнем с того, как узнать размеры матрицы. Для этого в классе определен метод `size()`

```h
pair<int, int> size();
```
Он возвращает структуру `pair`, у которой `first` - количество строк, `second` - количество столбцов.

<details>
<summary><strong>Пример работы <code>size()</code></strong></summary>

```cpp
#include <iostream>
#include "Matrix.h"
int main()
{
    Matrix<double> mat1(3, 3);
    pair<int, int> size = mat1.size();
    cout << "Количество строк в mat1 - " << size.first << ". Количество столбцов в mat1 - " << size.second << endl;
    return 0;
}
```
<details>
<summary><b>Вывод в консоль</b></summary>

`Количество строк в mat1 - 3. Количество столбцов в mat1 - 3`
</details>
</details>


