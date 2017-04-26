#include "stdafx.h"
#include "student.h"
#include <cstring>



student::student(char* _name, char* _surname, char* _patronymic, int _number, float _score, scholarshipKind _kind, bool _have)
{
	strcpy_s(name, 30, _name);
	strcpy_s(surname, 30, _surname);
	strcpy_s(patronymic, 30, _patronymic);
	studentNumber = _number;
	averageScore = _score;
	kind = _kind;
	havePremium = _have;
}

student::student()
{
	strcpy_s(name, 30, "");
	strcpy_s(surname, 30, "");
	strcpy_s(patronymic, 30, "");
	studentNumber = 0;
	averageScore = 0;
	kind = standart;
	havePremium = false;
}

void student::EditStudent(student* newStudent)
{
	strcpy(name, newStudent->name);
	strcpy(surname, newStudent->surname);
	strcpy(patronymic, newStudent->patronymic);
	averageScore = newStudent->averageScore;
	kind = newStudent->kind;
	havePremium = newStudent->havePremium;
}


void studentsList::AddStudent(student newStudent)
{
	student *item = new student();
	*item = newStudent;
	item->next = item->prev = NULL;
	if (!head)
		head = tail = item;
	else
	{
		tail->next = item;
		item->prev = tail;
		tail = item;
	}
	studentsNumber++;
}

void studentsList::DeleteStudent(student* newStudent)
{
	if (newStudent)
	{
		if (this->studentsNumber == 1)
		{
			this->head = this->tail = NULL;
		}
		else
		{
			if (newStudent == head)
			{
				head->next->prev = NULL;
				head = head->next;
			}
			else if (newStudent == tail)
			{
				tail->prev->next = NULL;
				tail = tail->prev;
			}
			else
			{
				newStudent->next->prev = newStudent->prev;
				newStudent->prev->next = newStudent->next;
			}
		}
		delete newStudent;
		studentsNumber--;
	}
}

void studentsList::printAll()
{
	student* iterator = head;
	while (iterator)
	{
		iterator->ShowStudent();
		iterator = iterator->next;
	}
}

void student::CountScholarship()
{
	Amount money;
	if (averageScore >= 5 && kind == not)
		kind = standart;
	switch (kind)
	{
	case not: scholarshipAmount = 0; break;
	case university: scholarshipAmount = money.moneyUniversity; break;
	case nominal: scholarshipAmount = money.moneyNominal; break;
	case standart:
		if (averageScore >= 9)
			scholarshipAmount = money.money910;
		else if (averageScore >= 8)
			scholarshipAmount = money.money89;
		else if (averageScore >= 6)
			scholarshipAmount = money.money68;
		else if (averageScore >= 5)
			scholarshipAmount = money.money56;
		else
			scholarshipAmount = 0;
		break;
	}
	if (havePremium)
		scholarshipAmount += money.moneyPremium;
}

void student::ShowStudent()
{
	printf("\n");
	printf("�������: %s\n", surname);
	printf("���: %s\n", name);
	printf("��������: %s\n", patronymic);
	printf("������� ����: %f\n", averageScore);
	switch (kind)
	{
	case not: printf("��� ���������\n"); break;
	case standart: printf("���� ����������� ���������\n"); break;
	case university: printf("���� ��������� ������ ����"); break;
	case nominal: printf("���� ������� ���������\n"); break;
	}
	if(havePremium)
		printf("���� ���������� ��������\n");
}

