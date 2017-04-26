#include "stdafx.h"
#include "functions.h"
#include <cstdlib>
#include <conio.h>

void menuAddStudent(studentsList* list)
{
	int _studNumber;
	printf("Введите номер студенческого билета (0 если хотите выйти в меню): ");
	scanf("%d", &_studNumber);
	while (findStudent(_studNumber, list) && _studNumber!=0)
	{
		printf("Такой студент уже есть. Введите другой номер билета: ");
		scanf("%d", &_studNumber);
	}
	if (_studNumber)
	{
		char name[30], surname[30], patronymic[30];
		float score;
		printf("Введите фамилию студента: ");
		scanf("%s", surname);
		printf("Введите имя студента: ");
		scanf("%s", name);
		printf("Введите отчество студента: ");
		scanf("%s", patronymic);
		printf("Введите средний балл студента: ");
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
	printf("Введите номер студенческого билета (0 если хотите выйти в меню): ");
	scanf("%d", &_studNumber);
	while (!(newStudent=findStudent(_studNumber, list)) && _studNumber != 0)
	{
		printf("Такого студента нет. Введите другой номер билета: ");
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
	printf("Введите номер студенческого билета (0 если хотите выйти в меню): ");
	scanf("%d", &_studNumber);
	while (!(findStud = findStudent(_studNumber, list)) && _studNumber != 0)
	{
		printf("Такого студента нет. Введите другой номер билета: ");
		scanf("%d", &_studNumber);
	}
	if (findStud)
	{
		char name[30], surname[30], patronymic[30];
		float score;
		printf("Введите фамилию студента: ");
		scanf("%s", surname);
		printf("Введите имя студента: ");
		scanf("%s", name);
		printf("Введите отчество студента: ");
		scanf("%s", patronymic);
		printf("Введите средний балл студента: ");
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
	printf("Введите номер студенческого билета (0 если хотите выйти в меню): ");
	scanf("%d", &_studNumber);
	while (!(findStud = findStudent(_studNumber, list)) && _studNumber != 0)
	{
		printf("Такого студента нет. Введите другой номер билета: ");
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
	printf("Размеры стипендий:\n");
	printf("5-6 баллов : %f рублей\n", amount.money56);
	printf("6-8 баллов : %f рублей\n", amount.money68);
	printf("8-9 баллов : %f рублей\n", amount.money89);
	printf("9-10 баллов : %f рублей\n", amount.money910);
	printf("Именная стипендия : %f рублей\n", amount.moneyNominal);
	printf("Стипендия совета ВУЗа: %f рублей\n", amount.moneyUniversity);
	printf("Социальная надбавка: %f рублей\n", amount.moneyPremium);

}

void ChangeScholarship(studentsList * list, int type)
{
	int _studNumber;
	int choice;
	student *findStud;
	printf("Введите номер студенческого билета (0 если хотите выйти в меню): ");
	scanf("%d", &_studNumber);
	while (!(findStud = findStudent(_studNumber, list)) && _studNumber != 0)
	{
		printf("Такого студента нет. Введите другой номер билета: ");
		scanf("%d", &_studNumber);
	}
	if (findStud)
	{
		printf("Выберите одно из действий:\n");
		printf("1.Снять стипендию\n");
		printf("2.Добавить стипендию\n");
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




