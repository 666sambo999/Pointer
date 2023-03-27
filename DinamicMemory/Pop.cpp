#include "Pop.h"
template <typename T>T* Pop_back(T arr[], int& n, int value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n--;
	return arr;
}
//int* Pop_back(int arr[], int& n, int value)
//{
//	int* buffer = new int[--n];
//	for (int i = 0; i < n; i++)buffer[i] = arr[i];
//	delete[] arr;
//	return buffer;
//}

template <typename T>T* pop_front(T arr[], int& n, int value)
{
	T* crr = new T[--n];
	for (int i = 0; i < n; i++)crr[i] = arr[i + 1];
	delete[] arr;
	return crr;
}
template <typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	//1) удаляем строку из памяти 
	delete[] arr[rows - 1];
	// 2) перераспределяем массив указателей:
	T** buffer = new T * [--rows];
	// 3) копируем адреса строк в новый массив: 
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	//4) удаляем исходный массив указателей: 
	delete[] arr;
	//5) возвращаем на место вызова 
	return buffer;
	/*int** buffer = new int* [rows + 1] {};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	rows--;
	return buffer;*/
}
template <typename T>T** pop_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T * [rows - 1];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;

	/*int** buffer = new int* [rows + 1] {};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i+1];
	delete[] arr;
	rows--;
	return buffer;*/
}
template <typename T>void pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template <typename T>void pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}