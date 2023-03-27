#include "erase.h"

template <typename T>T* erase(T arr[], int& n, T value, T index)
{
	T* buffer = new T[--n];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	buffer[index] = value;
	for (int i = index; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
	return buffer;
}
template <typename T>T** erase_row(T** arr, int& rows, const int cols, T in)
{
	delete[] arr[in];
	T** buffer = new T * [rows - 1];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	for (int i = in; i < rows; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;

	/*int** buffer = new int* [rows + 1] {};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	for (int i = in; i < rows; i++)buffer[i] = arr[i+1];
	delete[] arr;
	rows--;
	return buffer;*/
}
template <typename T>void erase_col(T** arr, const int rows, int& cols, T b)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		for (int j = b; j < cols; j++)buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}