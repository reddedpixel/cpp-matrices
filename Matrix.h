#pragma once
#include <iostream>

template <typename T> // T - любой тип данных
class Matrix
{
private:
	int rows;
	int columns;
public:
	Matrix();
	Matrix(int r, int c);
	~Matrix();

	//gets
	int getRows();
	int getColumns();


	//sets
	void setRows(int r);
	void setColumns(int c);


};