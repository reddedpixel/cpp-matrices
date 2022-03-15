//#include "Matrix.h"

#include <iostream>
#include <string>

template <typename T> // T - ����� ��� ������
class Matrix
{
private:
    int rows;
    int columns;
    T** element; // 
public:
    Matrix(int r, int c);
    ~Matrix();

    //gets
    int getRows();
    int getColumns();

    //sets
    void setRows(int r);
    void setColumns(int c);

    T operator[](int);
    bool operator== (Matrix<T>);
    Matrix<T> operator* (int);
    /*Matrix<T> operator+(Matrix<T>, Matrix<T>);
    Matrix<T> operator*(Matrix<T>, Matrix<T>);*/

    void print();
    void fill();
};

template <typename T>
Matrix<T>::Matrix(int r, int c)
{
    rows = r;
    columns = c;
    element = new T * [r];
    for (int i = 0; i < rows; i++)
    {
        element[i] = new T[c];
    }
}

template <typename T>
Matrix<T>::~Matrix()
{
    std::cout << "deleted" << std::endl;
}

// gets
template <typename T>
int Matrix<typename T>::getRows() {
    return rows;
}

template <typename T>
int Matrix<typename T>::getColumns() {
    return columns;
}

//sets
template <typename T>
void Matrix<T>::setRows(int r)
{
    rows = r;
};
template <typename T>
void Matrix<T>::setColumns(int c)
{
    columns = c;
};

template <typename T>
void Matrix<T>::print()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << element[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
void Matrix<T>::fill()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cin >> element[i][j];
        }
        std::cout << std::endl;
    }
}

template <typename T>
bool Matrix<T>::operator== (Matrix<T> b)
{
    if ((rows != b.rows) or (columns != b.columns))
        return false;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (element[i][j] != b.element[i][j])
                return false;
        }
    }

    return true;

}

template <typename T>
T Matrix<T>::operator[] (int subscript)
{
    if (subscript < 0 || subscript >= rows * columns)
    {
        std::cerr << "\n ������ �������: " << subscript << std::endl;
        return 0;
    }
    // ��������� � 1, � ������� � 0
    int i = int((subscript - 1) / columns); // ����� ����� �� ������� �����-1 �� ���������� ��������
    int j = (subscript - 1) % columns; // �������

    return element[i][j]; // ������� ������ �� ������� �������
}

template <typename T>
Matrix<T> Matrix<T>::operator* (int k)
{
    Matrix<T> M(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            M.element[i][j] = element[i][j] * k;
        }
    }
        return M;
}
