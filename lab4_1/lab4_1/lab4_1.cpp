// lab4_1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <conio.h>
#include <Windows.h>
#include <iostream>
using namespace std;

char* morze(char symbol);
char upper(char symbol);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char* input_string = new char[10000];
	printf("Input text:\n");
	gets_s(input_string, 10000);
	printf("Morze:\n");
	for (int i = 0 , len = strlen(input_string); i < len; i++)
		printf("%s", morze(upper(input_string[i])) );
	_getch();
	delete[] input_string;
    return 0;
}

char* morze(char symbol)
{
	switch (symbol)
	{
	case 'A':
	case '�': return ".-"; 
	case 'B':
	case '�': return "-...";
	case '�':
	case 'W': return ".--";
	case '�':
	case 'G': return "--.";
	case '�':
	case 'D': return "-..";
	case 'E':
	case '�':
	case '�': return ".";
	case '�':
	case 'V': return "...-";
	case '�':
	case 'Z': return "--..";
	case '�':
	case 'I': return "..";
	case '�':
	case 'J': return ".---";
	case '�':
	case 'K': return "-.-";
	case '�':
	case 'L': return ".-..";
	case '�':
	case 'M': return "--";
	case '�':
	case 'N': return "-.";
	case '�':
	case 'O': return "---";
	case '�':
	case 'P': return ".--.";
	case '�':
	case 'R': return ".-.";
	case '�':
	case 'S': return "...";
	case '�':
	case 'T': return "-";
	case '�':
	case 'U': return "..-";
	case '�':
	case 'F': return "..-.";
	case '�':
	case 'H': return "....";
	case '�':
	case 'C': return "-.-.";
	case '�': return "---.";
	case '�': return "----";
	case '�':
	case 'Q': return "--.-";
	case '�': return ".--.-.";
	case '�':
	case 'Y': return "-.--";
	case '�':
	case 'X': return "-..-";
	case '�': return "...-...";
	case '�': return "..--";
	case '�': return ".-.-";
	case '1': return ".----";
	case '2': return "..---";
	case '3': return "...--";
	case '4': return "....-";
	case '5': return ".....";
	case '6': return "-....";
	case '7': return "--...";
	case '8': return "---..";
	case '9': return "----.";
	case '0': return "-----";
	case '.': return ".-.-.-";
	case ',': return "--..--";
	case ':': return "---...";
	case '?': return "..--..";
	case '\'': return ".----.";
	case '-': return "-....-";
	case '/': return "-..-.";
	case ';': return "-.--.-";
	case ' ': return " ";
	default: return "";
	}
}

char upper(char symbol)
{
	if (symbol == -72)
		return -88;
	else if ( (symbol <= -1 && symbol >= -32) || (symbol >= 97 && symbol <= 122) )
		return symbol - 32;
	else
		return symbol;
}