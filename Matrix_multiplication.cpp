#include <iostream>
using namespace std;

// функция умножения матриц
int multiply_matrix(int row1, int row2, int col1, int col2, double** a, double** b)
/*
* Функция принимает на вход количество строк и столбцов каждой матрицы и указатели на сами матрицы.
* Сравнивает количество строк первой матрицы с количеством столбцов второй.
* Если значения различаются, то мы не можем выполнить умножение и выходим из функции.
* Далее сама функция.
* Создаём указатель, который указывает на указатель на массив размера *количество строк первой матрицы*
*/
{
    // проверка на возможность выполнения операции
	if (col1 != row2)
	{
		cout << "Умножение невозможно!";
		return 0;
	}
    // умножениие
    double ** c = new double* [row1];
    for (int i = 0; i < row1; i++)
    {
        c[i] = new double[col2];
        for (int j = 0; j < col2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < col1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
    // Вывод матрицы произведения
    cout << "Матрица произведения" << endl;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
    return 0;
}



int main()
{
    setlocale(LC_CTYPE, "rus");
	int row1, row2, col1, col2;
    double** a, ** b;
	cout << "Введите количество строк первой матрицы: ";
	cin >> row1;
	cout << "Введите количество столбцов первой матрицы: ";
	cin >> col1;
	cout << "Введите количество строк второй матрицы: ";
	cin >> row2;
	cout << "Введите количество столбцов второй матрицы: ";
	cin >> col2;
    // Ввод элементов первой матрицы
    a = new double* [row1];
    cout << "Введите элементы первой матрицы" << endl;
    for (int i = 0; i < row1; i++)
    {
        a[i] = new double[col1];
        for (int j = 0; j < col1; j++)
        {
            cout << "a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
        }
    }
    // Вывод элементов первой матрицы
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    // Ввод элементов второй матрицы
    b = new double* [row2];
    cout << "Введите элементы второй матрицы" << endl;
    for (int i = 0; i < row2; i++)
    {
        b[i] = new double[col2];
        for (int j = 0; j < col2; j++)
        {
            cout << "b[" << i << "][" << j << "]= ";
            cin >> b[i][j];
        }
    }
    // Вывод элементов второй матрицы
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    multiply_matrix(row1, row2, col1, col2, a, b);
    return 0;
}
