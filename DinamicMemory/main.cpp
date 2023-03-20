#include <iostream>

using namespace std;

using std::cout; 
using std::cin; 
using std::endl; 

void FillRand(int arr [], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr [], const int n);
void Print(int** arr, const int rows, const int cols);

int* Push_back(int arr[], int& n, int value);
int* Pop_back(int arr[], int& n, int value); 
int* push_front(int arr[], int& n, int value);
int* pop_front(int arr[], int& n, int value);
int* insert(int arr[], int& n, int value, int index);
int* erase(int arr[], int& n, int value, int index);

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
	cout << "Введите количество строк "; cin >> rows;
	cout << "Введите количество элементов строки "; cin >> cols;

	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;




#endif // DINAMO_MEMORY2

}
void FillRand(int arr [], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;// обращение к элементам массива через
		// арифметику указателей и оператор разыменования  
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
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
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int* Push_back(int arr[], int& n, int value) // произвести передачу по ссылке и ставим &
{
	//1)создать новый массив, выделить область памяти, нужного размера: 
	int* brr = new int[n + 1];// buffer 
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
int* Pop_back(int arr[], int& n, int value)
{
	int* buffer = new int[n+1];
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
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)buffer[i+1] = arr[i]; 
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
int* pop_front(int arr[], int& n, int value)
{
	int* crr = new int[--n];
	for (int i = 0; i < n; i++)crr[i] = arr[i+1];
	delete[] arr;
	return crr; 
}
int* insert(int arr[], int& n, int value, int index)
{
	int* buffer = new int[++n];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	buffer [index] = value;
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
int* erase(int arr[], int& n, int value, int index)
{
	int* buffer = new int[--n];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	buffer[index] = value;
	for (int i = index; i < n; i++)buffer[i] = arr[i+1];
	delete[] arr;
	arr = buffer;
	return buffer;
}