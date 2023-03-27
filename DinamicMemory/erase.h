#pragma once
#include "stdafx.h"

template <typename T>T* erase(T arr[], int& n, int value, T index);
template <typename T>T** erase_row(T** arr, int& rows, const int cols, T in);
template <typename T>void erase_col(T** arr, const int rows, int& cols, T b);
