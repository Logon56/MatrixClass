# MatrixClass
**Класс Matrix** - класс, реализующий работу с таким математическим объектом как матрицы.
Для удобной работы в классе определены различные методы и их перегрузки (о [методах рассказано ниже]()). В дальнейшем будут добавлятся новые методы и улучаться старые. Matrix является шаблоным классом и удобен для таких типов, как *int, double, long, short, float и похожие*.
Данный проект не заброшен, заходите по чаще и следите за обновлениями😊
## Работа с Matrix
### Установка
Чтобы начать работу с матрицами, необходимо скачать файл Matrix.h и в `#include` указать полный или относительный путь до файла. Наприме, допустип есть папка *MyProject*, в ней содержится папка *Matrix*, тогда подключение матриц будет выглядеть так: `#include "Myproject\Matrix\Matrix.h"`.
### Создание объекта
Для создание объекта, в классе объявлены и определенны несколько конструкторов:
<details>
<summary>Конструкторы</summary>

<details>
<summary>Конструктор по умолчанию</summary>

```cpp
template<typename T>
Matrix<T>::Matrix() : rows_(0), columns_(0), data_(nullptr) {}
```
</details>

<details>
<summary>Конструктор с параметрами</summary>

```cpp
template<typename T>
Matrix<T>::Matrix(int rows, int columns, const T value) 
    : rows_(rows), columns_(columns) 
{
    data_ = new T[rows * columns];
    std::fill(data_, data_ + rows * columns, value);
}
```
</details>
</details>
**Пример**
```
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
### Доступ к элементам
Для доступа к элементам в класса Matrix перегружен оператор `()`:
```
T &operator()(int row, int column) //Перегрузка оператора ()
```
С помощью данного оператора удобно заполнять и выводить матрицы:


