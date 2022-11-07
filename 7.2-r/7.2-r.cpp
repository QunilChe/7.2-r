// Lab_7_2_1.cpp
// < прізвище, ім’я автора >
// Лабораторна робота No 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 0
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount,
	const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void SearchMaxEven(int** a, const int n, int& minEven);
void SearchMaxEven1(int** a, const int n, int& minEven, int& max, int i, int j);
bool SearchMinEven(int** a, const int n, int& mininEven, int min, int i, int j);

void SearchMaxi(int** a, const int n, int& minEven, int& maxi, int I, int j);
void SearchMini(int** a, const int n, int& minEven, int& mini, int I, int j);
void SearchMaxj(int** a, const int n, int& minEven, int& maxj, int i, int j);
void SearchMinj(int** a, const int n, int& minEven, int& minj, int I, int j);

void swapMaxMin(int** a, int& maxi, int& mini, int& maxj, int& minj);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -6;
	int High = 23;
	int n;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n, n, Low, High, 0, 0);
	Print(a, n, n, 0, 0);
	int minEven, max = -6, mininEven;

	//SearchMaxEven(a, n, minEven);

	SearchMinEven(a, n, mininEven, 0, 0, 1);

	int maxi, maxj, mini, minj;
	SearchMaxEven1(a, n, minEven, max, 0, 1);
	SearchMaxi(a, n, minEven, maxi, 0, 1);
	SearchMini(a, n, minEven, mini, 0, 0);
	SearchMaxj(a, n, minEven, maxj, 0 ,1);
	SearchMinj(a, n, minEven, minj, 0, 0);
	cout << maxi << endl;
	cout << mini << endl;
	cout << maxj << endl;
	cout << minj << endl;
	swapMaxMin(a, maxi, mini, maxj, minj);
	cout << "max even = " << minEven << endl;
	cout << "min even = " << mininEven << endl;
	Print(a, n, n, 0, 0);
	return 0;
}
void Create(int** a, const int rowCount, const int colCount,
	const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
}
void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}
void SearchMaxEven(int** a, const int n, int& minEven)
{
	int max;
	max = a[0][1];
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			if (a[i][j] > max) max = a[i][j], minEven = a[i][j];

}
void SearchMaxEven1(int** a, const int n, int& minEven, int& max, int i, int j)
{
	if (i < n - 1)
	{
		if (j < n-1)
		{			
				if (a[i][j] > max)
				{ 
				max = a[i][j], minEven = a[i][j];
				SearchMaxEven1(a, n, minEven, max, i, j + 1);
			}
		}
		else SearchMaxEven1(a, n, minEven, max, i+1, 0);
	}		
}
bool SearchMinEven(int** a, const int n, int& mininEven, int min, int i, int j)
{
	if (i < n - 1)
	{
		if (j < n)
		{
			if (a[i][j] < min) min = a[i][j], mininEven = a[i][j];
			SearchMinEven(a, n, mininEven, min, i + 1, j+1);
		}
	}
return true;
}

void SearchMaxi(int** a, const int n, int& minEven, int& maxi, int i, int j)
{
	if (i < n - 1)
	{
		if (j < n)
		{
			if (a[i][j] > minEven) maxi = i;
			else SearchMaxi(a, n, minEven, maxi, i+1, j + 1);
		}
	}
}

void SearchMaxj(int** a, const int n, int& minEven, int& maxj, int i, int j)
{
	if (i < n - 1)
	{
		if (j < n)
		{
			if (a[i][j] > minEven) maxj = j;
			else SearchMaxi(a, n, minEven, maxj, i + 1, j + 1);
		}
	}
}

void SearchMini(int** a, const int n, int& mininEven, int& mini, int i, int j)
{
	if (i < n)
	{
		if (j < n)
		{
			if (a[i][j] < mininEven) mini = i;
			else SearchMaxi(a, n, mininEven, mini, i + 1, j + 1);
		}
	}
}
void SearchMinj(int** a, const int n, int& mininEven, int& minj, int i, int j)
{
	if (i < n)
	{
		if (j < n)
		{
			if (a[i][j] < mininEven) minj = i;
			else SearchMaxi(a, n, mininEven, minj, i + 1, j + 1);
		}
	}
}
void swapMaxMin(int** a, int& maxi, int& mini, int& maxj, int& minj)
{
	int tmp = a[maxi][maxj];
	a[maxi][maxj] = a[mini][minj];
	a[mini][minj] = tmp;
}
