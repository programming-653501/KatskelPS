//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <conio.h>
#include <time.h>
#define M_PI 3.141592

using namespace std;

double sin_iter(double x, double eps, int* n);
double sin_rec(double sum, double x, double eps, int* n);
long long int factorial(int n);
int input_check(char *input_str);

int main()
{
	int *n = new int();
	double x, sum, eps;
	char* input_string = new char[30];
	clock_t time1, time2;
	cout << "Separator: \".\"" << endl;
	cout << "Input x: ";
	cin >> input_string;
	while (input_check(input_string) == 0)
	{
		cout << "Input error. Try again: ";
		cin >> input_string;
	}
	x = atof(input_string);
	while (x > 2 * M_PI)
		x -= 2 * M_PI;
	while (x < -2 * M_PI)
		x += 2 * M_PI;
	cout << "sin(x) = " << sin(x) << endl;
	cout << "Input measure error (eps) : ";
	cin >> input_string;
	while (input_check(input_string) == 0 || atof(input_string)==0)
	{
		cout << "Input error. Try again: ";
		cin >> input_string;
	}
	eps = atof(input_string);
	cout << endl << "Iteration function: " << endl;
	time1 = clock();
	sum = sin_iter(x, eps, n);
	time2 = clock();
	cout << "Value n for which |sin(x)-Teylor_sum|<eps = " << ((*n) + 1) / 2 << endl;
	cout << "Value of Teylor_sum: " << sum << endl;
	cout << "Elapsed time: " << (time2 - time1) / CLOCKS_PER_SEC << endl;

	cout << endl << "Recursive function" << endl;
	*n = 1;
	time1 = clock();
	sum = sin_rec(x, x, eps, n);
	time2 = clock();
	cout << "Value n for which |sin(x)-Teylor_sum|<eps = " << ((*n) + 1) / 2 << endl;
	cout << "Value of Teylor_sum: " << sum << endl;
	cout << "Elapsed time: " << 1000.0*(time2 - time1) / CLOCKS_PER_SEC << endl;

	_getch();
	delete[] input_string;
    return 0;
}



double sin_iter(double x, double eps, int* n)
{
	int product = 1;
	double sum = x, summand = x;

	*n = 1;
	while (abs(sum - sin(x)) > eps)
	{
		summand *= (-x*x) / (((*n) + 1)*((*n) + 2));
		sum += summand;
		(*n) += 2;
	}
	return sum;
}

double sin_rec(double sum, double x, double eps, int* n)
{
	if (abs(sum - sin(x)) < eps)
		return sum;
	else
	{
		(*n) += 2;
		if (*n > 21)
			return sum;
		if ((*n) % 4 == 1)
			sum += pow(x, *n) / factorial(*n);
		else
			sum -= pow(x, *n) / factorial(*n);
		return sin_rec(sum, x, eps, n);
	}
}

long long int factorial(int n)
{
	long long int pr = 1;
	for (int i = 2; i <= n; i++)
	{
		pr *= i;
	}
	return pr;
}

int input_check(char *input_str)
{
	int i, count = 0;

	for (i = 0; i < (int)strlen(input_str); i++)
	{
		if (input_str[i]!='-' && input_str[i] != '.' && (input_str[i] > '9' || input_str[i] < '0'))
			return 0;
		if (input_str[i] == '.')
			count++;
	}
	if (count > 1)
		return 0;
	if (atof(input_str) == NULL && strcmp(input_str, "0")!=0)
		return 0;
	else if (atof(input_str) < 0)
		return 0;
	else
		return 1;
}

