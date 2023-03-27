#include "Push.h"


template <typename T>T* Push_back(T arr[], int& n, int value) // ���������� �������� �� ������ � ������ &
{
	//1)������� ����� ������, �������� ������� ������, ������� �������: 
	T* brr = new T[n + 1];// buffer 
	// 2) �������� ��� ���������� ��������� ���c��� � �����:
	for (int i = 0; i < n; i++)
	{
		brr[i] = arr[i];
	}
	// 3) ������� �������� ������:
	delete[] arr;
	// 4) ��������� ��������� ������� ������� �� �����:
	arr = brr; //  ��� ���������� �������� ����������� 
	// 5) ������ ����� ����� � ������� arr ���������� �������, � ������� ����� ��������� �������� 
	arr[n] = value;
	// 6) ����� ���������� � ������, ���-�� ��� ��������� ������������� �� 1
	n++;
	//7)  ���������� 
	return arr; // ���������� ����� ������ 
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
// 2 ������� 
//int* push_front(int arr[], int& n, int value)
//{
//	int* buffer = new int[n + 1];//
//	for (int i = 0; i < n; i++)buffer[i + 1] = arr[i];// �������� �� ���������
//	delete[] arr; // ������� ������
//	buffer[0] = value; // �������� ����������� ������� � ������ �������
//	n++; // 
//	return buffer; // ���������� ������ 
//}
template <typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	//1) ���������������� ������ ����������
	T** buffer = new T * [rows + 1] {};
	// 2) �������� ������ ����� �� ��������� ������� ���������� � �����
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	// 3) ������� ������ ������ �����������
	delete[] arr;
	//4) ��������� ����� ������ � ������ 
	buffer[rows] = new T[cols]{};
	//5) ����� ���������� ������, ���-�� ����� ������������� �� 1
	rows++;
	// 6) ���������� ����� ������ �� ����� ������
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