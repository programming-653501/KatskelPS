// lab1.cpp: определяет точку входа для консольного приложения.
//
/*Составить программу, которая преобразует введенное с клавиатуры
дробное число в денежный формат. Например, число 12,348 должно
быть преобразовано в 12 руб. 35 коп. */

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

int input_check (char* input_str);

int main()
{
	double ans;
	int ans_rub, ans_kopek;
	char *input_str= new char [20];

	setlocale(LC_ALL, "Russian");
	cout << "Введите число (дробная часть через \",\"): " << endl;
	cin >> input_str;
	while (input_check(input_str) == 0)
	{
		cout << "Ошибка ввода. Попробуйте снова: " << endl;
		cin >> input_str;
	}
	ans = atof(input_str);
	ans_rub = (int)(round(ans * 100) / 100);
	if (ans_rub > ans)
		ans_kopek = 0;
	else
		ans_kopek = (int)(round((ans - ans_rub) * 100));
	cout << ans_rub << " руб., " << ans_kopek << " коп.";

	delete[]input_str;
	_getch();
    return 0;
}

int input_check(char* input_str)
{
	int i, count = 0;

	for (i = 0; i < (int)strlen(input_str); i++)
	{
		if (input_str[i] != ',' && (input_str[i] > '9' || input_str[i] < '0') )
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

