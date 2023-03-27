#include "Insert.h"

template <typename T>T* insert(T arr[], int& n, T value, T index)
{
	T* buffer = new T[++n];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	buffer[index] = value;
	for (int i = index; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	return buffer;
}
//int* insert(int arr[], int& n, int value, int index)
//{
//	int* buffer = new int[++n];
//	for (int i = 0; i < index; i++)buffer[i] = arr[i];
//	for (int i = index; i < n; i++)buffer[i + 1] = arr[i];
//	delete[] arr;
//	buffer[index] = value;
//	n++; 
//	return buffer; 
//}
template <typename T>T** Insert(T** arr, int& rows, const int cols, T index)
{
	T** buffer = new T * [rows + 1] {};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	buffer[index] = new T[cols]{};
	for (int i = index; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	rows++;
	return buffer;
	// 2 вариант 
	/*int** buffer = new int* [rows + 1] {};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	buffer[index] = new int [cols] {};
	rows++;
	return buffer;*/
}
template <typename T>void insert_col(T** arr, const int rows, int& cols, T a)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < a; j++)buffer[j] = arr[i][j];
		for (int j = a; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}