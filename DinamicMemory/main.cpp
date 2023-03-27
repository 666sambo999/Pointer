#include "stdafx.h"
#include "Allocate.h"
#include "Allocate.cpp"
#include "Clear.h"
#include "Clear.cpp"
#include "FillRand.h"
#include "Print.h"
#include "Print.cpp"
#include "Push.h"
#include "Push.cpp"
#include "Pop.h"
#include "Pop.cpp"
#include "Insert.h"
#include "Insert.cpp"
#include "erase.h"
#include "erase.cpp"


//#define DIMANO_MEMORY1
#define DINAMO_MEMORY2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DIMANO_MEMORY1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	arr = Push_back(arr, n, value);
	Print(arr, n);

	cout << "Удаление из массива последного элемента: " << endl;
	arr = Pop_back(arr, n, value);
	Print(arr, n);

	cout << "Введите значение добавляемого элемента: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	cout << "Удаление первого элемента из массива:" << endl;
	arr = pop_front(arr, n, value);
	Print(arr, n);

	int index;
	//cout << "Введите значение элемента по указанному индексу: "; cin >> index;
	cout << "Введите индекс добавляемого значения:  "; cin >> index;
	cout << "Введите значение добавляемого значения:  "; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	cout << "Введите значение по указанному индексу: "; cin >> index;
	arr = erase(arr, n, value, index);
	Print(arr, n);
	delete[] arr;

#endif // DIMANO_MEMORY1
#ifdef DINAMO_MEMORY2

	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	
	int** arr = Allocate<int>(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Добавление строки в конец массва: " << endl; 
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Добавление строки в начало массива: " << endl; 
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	int index; 
	cout << "Добавление строки по указанному индексу массива: "; cin >> index;
	arr = Insert(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << "Удаление строки в конце массива: " << endl; 
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Удаление строки в начале массива: " << endl; 
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	int in;
	cout << "Введите индекс для удаления строки:"; cin >> in;
	arr = erase_row(arr, rows, cols,in);
	Print(arr, rows, cols);
	cout << "Всталяем пустой столбец в конец массива: " << endl; 
	push_col_back(arr, rows, cols);
	Print(arr,rows, cols);
	cout << "Всталяем пустой столбец в начало массива: " << endl; 
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	int a;
	cout << "Введите индекс для добавления столбика по индексу:"; cin >> a;
	insert_col(arr, rows, cols, a);
	Print(arr, rows, cols);
	cout << "Удаление столбца с конца массива: " << endl; 
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Удаление столбца с начала массива: " << endl;
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	int b;
	cout << "Введите индекс для удаления столбца по индексу:"; cin >> b;
	erase_col(arr, rows, cols, b);
	Print(arr, rows, cols);
	Clear(arr, rows);

#endif // DINAMO_MEMORY2
}
