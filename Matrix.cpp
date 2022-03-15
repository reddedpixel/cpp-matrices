//#include "Matrix.h"

#include <iostream>
#include <string>

template <typename T> // T - любой тип данных
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