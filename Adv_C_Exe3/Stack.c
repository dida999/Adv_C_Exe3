#include "Stack.h"

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	// add your code here
}

void destroyStack(Stack* s)
{
	Stack* temp;
	while (s->head)
	{
		temp = s->head;
		s->head = s->head->next;
		free(temp);
	}
}

void push(Stack* s, char data)
{
	// add your code here
}

char pop(Stack* s)
{
	Stack* temp = s->head;
	char temp2=s->head->data;
	s->head = s->head->next;
	free(temp);
	return temp2;
}


int isEmptyStack(const Stack* s)
{
	// add your code here
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	// add your code here
}

int isPalindrome(Stack* s)
{
	// add your code here
}

void rotateStack(Stack* s, int n)
{
	// add your code here
}