#include "stdafx.h"
#include "menu.h"
#include <cstdlib>
#include <conio.h>
#include <string.h>
#include <cstdio>
#include "functions.h"
extern studentsList Mylist;
Amount amount;

void workWithStudents()
{
	int choise = 0;
	while (choise != 5)
	{
		printf("Работа со студентами. Выберите одно из действий:\n");
		printf("1.Добавить нового студента в список\n");
		printf("2.Изменить данные студента\n");
		printf("3.Удалить студента из списка\n");
		printf("4.Просмотреть данные студентов из списка\n");
		printf("5.Выход в главное меню\n");
		choise = inputMenu(5);
		system("cls");
		switch (choise)
		{
		case 1: menuAddStudent(&Mylist); break;
		case 2: menuEditStudent(&Mylist); break;
		case 3: menuDeleteStudent(&Mylist); break;
		case 4: Mylist.printAll(); break;
		default: break;
		}
	}
}

void workWithScholarships()
{
	int choise = 0;
	while (choise != 4)
	{
		printf("Начисление/снятие дополнительных стипендий. Выберите одно из действий:\n");
		printf("1.Именная стипендия\n");
		printf("2.Стипендия совета ВУЗа\n");
		printf("3.Социальная надбавка\n");
		printf("4.Выход в главное меню\n");
		choise = inputMenu(4);
		system("cls");
		switch (choise)
		{
		case 1: ChangeScholarship(&Mylist, 1); break;
		case 2: ChangeScholarship(&Mylist, 2); break;
		case 3: ChangeScholarship(&Mylist, 3); break;
		default: break;
		}
	}
}

void workWithReports()
{
	int choise = 0;
	while (choise != 4)
	{
		printf("Работа с ведомостями. Выберите одно из действий:\n");
		printf("1.Печать полного списка студентов со стипендиями\n");
		printf("2.Печать студентов с повышенными стипендиями\n");
		printf("3.Печать студентов с социальными надбавками\n");
		printf("4.Выход в главное меню\n");
		choise = inputMenu(4);
		system("cls");
		switch (choise)
		{
		case 1: ShowAllWithParams(&Mylist, HaveScholarship); break;
		case 2: ShowAllWithParams(&Mylist, HaveHighScholarship); break;
		case 3: ShowAllWithParams(&Mylist, HavePremium); break;
		default: break;
		}
	}
}

void workWithMoney()
{
	int choise = 0;
	while (choise != 2)
	{
		printf("Работа со ставками. Выберите одно из действий:\n");
		printf("1.Просмотр величины стипендий\n");
		printf("2.Выход в главное меню\n");
		choise = inputMenu(2);
		system("cls");
		switch (choise)
		{
		case 1: ShowScholarshipAmount(amount); break;
		default: break;
		}
	}
}

void help()
{
	printf("Меню помощи:\n");
	printf("1.Меню работы со студентами позволяет добавлять, удалять и изменять данные списка студентов\n");
	printf("2.Меню начисления доп. стипендий позволяет начислять студентам дополнительные виды стипендий, а также снимать их\n");
	printf("3.Меню работы с ведомостями позволяет просмотреть списки студентов со стипендиями,\n списки студентов с соц. надбавками, а также тех, кто обладает повышенными стипендиями\n");
	printf("4.Меню работы с размерами стипендий позволяет просматривать базовые ставки стипендий, а также изменять их\n");
	printf("\nНажмите любую клавишу для выхода в главное меню...");
	_getch();
	system("cls");
}

void mainMenu()
{
	int choise=0;
	while (choise != 6)
	{

		printf("Главное меню. Выберите одно из следующий действий:\n");
		printf("1.Меню работы со студентами\n");
		printf("2.Меню начисления доп. стипендий\n");
		printf("3.Меню работы с ведомостями\n");
		printf("4.Меню работы с размерами стипендий\n");
		printf("5.Меню помощи\n");
		printf("6.Выход\n");
		choise = inputMenu(6);
		system("cls");
		switch (choise)
		{
		case 1: workWithStudents(); break;
		case 2: workWithScholarships(); break;
		case 3: workWithReports(); break;
		case 4: workWithMoney(); break;
		case 5: help(); break;
		default: break;
		}
	}
}

int inputMenu(int number)
{
	int flag, choise;
	char* input_string = new char[300];
	gets_s(input_string, 299);
	if (strlen(input_string) > 1)
		flag = 0;
	else  if (input_string[0] <= '0' || input_string[0] > '0' + number)
		flag = 0;
	else
		flag = 1;
	while (!flag)
	{
		printf("Ошибка ввода. Попробуйте ещё раз:\n");
		gets_s(input_string, 299);
		if (strlen(input_string) > 1)
			flag = 0;
		else  if (input_string[0] <= '0' || input_string[0] > '0' + number)
			flag = 0;
		else
			flag = 1;
	}
	choise = input_string[0] - '0';
	delete[] input_string;
	return choise;
}
