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
		printf("������ �� ����������. �������� ���� �� ��������:\n");
		printf("1.�������� ������ �������� � ������\n");
		printf("2.�������� ������ ��������\n");
		printf("3.������� �������� �� ������\n");
		printf("4.����������� ������ ��������� �� ������\n");
		printf("5.����� � ������� ����\n");
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
		printf("����������/������ �������������� ���������. �������� ���� �� ��������:\n");
		printf("1.������� ���������\n");
		printf("2.��������� ������ ����\n");
		printf("3.���������� ��������\n");
		printf("4.����� � ������� ����\n");
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
		printf("������ � �����������. �������� ���� �� ��������:\n");
		printf("1.������ ������� ������ ��������� �� �����������\n");
		printf("2.������ ��������� � ����������� �����������\n");
		printf("3.������ ��������� � ����������� ����������\n");
		printf("4.����� � ������� ����\n");
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
		printf("������ �� ��������. �������� ���� �� ��������:\n");
		printf("1.�������� �������� ���������\n");
		printf("2.����� � ������� ����\n");
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
	printf("���� ������:\n");
	printf("1.���� ������ �� ���������� ��������� ���������, ������� � �������� ������ ������ ���������\n");
	printf("2.���� ���������� ���. ��������� ��������� ��������� ��������� �������������� ���� ���������, � ����� ������� ��\n");
	printf("3.���� ������ � ����������� ��������� ����������� ������ ��������� �� �����������,\n ������ ��������� � ���. ����������, � ����� ���, ��� �������� ����������� �����������\n");
	printf("4.���� ������ � ��������� ��������� ��������� ������������� ������� ������ ���������, � ����� �������� ��\n");
	printf("\n������� ����� ������� ��� ������ � ������� ����...");
	_getch();
	system("cls");
}

void mainMenu()
{
	int choise=0;
	while (choise != 6)
	{

		printf("������� ����. �������� ���� �� ��������� ��������:\n");
		printf("1.���� ������ �� ����������\n");
		printf("2.���� ���������� ���. ���������\n");
		printf("3.���� ������ � �����������\n");
		printf("4.���� ������ � ��������� ���������\n");
		printf("5.���� ������\n");
		printf("6.�����\n");
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
		printf("������ �����. ���������� ��� ���:\n");
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
