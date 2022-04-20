#include "Stack.h"
#include <cstddef>

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	s->head = NULL;
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
	charNode* newNode = (charNode*)malloc(sizeof(charNode));
	if (newNode = NULL)
	{
		printf("malloc failed");
		return;
	}
	newNode->data = data;
	newNode->next = s->head;
	s->head = newNode;
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
	return (s->head == NULL ? 1 : 0);
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	Stack* temp;
	initStack(temp);
	for (int i = 0; i < strlen(sentence); i++)
	{
		//going through the string
		if (sentence[i] == '#')
		{
			int j = 0;
			while (sentence[j] != '#')
			{
				//pushing the flipped sentanced to the temp stack
				push(temp,sentence[j]);
				j++;
			}
			//using display function to print the flipped part from the end
			display(temp);
		}
		//printing the non-flipped part
		else printf("%d", sentence[i]);
	}
}

int isPalindrome(Stack* s)
{
	charNode* node1, * node2;
	if (s->head == NULL)
	{
		return 1;
	}
	//we're going to count how many elements we have in our stack
	int size = 0, i;
	for (size = 0, node1 = s->head; node1 != NULL; size++, node1 = node1->next)
	{
	}
	// now that we have the size we will check if the stack is palindrome
	int distance;
	for (node1 = s->head, distance = size - 1; distance > 0; node1->next, distance -= 2)
	{
		for (node2 = node1, i = 0; i < distance; node2 = node2->next, i++)
		{
		}
		if (node1->data != node2->data)
		{
			return 0;
		}
	}
	return 1;
}

void rotateStack(Stack* s, int n)
{
	//return from the function if n<0,n>stack,stack is empty
	charNode* counter=s->head;
	int count = 0;
	while (counter != NULL)
	{
		counter = counter->next;
		count++;
	}
	if (n<0 || n>count || isEmptyStack(s))
	{
		return;
	}
	//creating temp stacks
	Stack* tmp1 = (Stack*)malloc(sizeof(Stack*));
	Stack* tmp2 = (Stack*)malloc(sizeof(Stack*));
	if (tmp1 == NULL || tmp2 == NULL)
	{
		print("error");
	}
	//pushing from original stack to 2 temp stack and arranging again in original stack
	for (int i = 0; i < count - n; i++)
	{
		push(tmp1, pop(s));
	}
	for (int i = 0; i < n; i++)
	{
		push(tmp2, pop(s));
	}
	for (int i = 0; i < count; i++)
	{
		push(s,pop(tmp1));
	}
	for (int i = 0; i <n; i++)
	{
		push(s, pop(tmp2));
	}
	//free the allocated memory
	free(tmp1);
	free(tmp2);
}

void print(charNode* head)
{
	charNode* tmp;
	tmp = head;
	while (tmp != NULL) {
		printf(" % d ", tmp->data);
		tmp = tmp->next;
	}
}

void display(Stack* S)
{
	print(S->head);
}
