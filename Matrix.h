#include <utility>
#include <iostream>
#ifndef MATRIX
#define MATRIX
using std::pair, std::cout, std::endl;
template <typename T>
class Matrix
{
private:
    T *matrix;
    pair<int, int> MatSize;

public:
    Matrix() : matrix(nullptr) {}
    Matrix(int rows, int columns, const T value = T());
    Matrix(const Matrix<T> &mat);
    Matrix(const pair<int, int> size, const T value = T());
    ~Matrix() { delete[] matrix; }
    pair<int, int> size() const { return MatSize; }
    T &operator()(int row, int columns) const { return matrix[MatSize.second * row + columns]; }
    Matrix<T> &operator=(const Matrix<T> &mat);
    Matrix<T> &operator+=(const Matrix<T> &mat);
    Matrix<T> &operator-=(const Matrix<T> &mat);
    Matrix<T> &operator*=(const Matrix<T> &mat);
    Matrix<T> &operator*=(const int mul);
    Matrix<T> operator+(const Matrix<T> &mat) const;
    Matrix<T> operator-(const Matrix<T> &mat) const;
    Matrix<T> operator*(const Matrix<T> &mat) const;
    Matrix<T> operator*(const int mul) const;
    void fill(const T value = T());
    void clear();
    void addRows(int rows);
    void addColumns(int columns);
    void removeRows(int rows);
    void removeColumns(int columns);
    void setSize(int rows, int columns);
    void setSize(const pair<int, int> new_size);
};

template <typename T>
inline Matrix<T>::Matrix(int rows, int columns, const T value)
{
    MatSize = pair<int, int>(rows, columns);
    matrix = new T[rows * columns];
    fill(value);
}

template <typename T>
inline Matrix<T>::Matrix(const Matrix<T> &mat)
{
    MatSize = mat.MatSize;
    matrix = new T[MatSize.first * MatSize.second];
    for (int i = 0; i < MatSize.first * MatSize.second; i++)
    {
        matrix[i] = mat.matrix[i];
    }
}

template <typename T>
inline Matrix<T>::Matrix(const pair<int, int> size, const T value)
{
    MatSize = size;
    matrix = new T[size.first * size.second];
    fill(value);
}

template <typename T>
inline Matrix<T> &Matrix<T>::operator=(const Matrix<T> &mat)
{
    if (mat.MatSize == MatSize)
    {
        for (int i = 0; i < mat.MatSize.first * mat.MatSize.second; i++)
        {
            matrix[i] = mat.matrix[i];
        }
    }
    else
    {
        delete[] matrix;
        matrix = new T[mat.MatSize.first * mat.MatSize.second];
        for (int i = 0; i < mat.MatSize.first * mat.MatSize.second; i++)
        {
            matrix[i] = mat.matrix[i];
        }
        MatSize = mat.MatSize;
    }
    return *this;
}

template <typename T>
inline Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &mat)
{
    if (MatSize != mat.MatSize)
    {
        cout << "Размеры матриц не совпадают" << endl;
        exit(0);
    }
    for (int i = 0; i < MatSize.first * MatSize.second; i++)
    {
        matrix[i] += mat.matrix[i];
    }
    return *this;
}

template <typename T>
inline Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &mat)
{
    if (MatSize != mat.MatSize)
    {
        cout << "Размеры матриц не совпадают" << endl;
        exit(0);
    }
    for (int i = 0; i < MatSize.first * MatSize.second; i++)
    {
        matrix[i] -= mat.matrix[i];
    }
    return *this;
}

template <typename T>
inline Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &mat)
{
    if (MatSize.second != mat.MatSize.first)
    {
        cout << "Размеры матриц не совпадают";
        exit(0);
    }
    Matrix<T> temp(MatSize.first, mat.MatSize.second);
    for (int i = 0; i < MatSize.first; i++)
    {
        for (int j = 0; j < mat.MatSize.second; j++)
        {
            T temp_value = T();
            for (int k = 0; k < MatSize.second; k++)
            {
                temp_value += (*this)(i, k) * mat(k, j);
            }
            temp(i, j) = temp_value;
        }
    }
    delete[] matrix;
    matrix = new T[temp.MatSize.first * temp.MatSize.second];
    for (int i = 0; i < temp.MatSize.first * temp.MatSize.second; i++)
    {
        matrix[i] = temp.matrix[i];
    }
    MatSize = temp.MatSize;
    return *this;
}

template <typename T>
inline Matrix<T> &Matrix<T>::operator*=(const int mul)
{
    for (int i = 0; i < MatSize.first * MatSize.second; i++)
    {
        matrix[i] *= mul;
    }
    return *this;
}

template <typename T>
inline Matrix<T> Matrix<T>::operator+(const Matrix<T> &mat) const
{
    Matrix<T> temp(*this);
    temp += mat;
    return temp;
}

template <typename T>
inline Matrix<T> Matrix<T>::operator-(const Matrix<T> &mat) const
{
    Matrix<T> temp(*this);
    temp -= mat;
    return temp;
}

template <typename T>
inline Matrix<T> Matrix<T>::operator*(const Matrix<T> &mat) const
{
    Matrix<T> temp(*this);
    temp *= mat;
    return temp;
}

template <typename T>
inline Matrix<T> Matrix<T>::operator*(const int mul) const
{
    Matrix<T> temp(*this);
    temp *= mul;
    return temp;
}

template <typename T>
inline void Matrix<T>::fill(const T value)
{
    for (int i = 0; i < MatSize.first * MatSize.second; i++)
    {
        matrix[i] = value;
    }
}

template <typename T>
inline void Matrix<T>::clear()
{
    delete[] matrix;
    matrix = nullptr;
    MatSize = pair<int, int>();
}

template <typename T>
inline void Matrix<T>::addRows(int rows)
{
    T *temp_matrix = new T[(MatSize.first + rows) * MatSize.second];
    for (int i = 0; i < MatSize.first * MatSize.second; i++)
    {
        temp_matrix[i] = matrix[i];
    }
    for (int i = MatSize.first * MatSize.second; i < (MatSize.first + rows) * MatSize.second; i++)
    {
        temp_matrix[i] = T();
    }
    delete[] matrix;
    matrix = temp_matrix;
    MatSize.first += rows;
}

template <typename T>
inline void Matrix<T>::addColumns(int columns)
{
    T *temp_matrix = new T[MatSize.first * (MatSize.second + columns)];
    for (int i = 0; i < MatSize.first; i++)
    {
        for (int j = 0; j < MatSize.second; j++)
        {
            temp_matrix[i * (MatSize.second + columns) + j] = (*this)(i, j);
        }
        for (int j = MatSize.second; j < MatSize.second + columns; j++)
        {
            temp_matrix[i * (MatSize.second + columns) + j] = T();
        }
    }
    delete[] matrix;
    matrix = temp_matrix;
    MatSize.second += columns;
}
template <typename T>
inline void Matrix<T>::removeRows(int rows)
{
    T *temp_matrix = new T[(MatSize.first - rows) * MatSize.second];
    for (int i = 0; i < (MatSize.first - rows) * MatSize.second; i++)
    {
        temp_matrix[i] = matrix[i];
    }
    delete[] matrix;
    matrix = temp_matrix;
    MatSize.first -= rows;
}
template <typename T>
inline void Matrix<T>::removeColumns(int columns)
{
    T *temp_matrix = new T[MatSize.first * (MatSize.second - columns)];
    for (int i = 0; i < MatSize.first; i++)
    {
        for (int j = 0; j < MatSize.second - columns; j++)
        {
            temp_matrix[i * (MatSize.second - columns) + j] = matrix[i * MatSize.second + j];
        }
    }
    delete[] matrix;
    matrix = temp_matrix;
    MatSize.second -= columns;
}

template <typename T>
inline void Matrix<T>::setSize(int rows, int columns)
{

    if (rows == 0 && columns == 0)
    {
        clear();
        return;
    }
    if (MatSize.first != rows)
    {
        if (rows > MatSize.first)
        {
            addRows(rows - MatSize.first);
        }
        else
        {
            removeRows(MatSize.first - rows);
        }
    }
    if (MatSize.second != columns)
    {
        if (columns > MatSize.second)
        {
            addColumns(columns - MatSize.second);
        }
        else
        {
            removeColumns(MatSize.second - columns);
        }
    }
}
template <typename T>
inline void Matrix<T>::setSize(const pair<int, int> new_size)
{
    setSize(new_size.first, new_size.second);
}
#endif // MATRIX
