#include <iostream>

using namespace std;

void FillRand(int* arr, const int n);
void Print(int* arr, const int n);
void Search(int* arr, int& a, int& b, const int n);
void Split(int* arr, int* arr_even, int* arr_odd, const int n);

void main()
{
	setlocale(LC_ALL, "");

	const int n =15; 
    int arr[n];
    int a = 0;
    int b = 0;
    FillRand(arr, n);
    Print(arr, n);
    Search(arr, a, b,n);
    
    int* arr_even = new int[a]; // четные числа
    int* arr_odd = new int[b]; // нечетные числа
    Split(arr, arr_even, arr_odd, n);
    Print(arr_even, a);
    Print(arr_odd, b);
      
    delete[] arr_even; 
    delete[] arr_odd; 
    
}
void FillRand(int* arr, const int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
      cout << endl; 
}
void Search(int* arr, int& a, int& b, const int n) //поиск четных и нечетных чисел
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            a++;
        }
        else
        {
            b++;
        }
    }
    cout << " Четных элементов : " << a << endl;
    cout << " Не четных элементов : " << b << endl;
}
void Split(int* arr, int* arr_even, int* arr_odd, const int n)
{
    int с = 0, d = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0) // отлавливаем четные и записываем их в новый массив
        {
            arr_even[с] = arr[i];
            с++;
        }
        else                            // отлавливаем нечетные и записываем их в новый массив
        {
            arr_odd[d] = arr[i];
            d++;
        }
    }
}

void Print(int* arr, const int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}