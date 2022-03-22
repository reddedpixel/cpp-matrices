#pragma once
#include <iostream>
template <typename T>
class Matrix
{
private:
	int rows;
	int columns;
	T* element;
public:
    class Iterator
    {
    private:
        T* row;
        int length;
    public:
        T operator[](int i)
        {
            if ((i < 0) || (i >= length))
            {
                std::cerr << "Unable to find cell with index " << i << std::endl;
                exit(0);
            }
            return row[i];
        }
        Iterator(T* row) : row(row) {
            length = sizeof(row)/sizeof(row[0]);
        }
    };

    Matrix<T>()
    {

    }
    
	Matrix<T>(int r, int c)
    {
        rows = r;
        columns = c;
        element = new T[r * c];
        //for (int i = 0; i < rows; i++)
        //{
        //    element[i] = new T[c];
        //}
    }

    ~Matrix<T>() { std::cout << "deleted" << std::endl; }

	//gets
    int getRows() { return rows; }

    int getColumns() { return columns; }

	//sets
    void setRows(int r) { rows = r; }
    void setColumns(int c) { columns = c; }

	void print()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                std::cout << element[i * columns + j] << " ";
            }
            std::cout << std::endl;
        }
    }

	void fill()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                std::cin >> element[i * columns + j];
            }
        }
    }

	bool operator==(Matrix<T> b)
    {
        if ((rows != b.rows) or (columns != b.columns))
            return false;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (element[i * columns + j] != b.element[i * columns + j])
                    return false;
            }
        }
        return true;
    }

	Iterator operator[](int i)
    {
        if (i < 0 || i >= rows)
        {
            std::cerr << "Unable to find cell with index " << i << std::endl;
            exit(0);
        }
        return element + i * rows;
    }

	Matrix<T> operator* (int k)
    {
        Matrix<T> M(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                M.element[i * columns + j] *= /*element[i * rows + j] **/ k;
            }
        }
        return M;
    }

	Matrix<T> operator* (Matrix<T> b)
    {
        if (columns != b.rows)
        {
            std::cout << "Unable to multiply matrices with these dimensions." << std::endl;
            exit(0);
        }

        Matrix<T> M(rows, b.columns);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < b.columns; j++)
            {
                M.element[i * b.columns + j] = 0;
                for (int k = 0; k < columns; k++)
                    M.element[i * b.columns + j] += element[i * columns + k] * b.element[k * b.columns + j];
            }
        }
        return M;
    }

    Matrix<T> operator+(Matrix<T> b)
    {
        if ((columns != b.columns) || (rows != b.rows))
        {
            std::cout << "Unable to sum matrices with unequal dimensions." << std::endl;
            exit(0);
        }

        Matrix<T> M(rows, columns);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                M.element[i * columns + j] = element[i * columns + j] + b.element[i * columns + j];
            }
        }
        return M;
    }
};