#include <iostream>
using namespace std;
//#define POINTER_BASICS


void main()
{
	setlocale(LC_ALL, "");
	
#ifdef POINTER_BASICS
	int a = 2;
	int* pa = &a; // pa - Pointer to 'a' (указатель на переменную "а")
	cout << a << endl; // Вывод значения переменной а на экран
	cout << &a << endl; // Взятия адреса переменной "а" прямо при выводе 
	cout << pa << endl; // вывод адреса переменной "а", хранящегося в указателе "ра"
	cout << *pa << endl; //разыменование указателя "ра" для того чтобы получить значение по адресу 


	int* pb;  // int* - указатель на int
	int b = 3;
	pb = &b;

#endif // POINTER_BASICS

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl; 
	cout << *arr << endl; 
	for (int i = 0; i < n; i++)
	{
		cout << arr + i << "\t"; // чтобы получить значение, нужно разыменовать 
		cout << *(arr + i) << "\t";
	}
	cout << endl; 


}

/*
-----------------------------------------
& - оператор взятия адреса (Address-jf operator)
* - оператор зфзыменовывания (Dereference operator)
=============================================
*/