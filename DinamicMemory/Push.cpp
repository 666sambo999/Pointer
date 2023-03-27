#include "Push.h"


template <typename T>T* Push_back(T arr[], int& n, int value) // произвести передачу по ссылке и ставим &
{
	//1)создать новый массив, выделить область памяти, нужного размера: 
	T* brr = new T[n + 1];// buffer 
	// 2) копируем все содержимое исконного масcива в новый:
	for (int i = 0; i < n; i++)
	{
		brr[i] = arr[i];
	}
	// 3) удаляем исходный массив:
	delete[] arr;
	// 4) подменить указатель старого массива на новый:
	arr = brr; //  оба переменных являются указателями 
	// 5) Только после этого в массиве arr появляется элемент, в который можем сохранить значение 
	arr[n] = value;
	// 6) После добавления в массив, кол-во его элементов увеличевается на 1
	n++;
	//7)  возвратить 
	return arr; // возвращает новый массив 
}
template <typename T>T* push_front(T arr[], int& n, int value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
// 2 вариант 
//int* push_front(int arr[], int& n, int value)
//{
//	int* buffer = new int[n + 1];//
//	for (int i = 0; i < n; i++)buffer[i + 1] = arr[i];// копируем со смещением
//	delete[] arr; // удаляем массив
//	buffer[0] = value; // помещаем добавленный элемент в начало массива
//	n++; // 
//	return buffer; // возвращаем массив 
//}
template <typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	//1) Перераспределяем массив указателей
	T** buffer = new T * [rows + 1] {};
	// 2) копируем адреса строк из исходного массива указателей в новый
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	// 3) удаляем старый массив указаителей
	delete[] arr;
	//4) добавляем новую строку в массив 
	buffer[rows] = new T[cols]{};
	//5) После добавления строки, кол-во строк увеличевается на 1
	rows++;
	// 6) возвращаем новый массив на место вызова
	return buffer;
}
template <typename T>T** push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T * [rows + 1] {};
	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new T[cols]{};
	rows++;
	return buffer;
}
template <typename T>void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template <typename T>void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}