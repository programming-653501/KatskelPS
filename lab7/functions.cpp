#include "stdafx.h"
#include "functions.h"
#include <cstdlib>
#include <conio.h>

void menuAddStudent(studentsList* list)
{
	int _studNumber;
	printf("������� ����� ������������� ������ (0 ���� ������ ����� � ����): ");
	scanf("%d", &_studNumber);
	while (findStudent(_studNumber, list) && _studNumber!=0)
	{
		printf("����� ������� ��� ����. ������� ������ ����� ������: ");
		scanf("%d", &_studNumber);
	}
	if (_studNumber)
	{
		char name[30], surname[30], patronymic[30];
		float score;
		printf("������� ������� ��������: ");
		scanf("%s", surname);
		printf("������� ��� ��������: ");
		scanf("%s", name);
		printf("������� �������� ��������: ");
		scanf("%s", patronymic);
		printf("������� ������� ���� ��������: ");
		scanf("%f", &score);
		student newStudent = { name, surname, patronymic, _studNumber, score, not, 0 };
		newStudent.CountScholarship();
		list->AddStudent(newStudent);
	}
	while (getchar() != '\n') {}
	system("cls");

}

student* findStudent(int studNumber, studentsList *list)
{

	student* iterator = list->head;
	while (iterator)
	{
		if (iterator->studentNumber == studNumber)
			return iterator;
		iterator = iterator->next;
	}
	return NULL;
}

void menuShowStudent(studentsList * list)
{
	int _studNumber;
	student *newStudent;
	printf("������� ����� ������������� ������ (0 ���� ������ ����� � ����): ");
	scanf("%d", &_studNumber);
	while (!(newStudent=findStudent(_studNumber, list)) && _studNumber != 0)
	{
		printf("������ �������� ���. ������� ������ ����� ������: ");
		scanf("%d", &_studNumber);
	}
	if (newStudent)
	{
		newStudent->ShowStudent();
		_getch();
	}
	while (getchar() != '\n') {}
	system("cls");
}

void menuEditStudent(studentsList * list)
{
	int _studNumber;
	student *findStud;
	printf("������� ����� ������������� ������ (0 ���� ������ ����� � ����): ");
	scanf("%d", &_studNumber);
	while (!(findStud = findStudent(_studNumber, list)) && _studNumber != 0)
	{
		printf("������ �������� ���. ������� ������ ����� ������: ");
		scanf("%d", &_studNumber);
	}
	if (findStud)
	{
		char name[30], surname[30], patronymic[30];
		float score;
		printf("������� ������� ��������: ");
		scanf("%s", surname);
		printf("������� ��� ��������: ");
		scanf("%s", name);
		printf("������� �������� ��������: ");
		scanf("%s", patronymic);
		printf("������� ������� ���� ��������: ");
		scanf("%f", &score);
		student newStudent = { name, surname, patronymic, _studNumber, score, not, 0 };
		findStud->EditStudent(&newStudent);
		findStud->CountScholarship();
	}
	while (getchar() != '\n') {}
	system("cls");
}

void menuDeleteStudent(studentsList * list)
{
	int _studNumber;
	student *findStud;
	printf("������� ����� ������������� ������ (0 ���� ������ ����� � ����): ");
	scanf("%d", &_studNumber);
	while (!(findStud = findStudent(_studNumber, list)) && _studNumber != 0)
	{
		printf("������ �������� ���. ������� ������ ����� ������: ");
		scanf("%d", &_studNumber);
	}
	if (findStud)
	{
		list->DeleteStudent(findStud);
	}
	while (getchar() != '\n') {}
	system("cls");
}

void ShowAllWithParams(studentsList * list, bool(*comparator)(student *student))
{
	student *iterator = list->head;
	while (iterator)
	{
		if (comparator(iterator))
			iterator->ShowStudent();
		iterator = iterator->next;
	}
	_getch();
	system("cls");
}

bool HaveScholarship(student * student)
{
	return student->kind != 0;
}

bool HaveHighScholarship(student *student)
{
	return student->kind > 1;
}

bool HavePremium(student * student)
{
	return student->havePremium;
}

void ShowScholarshipAmount(Amount amount)
{
	printf("������� ���������:\n");
	printf("5-6 ������ : %f ������\n", amount.money56);
	printf("6-8 ������ : %f ������\n", amount.money68);
	printf("8-9 ������ : %f ������\n", amount.money89);
	printf("9-10 ������ : %f ������\n", amount.money910);
	printf("������� ��������� : %f ������\n", amount.moneyNominal);
	printf("��������� ������ ����: %f ������\n", amount.moneyUniversity);
	printf("���������� ��������: %f ������\n", amount.moneyPremium);

}

void ChangeScholarship(studentsList * list, int type)
{
	int _studNumber;
	int choice;
	student *findStud;
	printf("������� ����� ������������� ������ (0 ���� ������ ����� � ����): ");
	scanf("%d", &_studNumber);
	while (!(findStud = findStudent(_studNumber, list)) && _studNumber != 0)
	{
		printf("������ �������� ���. ������� ������ ����� ������: ");
		scanf("%d", &_studNumber);
	}
	if (findStud)
	{
		printf("�������� ���� �� ��������:\n");
		printf("1.����� ���������\n");
		printf("2.�������� ���������\n");
		scanf("%d", &choice);
		switch (type)
		{
		case 1: if (choice == 1)
					findStud->kind = standart;
				else
					findStud->kind = nominal;
			break;
		case 2:
			if (choice == 1)
				findStud->kind = standart;
			else
				findStud->kind = university;
			break;
		case 3:
			if (choice == 1)
				findStud->havePremium = false;
			else
				findStud->havePremium = true;
			break;
		}
	}
	findStud->CountScholarship();
	while (getchar() != '\n') {}
	system("cls");
}

void SaveToFile(studentsList * list)
{
	student addStudent, *iterator = list->head;
	FILE* output = fopen("data.txt", "w");
	while (iterator)
	{
		addStudent = (*iterator);
		fwrite(&addStudent, sizeof(student), 1, output);
		iterator = iterator->next;
	}
	fclose(output);
}

void LoadFromFile(studentsList * list)
{
	student addStudent;
	FILE* input = fopen("data.txt", "r");
	if (input)
	{
		while (!feof(input))
		{
			fread(&addStudent, sizeof(student), 1, input);
			list->AddStudent(addStudent);
		}
		fclose(input);
	}
}




