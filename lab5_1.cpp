// 5_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <queue>
#include <conio.h>
#include <iostream>
#include <stack>
using namespace std;

struct Mystruct {
	int stack_number;
	char choise;
	int data;
};

int main()
{
	int number, stack_number, stack_data;
	char stack_choise;
	queue <Mystruct> Myqueue;
	do 
	{
		cout << "Input n - number of stacks : ";
		cin >> number;
	} while (number <= 0);
	stack <int> *Mystack = new stack <int>[number];
	do
	{
		do 
		{
			printf("\nInput number of stack(0 if you want to exit): ");
			cin >> stack_number;
		} while (stack_number<0 || stack_number>number);
		if (!stack_number)
			break;
		do 
		{
			printf("\nInput what you want to do with stack ('A' or 'D'): ");
			cin >> stack_choise;
		} while (stack_choise != 'A' && stack_choise != 'D');
		printf("\nInput element you want to add: ");
		cin >> stack_data;
		Myqueue.push({stack_number, stack_choise, stack_data});
	} while (stack_number);

	while (!Myqueue.empty())
	{
		stack_number = Myqueue.front().stack_number;
		stack_choise = Myqueue.front().choise;
		stack_data = Myqueue.front().data;
		
		if (stack_choise == 'D')
		{
			if (!Mystack[stack_number - 1].empty())
				Mystack[stack_number - 1].pop();
		}
		else
			Mystack[stack_number - 1].push(stack_data);
		Myqueue.pop();
	}
	printf("Stacks: \n");
	for (int i = 0; i < number; i++)
	{
		printf("%d: ", i + 1);
		while (!Mystack[i].empty())
		{
			printf("%d ", Mystack[i].top());
			Mystack[i].pop();
		}
		printf("\n");
	}
	_getch();
    return 0;
}

