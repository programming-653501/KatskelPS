// lab4_1.cpp: определяет точку входа для консольного приложения.
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
	case 'А': return ".-"; 
	case 'B':
	case 'Б': return "-...";
	case 'В':
	case 'W': return ".--";
	case 'Г':
	case 'G': return "--.";
	case 'Д':
	case 'D': return "-..";
	case 'E':
	case 'Е':
	case 'Ё': return ".";
	case 'Ж':
	case 'V': return "...-";
	case 'З':
	case 'Z': return "--..";
	case 'И':
	case 'I': return "..";
	case 'Й':
	case 'J': return ".---";
	case 'К':
	case 'K': return "-.-";
	case 'Л':
	case 'L': return ".-..";
	case 'М':
	case 'M': return "--";
	case 'Н':
	case 'N': return "-.";
	case 'О':
	case 'O': return "---";
	case 'П':
	case 'P': return ".--.";
	case 'Р':
	case 'R': return ".-.";
	case 'С':
	case 'S': return "...";
	case 'Т':
	case 'T': return "-";
	case 'У':
	case 'U': return "..-";
	case 'Ф':
	case 'F': return "..-.";
	case 'Х':
	case 'H': return "....";
	case 'Ц':
	case 'C': return "-.-.";
	case 'Ч': return "---.";
	case 'Ш': return "----";
	case 'Щ':
	case 'Q': return "--.-";
	case 'Ъ': return ".--.-.";
	case 'Ы':
	case 'Y': return "-.--";
	case 'Ь':
	case 'X': return "-..-";
	case 'Э': return "...-...";
	case 'Ю': return "..--";
	case 'Я': return ".-.-";
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