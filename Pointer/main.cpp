#include <iostream>
using namespace std;
//#define POINTER_BASICS


void main()
{
	setlocale(LC_ALL, "");
	
#ifdef POINTER_BASICS
	int a = 2;
	int* pa = &a; // pa - Pointer to 'a' (��������� �� ���������� "�")
	cout << a << endl; // ����� �������� ���������� � �� �����
	cout << &a << endl; // ������ ������ ���������� "�" ����� ��� ������ 
	cout << pa << endl; // ����� ������ ���������� "�", ����������� � ��������� "��"
	cout << *pa << endl; //������������� ��������� "��" ��� ���� ����� �������� �������� �� ������ 


	int* pb;  // int* - ��������� �� int
	int b = 3;
	pb = &b;

#endif // POINTER_BASICS

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl; 
	cout << *arr << endl; 
	for (int i = 0; i < n; i++)
	{
		cout << arr + i << "\t"; // ����� �������� ��������, ����� ������������ 
		cout << *(arr + i) << "\t";
	}
	cout << endl; 


}

/*
-----------------------------------------
& - �������� ������ ������ (Address-jf operator)
* - �������� ��������������� (Dereference operator)
=============================================
*/