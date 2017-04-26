#pragma once
#include "stdafx.h"
#include "student.h"


void menuAddStudent(studentsList* list);
student* findStudent(int studNumber, studentsList *list);
void menuShowStudent(studentsList *list);
void menuEditStudent(studentsList *list);
void menuDeleteStudent(studentsList *list);
void ShowAllWithParams(studentsList *list, bool (*comparator)(student *student));
bool HaveScholarship(student *student);
bool HaveHighScholarship(student *student);
bool HavePremium(student *student);
void ShowScholarshipAmount(Amount amount);
void ChangeScholarship(studentsList* list, int type);
void SaveToFile(studentsList *list);
void LoadFromFile(studentsList* list);

