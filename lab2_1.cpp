// lab2.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include <iostream>
#include <cstring>


using namespace std;

void menu();
int input_check(char* input_str, char max_symb);
int input_check(char *input_str);
void func_version();
void input_value();
void convert_rus();
void convert_uk();
void report();

double value_meters = 0.0;

int main()
{
	cout << "Hello. This is program to work with linear measures." << endl;
	menu();
    return 0;
}

void menu()
{
	int choise;
	char* input_str = new char[20];

	do
	{
		cout << "You have some options. Choose one of them:" << endl;
		cout << "1: Input value" << endl;
		cout << "2: Convert value into russian units" << endl;
		cout << "3: Convert value into British units" << endl;
		cout << "4: To output report with values in mm/cm/m/km" << endl;
		cout << "5: Info about program version and author" << endl;
		cout << "6: Exit" << endl;
		cin >> input_str;
		while (input_check(input_str, '6') == 0)
		{
			cout << "Input error. Try choose again: " << endl;
			cin >> input_str;
		}
		cout << endl;
		choise = atoi(input_str);
		switch (choise)
		{
		case 1: input_value(); break;
		case 2: convert_rus(); break;
		case 3: convert_uk(); break;
		case 4: report(); break;
		case 5: func_version(); break;
		case 6: break;
		}
	} while (choise != 6);
	delete[]input_str;
}

int input_check(char* input_str, char max_symb)
{
	if ((int)strlen(input_str) > 1)
		return 0;
	else if (input_str[0]<'1' || input_str[0]>max_symb)
		return 0;
	else
		return 1;
}

void func_version()
{
	cout << "Converter 1.0.0. Created by Pavel Katskel" << endl;
	cout << "All rights reserved." << endl << endl;
}

void input_value()
{
	int choise;
	char* input_str = new char[20];
	double value;

	cout << "Choose unit of length:" << endl;
	cout << "1: Meters" << endl;
	cout << "2: Kilometers" << endl;
	cout << "3: Millimeters" << endl;
	cout << "4: Centimeters" << endl;
	cin >> input_str;
	while (input_check(input_str, '4') == 0)
	{
		cout << "Input error. Try input choise again: " << endl;
		cin >> input_str;
	}
	choise = atoi(input_str);
	cout << "Input value: ";
	cin >> input_str;
	while (input_check(input_str) == 0)
	{
		cout << "Input error. Try input value again: " << endl;
		cin >> input_str;
	}
	value = atof(input_str);
	cout << endl;
	switch (choise)
	{
	case 1: value_meters = 1.0*value;
			break;
	case 2: value_meters = 1.0*value * 1000;
			break;
	case 3: value_meters = 1.0*value / 1000;
			break;
	case 4: value_meters = 1.0*value / 100;
			break;
	}
	delete[]input_str;
}

int input_check(char *input_str)
{
	int i, count = 0;

	for (i = 0; i < (int)strlen(input_str); i++)
	{
		if (input_str[i] != ',' && (input_str[i] > '9' || input_str[i] < '0'))
			return 0;
		if (input_str[i] == ',')
			count++;
	}
	if (count > 1)
		return 0;
	if (atof(input_str) == NULL)
		return 0;
	else if (atof(input_str) < 0)
		return 0;
	else
		return 1;
}

void convert_rus()
{
	double vershok = 0.04445;
	double arshin = 16 * vershok;
	double sazhen = 3 * arshin;
	double versta = 500 * sazhen;
	cout << "Your value in Russian units: " << endl;
	cout << "Versta: " << value_meters / versta << endl;
	cout << "Sazhen: " << value_meters / sazhen << endl;
	cout << "Arshin: " << value_meters / arshin << endl;
	cout << "Vershok: " << value_meters / vershok << endl;
	cout << endl;
}

void convert_uk()
{
	double inch = 0.0254;
	double foot = 12 * inch;
	double yard = 3 * foot;
	double mile = 1760 * yard;
	cout << "Your value in British units: " << endl;
	cout << "Mile: " << value_meters / mile << endl;
	cout << "Yard: " << value_meters / yard << endl;
	cout << "Foot: " << value_meters / foot << endl;
	cout << "Inch: " << value_meters / inch << endl;
	cout << endl;
}

void report()
{
	cout << "Your value in mm/cm/m/km: " << endl;
	cout << "Kilometer: " << value_meters / 1000 << endl;
	cout << "Meter: " << value_meters << endl;
	cout << "Centimeter: " << value_meters * 100 << endl;
	cout << "Millimeter: " << value_meters * 1000 << endl;
	cout << endl;
}
