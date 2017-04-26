// lab7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include "student.h"
#include "menu.h"
#include "functions.h"
#include <Windows.h>
studentsList Mylist;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	LoadFromFile(&Mylist);
	mainMenu();
	SaveToFile(&Mylist);
    return 0;
}

