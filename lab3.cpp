// lab3.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>
#include <conio.h>

using namespace std;

void scan_spiral(int**, int, int, int, int*);
void reverse(int*, int);
int input_check(char *input_str);

int main()
{
	int n;
	char* input_string = new char[30];
	cout << "Input odd n: " << endl;
	cin >> input_string;
	while (input_check(input_string) == 0 || atoi(input_string) % 2 != 1 || atoi(input_string) <= 0)
	{
		cout << "Input error. Try again: ";
		cin >> input_string;
	}
	n = atoi(input_string);
	int **array = new int*[n];
	for (int i = 0; i<n; i++)
		array[i] = new int[n];
	int *scan_array = new int[n*n];
	cout << "Input array:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "array[" << i << "][" << j << "]: ";
			cin >> input_string;
			while (input_check(input_string) == 0)
			{
				cout << "Input error. Try again: ";
				cin >> input_string;
			}
			array[i][j] = atoi(input_string);
		}
	}
	scan_spiral(array, 0, n, 0, scan_array);
	reverse(scan_array, n*n);
	cout << "New array" << endl;
	for (int i = 0; i < n*n; i++)
	{
		cout << scan_array[i] << " ";
	}
	_getch();
	delete[] input_string;
	return 0;
}

void scan_spiral(int** array, int position, int length, int current, int* scan_array)
{
	if (length>2)
	{
		int i;
		for (i = position; i<position + length; i++)
			scan_array[current++] = array[position][i];
		for (i = position + 1; i < position + length; i++)
			scan_array[current++] = array[i][position + length - 1];
		for (i = position + length - 2; i >= position; i--)
			scan_array[current++] = array[position + length - 1][i];
		for (i = position + length - 2; i>position; i--)
			scan_array[current++] = array[i][position];
		scan_spiral(array, position + 1, length - 2, current, scan_array);
	}
	else
	{
		if (length == 1)
			scan_array[current++] = array[position][position];
		if (length == 2)
		{
			scan_array[current++] = array[position][position];
			scan_array[current++] = array[position][position+1];
			scan_array[current++] = array[position+1][position+1];
			scan_array[current++] = array[position+1][position];
		}
	}
}

void reverse(int* array, int size)
{
	int temp;
	for (int i = 0; i <= size/2; i++)
	{
		temp = array[i];
		array[i] = array[size - 1 - i];
		array[size - 1 - i] = temp;
	}
}

int input_check(char *input_str)
{
	int i;

	for (i = 0; i < (int)strlen(input_str); i++)
	{
		if (input_str[i] != '-' && (input_str[i] > '9' || input_str[i] < '0'))
			return 0;
	}

	if (atoi(input_str) == NULL && strcmp(input_str, "0")!=0)
		return 0;
	else
		return 1;
}













