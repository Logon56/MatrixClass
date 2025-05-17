# Class Matrix(v 1.0)
**Класс Matrix** - класс, реализующий работу с таким математическим объектом как матрицы.
Для удобной работы в классе определены различные [методы](#Metods) и их перегрузки. В дальнейшем будут добавлятся новые методы и улучаться старые. Matrix является шаблоным классом и удобен для таких типов, как *int, double, long, short, float и похожие*.
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
<summary><b>Вывод в консоль</b></summary>
    
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
using namespace std;
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

Для задания новых размеров, в классе определен метод `setSize(int rows, int columns)` и его перегрузка.
```h
void setSize(int rows, int columns); // rows - количество строк, columns - количество столбцов

void setSize(const pair<int, int> new_size); // стркуктура pair где first - количество строк, second - количество столбцов
```
При указании новых размеро, данные не куда не деваются. Если новые размеры больше текущих, то к матрицы справо добавляются новые столбы, а снизу - новые строки заполненые значением по умолчанию. Если размеры меньше, то справа и снизу удаляются столбцы и строки соотвественно.

<details>
<summary><strong>Пример работы <code>setSize</code></strong></summary>
    
```cpp
#include <iostream>
#include "Matrix.h"
using namespace std;
int main()
{
    Matrix<float> mat1(5, 5, 1); // Создание матрицы 3*3 заполненый 1
    Matrix<float> mat2;          // Создание пустого объекта
    pair<int, int> size(2, 2);
    mat2.setSize(size); // Задание новых размеро 2*2
    cout << "mat2 после установки новых размеров 2 * 2" << endl;
    for (int i = 0; i < size.first; i++)
    {
        for (int j = 0; j < size.second; j++)
        {
            cout << mat2(i, j) << " ";
        }
        cout << endl;
    }
    cout << "\nmat1 до установки новых размеров" << endl;
    for (int i = 0; i < mat1.size().first; i++)
    {
        for (int j = 0; j < mat1.size().second; j++)
        {
            cout << mat1(i, j) << " ";
        }
        cout << endl;
    }
    mat1.setSize(3, 7); // Устанавливаем новый размер 3*7
    cout << "\nmat1 после установки новых размеров 3 * 7" << endl;
    for (int i = 0; i < mat1.size().first; i++)
    {
        for (int j = 0; j < mat1.size().second; j++)
        {
            cout << mat1(i, j) << " ";
        }
        cout << endl;
    }
}
```
<details>
<summary><b>Вывод в консоль</b></summary>

```
mat2 после установки новых размеров 2 * 2
0 0 
0 0 

mat1 до установки новых размеров   
1 1 1 1 1 
1 1 1 1 1 
1 1 1 1 1 
1 1 1 1 1 
1 1 1 1 1 

mat1 после установки новых размеров 3 * 7
1 1 1 1 1 0 0 
1 1 1 1 1 0 0 
1 1 1 1 1 0 0
```
</details>  
</details>

### Арифметические операторы и операторы присвоения
Для удобной работы с матрицами, в классе перегруженны такие операторы как: `+, -, *, +=, -=, *=, =`.
```h
Matrix<T> &operator=(const Matrix<T> &mat);

Matrix<T> &operator+=(const Matrix<T> &mat);

Matrix<T> &operator-=(const Matrix<T> &mat);

Matrix<T> &operator*=(const Matrix<T> &mat);

Matrix<T> &operator*=(const int mul); //Умножение на число с присваением

Matrix<T> operator+(const Matrix<T> &mat) const;

Matrix<T> operator-(const Matrix<T> &mat) const;

Matrix<T> operator*(const Matrix<T> &mat) const;

Matrix<T> operator*(const int mul) const; //Умножение на число
```
<details>
<summary><strong>Пример работы aрифметических оператор и операторов присвоения</strong></summary>

```cpp
#include <iostream>
#include "Matrix.h"

using namespace std;

template <typename T>
void printMatrix(const Matrix<T> &mat, const string &name = "") //Функция для вывода матрицы
{
    auto size = mat.size();
    if (!name.empty())
    {
        cout << "Матрица " << name << " (" << size.first << "x" << size.second << "):" << endl;
    }
    else
    {
        cout << "Матрица " << size.first << "x" << size.second << ":" << endl;
    }
    for (int i = 0; i < size.first; ++i)
    {
        for (int j = 0; j < size.second; ++j)
        {
            cout << mat(i, j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    Matrix<int> mat1(2, 3, 1); // Создание матрицы 2x3, заполненной единицами
    Matrix<int> mat2(2, 3, 2); // Создание матрицы 2x3, заполненной двойками
    Matrix<int> mat3(3, 2, 3); // Создание матрицы 3x2, заполненной тройками

    cout << "Исходные матрицы:" << endl;
    printMatrix(mat1, "mat1 (2x3, заполнена 1)");
    printMatrix(mat2, "mat2 (2x3, заполнена 2)");
    printMatrix(mat3, "mat3 (3x2, заполнена 3)");

    // Тестирование оператора присваивания
    cout << "\n=== Тестирование оператора присваивания ===" << endl;
    Matrix<int> mat4 = mat1;
    cout << "Матрица после операции присваивания (mat4 = mat1):" << endl;
    printMatrix(mat4, "mat4");

    // Тестирование оператора +=
    cout << "\n=== Тестирование оператора += ===" << endl;
    mat1 += mat2;
    cout << "Матрица после операции += (mat1 += mat2):" << endl;
    printMatrix(mat1, "mat1");

    // Тестирование оператора +
    cout << "\n=== Тестирование оператора + ===" << endl;
    Matrix<int> mat5 = mat1 + mat2;
    cout << "Матрица после операции + (mat5 = mat1 + mat2):" << endl;
    printMatrix(mat5, "mat5");

    // Тестирование оператора -=
    cout << "\n=== Тестирование оператора -= ===" << endl;
    mat1 -= mat2;
    cout << "Матрица после операции -= (mat1 -= mat2):" << endl;
    printMatrix(mat1, "mat1");

    // Тестирование оператора -
    cout << "\n=== Тестирование оператора - ===" << endl;
    Matrix<int> mat6 = mat2 - mat1;
    cout << "Матрица после операции - (mat6 = mat2 - mat1):" << endl;
    printMatrix(mat6, "mat6");

    // Тестирование оператора *= (умножение на скаляр)
    cout << "\n=== Тестирование оператора *= (умножение на скаляр) ===" << endl;
    mat1 *= 3;
    cout << "Матрица после операции *= (mat1 *= 3):" << endl;
    printMatrix(mat1, "mat1");

    // Тестирование оператора * (умножение на скаляр)
    cout << "\n=== Тестирование оператора * (умножение на скаляр) ===" << endl;
    Matrix<int> mat7 = mat1 * 2;
    cout << "Матрица после операции * (mat7 = mat1 * 2):" << endl;
    printMatrix(mat7, "mat7");

    // Тестирование матричного умножения
    cout << "\n=== Тестирование матричного умножения ===" << endl;
    Matrix<int> mat8 = mat2 * mat3;
    cout << "Матрица после матричного умножения (mat8 = mat2 * mat3):" << endl;
    printMatrix(mat8, "mat8");

    // Тестирование оператора *= (матричное умножение)
    cout << "\n=== Тестирование оператора *= (матричное умножение) ===" << endl;
    mat2 *= mat3;
    cout << "Матрица после операции *= (mat2 *= mat3):" << endl;
    printMatrix(mat2, "mat2");

    // Тестирование с другими типами данных
    cout << "\n=== Тестирование с типом double ===" << endl;
    Matrix<double> mat9(2, 2, 1.5);
    Matrix<double> mat10(2, 2, 2.5);
    cout << "Матрицы типа double:" << endl;
    printMatrix(mat9, "mat9 (2x2, заполнена 1.5)");
    printMatrix(mat10, "mat10 (2x2, заполнена 2.5)");

    Matrix<double> mat11 = mat9 + mat10;
    cout << "Матрица типа double после операции + (mat11 = mat9 + mat10):" << endl;
    printMatrix(mat11, "mat11");

    return 0;
}
```
<details>
<summary><b>Вывод в конслоль</b></summary>

```
Исходные матрицы:
Матрица mat1 (2x3, заполнена 1):
1 1 1 
1 1 1 

Матрица mat2 (2x3, заполнена 2):
2 2 2 
2 2 2 

Матрица mat3 (3x2, заполнена 3):
3 3 
3 3 
3 3 


=== Тестирование оператора присваивания ===
Матрица после операции присваивания (mat4 = mat1):
Матрица mat4 (2x3):
1 1 1 
1 1 1 


=== Тестирование оператора += ===
Матрица после операции += (mat1 += mat2):
Матрица mat1 (2x3):
3 3 3 
3 3 3 


=== Тестирование оператора + ===
Матрица после операции + (mat5 = mat1 + mat2):
Матрица mat5 (2x3):
5 5 5 
5 5 5 


=== Тестирование оператора -= ===
Матрица после операции -= (mat1 -= mat2):
Матрица mat1 (2x3):
1 1 1 
1 1 1 


=== Тестирование оператора - ===
Матрица после операции - (mat6 = mat2 - mat1):
Матрица mat6 (2x3):
1 1 1 
1 1 1 


=== Тестирование оператора *= (умножение на скаляр) ===
Матрица после операции *= (mat1 *= 3):
Матрица mat1 (2x3):
3 3 3 
3 3 3 


=== Тестирование оператора * (умножение на скаляр) ===
Матрица после операции * (mat7 = mat1 * 2):
Матрица mat7 (2x3):
6 6 6 
6 6 6 


=== Тестирование матричного умножения ===
Матрица после матричного умножения (mat8 = mat2 * mat3):
Матрица mat8 (2x2):
18 18 
18 18 


=== Тестирование оператора *= (матричное умножение) ===
Матрица после операции *= (mat2 *= mat3):
Матрица mat2 (2x2):
18 18 
18 18 


=== Тестирование с типом double ===
Матрицы типа double:
Матрица mat9 (2x2, заполнена 1.5):
1.5 1.5 
1.5 1.5 

Матрица mat10 (2x2, заполнена 2.5):
2.5 2.5 
2.5 2.5 

Матрица типа double после операции + (mat11 = mat9 + mat10):
Матрица mat11 (2x2):
4 4 
4 4 
```
</details>
</details>

### В завершении
На этом все, ниже указаны методы реализованные в Matrix (и те, которые были рассмотренны выше) и примеры работы с ними.
***Спасибо за внимание и следите за обновлениями!***

<details>
<summary><a id = "Metods"><h2>Публичные методы</h2></a></summary>
    
|             Методы              | Описание                                                                                      |
| :-----------------------------: | :-------------------------------------------------------------------------------------------- |
|    [addColumns](#addColumns)    | Добавляет справо указаное количество столбцов                                                 |
|       [addRows](#addRows)       | Добавляет снизу указаное количество строк                                                     |
|         [clear](#clear)         | Очищает объект класса                                                                         |
|          [fill](#fill)          | Заполняет матрицу указанным значением                                                         |
| [removeColumns](#removeColumns) | Удаляет справо указаное количество столбцов                                                   |
|    [removeRows](#removeRows)    | Удаляет снизу указаное количество строк                                                       |
|       [setSize](#setSize)       | Устанавливает новые размеры матрицы                                                           |
|          [size](#size)          | Возвращает структуру `pair`, где `firs` - количество строк,<br>`second` - количество столбцов |
<details>
<summary><a id="addColumns"><h3><code>addColumns</code></h3></a></summary>

```h
void addColumns(int columns); // Добавляет новые столбцы справо
```
**Пример**
```cpp
#include <iostream>
#include "Matrix.h"
using namespace std;
int main()
{
    Matrix<int> mat1(3, 4, 5);
    cout << "mat1 до добавление столбцов" << endl;
    for (int i = 0; i < mat1.size().first; i++)
    {
        for (int j = 0; j < mat1.size().second; j++)
        {
            cout << mat1(i, j) << " ";
        }
        cout << endl;
    }
    mat1.addColumns(3); // Добавляем 3 столбца
    cout << "mat1 после добавление 3 столбцов" << endl;
    for (int i = 0; i < mat1.size().first; i++)
    {
        for (int j = 0; j < mat1.size().second; j++)
        {
            cout << mat1(i, j) << " ";
        }
        cout << endl;
    }
    return 0;
}
```
**Вывод в консль**
```cpp
mat1 до добавление столбцов
5 5 5 5
5 5 5 5
5 5 5 5
mat1 после добавление 3 столбцов
5 5 5 5 0 0 0
5 5 5 5 0 0 0
5 5 5 5 0 0 0
```
</details>
<details>
<summary><a id="addRows"><h3><code>addRows</code></h3></a></summary>

```h
void Matrix<T>::addRows(int rows); // Добовить новые строки
```
**Пример**
```cpp
#include "Matrix.h"
#include <iostream>
using namespace std;
int main()
{
    Matrix<int> mat(3, 3, 3);
    cout << "mat до добавления новых строк" << endl;
    for (int i = 0; i < mat.size().first; i++)
    {
        for (int j = 0; j < mat.size().second; j++)
        {
            cout << mat(i, j) << " ";
        }
        cout << endl;
    }
    mat.addRows(3); // Добвляем 3 строки
    cout << "mat после добавления 3 строк" << endl;
    for (int i = 0; i < mat.size().first; i++)
    {
        for (int j = 0; j < mat.size().second; j++)
        {
            cout << mat(i, j) << " ";
        }
        cout << endl;
    }
}
```
**Вывод в консоль**
```cpp
mat до добавления новых строк
3 3 3 
3 3 3 
3 3 3 
mat после добавления 3 строк
3 3 3 
3 3 3 
3 3 3 
0 0 0 
0 0 0 
0 0 0 
```
</details>
<details>
<summary><a id="clear"><h3><code>clear</code></h3></a></summary>

```h
void Matrix<T>::clear()
```
**Пример**
```cpp
#include "Matrix.h"
int main()
{
    Matrix<int> mat(3, 3, 3);
    mat.clear();
}
```
</details>
<details>
<summary><a id="fill"><h3><code>fill</code></h3></a></summary>

```h
void Matrix<T>::fill(const T value); //Заполнить матрицу указаным значением value
```
**Пример**
```cpp
#include <iostream>
#include "Matrix.h"
using namespace std;
int main()
{
    Matrix<int> mat(3, 3, 3);
    cout << "mat до применения fill" << endl;
    for (int i = 0; i < mat.size().first; i++)
    {
        for (int j = 0; j < mat.size().second; j++)
        {
            cout << mat(i, j) << " ";
        }
        cout << endl;
    }
    mat.fill(0); // Заполняем матрицу 0
    cout << "mat после fill" << endl;
    for (int i = 0; i < mat.size().first; i++)
    {
        for (int j = 0; j < mat.size().second; j++)
        {
            cout << mat(i, j) << " ";
        }
        cout << endl;
    }
}
```
**Вывод в консоль**
```cpp
mat до применения fill
3 3 3         
3 3 3         
3 3 3         
mat после fill
0 0 0         
0 0 0         
0 0 0
```
</details>
<details>
<summary><a id="clear"><h3><code>clear</code></h3></a></summary>

```h
void Matrix<T>::clear()
```
**Пример**
```cpp
#include "Matrix.h"
int main()
{
    Matrix<int> mat(3, 3, 3);
    mat.clear();
}
```
</details>
<details>
<summary><a id="removeColumns"><h3><code>removeColumns</code></h3></a></summary>

```h
void Matrix<T>::removeColumns(int columns); //Удалять указаное columns столбцов 
```
**Пример**
```cpp
#include <iostream>
#include "Matrix.h"
using namespace std;
int main()
{
    Matrix<int> mat(3, 3, 3);
    cout << "mat до удаления столбцов" << endl;
    for (int i = 0; i < mat.size().first; i++)
    {
        for (int j = 0; j < mat.size().second; j++)
        {
            cout << mat(i, j) << " ";
        }
        cout << endl;
    }
    mat.removeColumns(2); // Удяляем 2 столбца
    cout << "mat после удаления 2 столбцов" << endl;
    for (int i = 0; i < mat.size().first; i++)
    {
        for (int j = 0; j < mat.size().second; j++)
        {
            cout << mat(i, j) << " ";
        }
        cout << endl;
    }
}
```
**Вывод в консоль**
```cpp
mat до удаления столбцов
3 3 3 
3 3 3 
3 3 3 
mat после удаления 2 столбцов
3 
3 
3 
```
</details>
<details>
<summary><a id="removeRows"><h3><code>removeRows</code></h3></a></summary>

```h
void Matrix<T>::removeRows(int rows); //Удалять указаное rows строк 
```
**Пример**
```cpp
#include <iostream>
#include "Matrix.h"
using namespace std;
int main()
{
    Matrix<int> mat(3, 3, 3);
    cout << "mat до удаления строк" << endl;
    for (int i = 0; i < mat.size().first; i++)
    {
        for (int j = 0; j < mat.size().second; j++)
        {
            cout << mat(i, j) << " ";
        }
        cout << endl;
    }
    mat.removeRows(2); // Удяляем 2 строки
    cout << "mat после удаления 2 строк" << endl;
    for (int i = 0; i < mat.size().first; i++)
    {
        for (int j = 0; j < mat.size().second; j++)
        {
            cout << mat(i, j) << " ";
        }
        cout << endl;
    }
}
```
**Вывод в консоль**
```cpp
mat до удаления строк
3 3 3 
3 3 3 
3 3 3 
mat после удаления 2 строк
3 3 3
```
</details>
<details>
<summary><a id="setSize"><h3><code>setSize</code></h3></a></summary>

```h
void setSize(int rows, int columns); //Устанавливает новые размеры
void setSize(const pair<int, int> new_size); 
```
**Пример**
```cpp
#include <iostream>
#include "Matrix.h"
using namespace std;
int main()
{
    Matrix<int> mat(3, 3, 3);
    cout << "Начальная mat" << endl;
    for (int i = 0; i < mat.size().first; i++)
    {
        for (int j = 0; j < mat.size().second; j++)
        {
            cout << mat(i, j) << " ";
        }
        cout << endl;
    }
    mat.setSize(2, 4); // Матрица из 2 строк и 4 столбцов
    cout << "Новая матрица" << endl;
    for (int i = 0; i < mat.size().first; i++)
    {
        for (int j = 0; j < mat.size().second; j++)
        {
            cout << mat(i, j) << " ";
        }
        cout << endl;
    }
}
```
**Вывод в консоль**
```cpp
Начальная mat
3 3 3 
3 3 3 
3 3 3 
Новая матрица
3 3 3 0
3 3 3 0
```
</details>
<details>
<summary><a id="size"><h3><code>size</code></h3></a></summary>

```h
pair<int, int> size() //возвращает размеры матрицы виде pair 
```
**Пример**
```cpp
#include <iostream>
#include "Matrix.h"
using namespace std;
int main()
{
    Matrix<int> mat(3, 3, 3);
    cout << "Количество строк " << mat.size().first << ", количество столбцов " << mat.size().second << endl;
}
```
**Вывод в консоль**
```cpp
Количество строк 3 , количество столбцов 3
```
</details>
</details>
