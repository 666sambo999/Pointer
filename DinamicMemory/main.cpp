#include <iostream>

using namespace std;

using std::cout; 
using std::cin; 
using std::endl; 

int** Allocate(int rows, int cols); 
void Clear(int** arr, int rows); 

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

int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols); 
int** Insert(int** arr, int& rows, const int cols, int index); 

int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols); 
int** erase_row(int** arr, int& rows, const int cols, int in);

void push_col_back(int** arr, const int rows, int& cols);
void push_col_front(int** arr, const int rows, int& cols);
void insert_col(int** arr, const int rows, int& cols, int a);

void pop_col_back(int** arr, const int rows, int& cols);
void pop_col_front(int** arr, const int rows, int& cols);
void erase_col (int** arr, const int rows, int& cols, int b);


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
	
	int** arr = Allocate(rows, cols);
		
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
int** Allocate(int rows, int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr; 
}
void Clear(int** arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
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
			//cout << arr[i][j] << "\t";
			cout << *(*(arr +i) +j) << "\t";
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
int** push_row_back(int** arr, int& rows, const int cols)
{
	//1) Перераспределяем массив указателей
	int** buffer = new int* [rows + 1] {};
	// 2) копируем адреса строк из исходного массива указателей в новый
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	// 3) удаляем старый массив указаителей
	delete[] arr;
	//4) добавляем новую строку в массив 
	buffer[rows] = new int [cols] {};
	//5) После добавления строки, кол-во строк увеличевается на 1
	rows++;
	// 6) возвращаем новый массив на место вызова
	return buffer;
}
int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1] {};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	buffer[0] = new int [cols] {};
	rows++;
	return buffer;
}
int** Insert(int** arr, int& rows, const int cols, int index)
{
	int** buffer = new int* [rows + 1] {};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	buffer[index] = new int [cols] {};
	for (int i = index; i < rows; i++)buffer[i+1] = arr[i];
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
int** pop_row_back(int** arr, int& rows, const int cols)
{
	//1) удаляем строку из памяти 
	delete[] arr[rows - 1];
	// 2) перераспределяем массив указателей:
	int** buffer = new int* [rows - 1]; \
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
int** pop_row_front(int** arr, int& rows, const int cols)
{
	delete[] arr[0];
	int** buffer = new int* [rows - 1]; 
	for (int i = 0; i < rows; i++)buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
		
	/*int** buffer = new int* [rows + 1] {};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i+1];
	delete[] arr;
	rows--;
	return buffer;*/
}
int** erase_row(int** arr, int& rows, const int cols, int in)
{
	delete[] arr[in];
	int** buffer = new int* [rows - 1];
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
void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int [cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++; 
}
void push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int [cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j+1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
//
void insert_col(int** arr, const int rows, int& cols, int a)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int [cols+1] {};
		for (int j = 0; j < a; j++)buffer[j] = arr[i][j];
		for (int j = a; j < cols; j++)buffer[j+1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void pop_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int [cols +1] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void pop_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int [cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j+1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void erase_col(int** arr, const int rows, int& cols, int b)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int [cols-1] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		for (int j = b; j < cols; j++)buffer[j] = arr[i][j+1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}

