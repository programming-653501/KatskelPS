

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

int input_check(char* input_str);

int main()
{
	double ans;
	int ans_rub, ans_kopek;
	char *input_str = new char[20];

	cout << "Input number (parts should be separated by \".\"): " << endl;
	cin >> input_str;
	while (input_check(input_str) == 0)
	{
		cout << "Input error. Try again: " << endl;
		cin >> input_str;
	}
	ans = atof(input_str);
	ans_rub = (int)(round(ans * 100) / 100);
	if (ans_rub > ans)
		ans_kopek = 0;
	else
		ans_kopek = (int)(round((ans - ans_rub) * 100));
	cout << ans_rub << " r., " << ans_kopek << " kop.";

	delete[]input_str;
	_getch();
	return 0;
}

int input_check(char* input_str)
{
	int i, count = 0;

	for (i = 0; i < (int)strlen(input_str); i++)
	{
		if (input_str[i] != '.' && (input_str[i] > '9' || input_str[i] < '0'))
			return 0;
		if (input_str[i] == '.')
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

