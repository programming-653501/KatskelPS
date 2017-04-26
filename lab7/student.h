#pragma once

#include "stdafx.h"
#include <cstring>

enum scholarshipKind {
	not,
	standart,
	university,
	nominal
};

struct Amount{
	float money56 = (float)78.862;
	float money68 = (float)94.634;
	float money89 = (float)110.405;
	float money910 = (float)126.179;
	float moneyUniversity = (float)135.00;
	float moneyNominal = (float)181.00;
	float moneyPremium = (float)45.00;
};

struct student {
	char name[30];
	char surname[30];
	char patronymic[30];
	int studentNumber;
	float averageScore;
	float scholarshipAmount;
	bool havePremium;
	scholarshipKind kind;
	student *next;
	student *prev;
	student(char* _name, char* _surname, char* _patronymic, int _number, float _score, scholarshipKind _kind, bool _have);
	student();
	void EditStudent(student* newStudent);
	void CountScholarship();
	void ShowStudent();
};

struct studentsList {
	student *head = NULL;
	student *tail = NULL;
	int studentsNumber = 0;
	void AddStudent(student newStudent);
	void DeleteStudent(student* newStudent);
	void printAll();
};
