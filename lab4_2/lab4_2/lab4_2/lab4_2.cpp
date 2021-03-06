// lab4_2.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include <conio.h>
#include <string.h>
#include <ctype.h>

void split_string(char* input_string, char** words, int* number, char* separators);
void init_cwords(char** c_words, int* number);
bool check_if_cword(char* word, char** c_words, int* number);
char* to_upper(char* word);
void save(char** words, int* number);
void init_input(char** words, int* number);
char* edit_string(char* string, char** c_words, int* number);
bool is_separator(char* word, char c);


int main()
{
	char* input_string = new char[100];
	char* separators = " ";
	char** c_words = new char*[50];
	char** words = new char*[200];
	int* number = new int();
	int* code_strings_number = new int();
	*number = 0;
	*code_strings_number = 0;
	for (int i = 0; i < 50; i++)
		c_words[i] = new char[40];
	for (int i = 0; i < 200; i++)
		words[i] = new char[200];		
	
	init_cwords(c_words, number);
	init_input(words, code_strings_number);

	for (int i = 0; i < *code_strings_number; i++)
	{
		words[i] = edit_string(words[i], c_words, number);
		printf("%s\n", words[i]);
	}
	save(words, code_strings_number);

	_getch();
	for (int i = 0; i < 50; i++)
		delete[] c_words[i];
	for (int i = 0; i < 200; i++)
		delete[] words[i];
	delete[] c_words;
	delete[] words;
	delete[] input_string;
    return 0;
}

char* edit_string(char* string, char** c_words, int* number)
{
	int i, j;
	char* output_string = new char[200];
	char* separators = " ,;{}()[]\t";
	char* word = new char[20];
	char* temp = NULL;
	char* begin = string;
	strcpy_s(output_string, 200, "");
	for (i = 0; i < *number; i++)
	{
		word = strstr(string, c_words[i]);
		while (word)
		{
			if (word==begin || is_separator(separators, *(word - 1)) != NULL)
			{
				temp = word;
				for (j = 0; is_separator(separators, word[j])==NULL; j++) {}
				if (strncmp(temp, c_words[i], j) == 0)
				{
					for (j = 0; j < strlen(word); j++)
					{
						if (is_separator(separators, word[j]) == 1)
							break;
						word[j] = toupper(word[j]);
					}
					string += j;
				}	
			}
			string += 1;
			word = strstr(string, c_words[i]);
		}
		string = begin;
	}

	return string;
}

bool is_separator(char* word, char c)
{
	return strstr(word, &c) != NULL ? 1 : 0;
}

void split_string(char* input_string, char** words, int* number, char* separators)
{
	char* temp = NULL;
	char* buf_word = new char[40];
	buf_word = strtok_s(input_string, separators, &temp);
	while (buf_word)
	{
		strcpy_s(words[(*number)++], 40, buf_word);
		buf_word = strtok_s(NULL, separators, &temp);
	}
	delete[] buf_word;
}

void init_cwords(char** c_words, int* number)
{
	FILE* file;
	char* input_string = new char[100];
	char* separators = " ";

	fopen_s(&file, "d:\\Work\\Programming\\lab4_2\\lab4_2\\lab4_2\\c_words.txt", "r");
	while (!feof(file))
	{
		fgets(input_string, 100, file);
		if (input_string[strlen(input_string) - 1] == '\n')
			input_string[strlen(input_string) - 1] = '\0';
		split_string(input_string, c_words, number, separators);
	}
	fclose(file);
	delete[] input_string;
}

void init_input(char** words, int* number)
{
	FILE* file;
	char* input_string = new char[200];

	fopen_s(&file, "d:\\Work\\Programming\\lab4_2\\lab4_2\\lab4_2\\input.txt", "r");
	while (!feof(file))
	{
		fgets(input_string, 200, file);
		if (input_string[strlen(input_string) - 1] == '\n')
			input_string[strlen(input_string) - 1] = '\0';
		strcpy_s(words[(*number)++], 200, input_string);
	}
	fclose(file);
	delete[] input_string;
}

void save(char** words, int* number)
{
	FILE* file;

	fopen_s(&file, "d:\\Work\\Programming\\lab4_2\\lab4_2\\lab4_2\\output.txt", "w");
	for (int i = 0; i < *number; i++)
	{
		fprintf(file, "%s\n", words[i]);
	}
	fclose(file);
}

char* to_upper(char* word)
{
	int i = 0, len = strlen(word);
	char* new_word = new char[len+1];
	for (i = 0; i < len; i++)
		new_word[i] = toupper(word[i]);
	new_word[i] = '\0';
	return new_word;
}

bool check_if_cword(char* word, char** c_words, int* number)
{
	for (int i = 0; i < *number; i++)
	{
		if (!strcmp(to_upper(word), to_upper(c_words[i])))
			return 1;
	}
	
	return 0;
}
