#include <iostream>

using namespace std;
void FillRand(int arr [], const int n);
void Print(int arr [], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n; 
	cout << "Введите размер массива: "; cin >> n; 
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n); 
	int value;
	cout << "Введите значение добавляемого элемента: "; cin >> value; 
	//1)создать новый массив, выделить область памяти, нужного размера: 
	int* brr = new int[n+1];// buffer 
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
	Print(arr, n);
	delete[] arr;


}
void FillRand(int arr [], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;// обращение к элементам массива через
		// арифметику указателей и оператор разыменования  
	}
}
void Print(int arr [], const int n)
{
	for (int i = 0; i < n; i++)
	{
		// обращение к элементам массива через оператор индексирования
		cout << arr[i] << "\t";
	}
	cout << endl;
}