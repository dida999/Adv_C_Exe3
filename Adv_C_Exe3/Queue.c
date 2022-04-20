#include "Queue.h"
#include <cstddef>

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
	q->head = NULL;
	q->tail = NULL;
}

void destroyQueue(Queue* q)
{
	// add your code here
}

void enqueue(Queue* q, unsigned int data)
{
	{
		intNode* node = (intNode*)malloc(sizeof(intNode));
		if (node == NULL)
		{
			printf("malloc failed");
			return;
		}
		node->data = data;
		node->next = NULL;
		if (isEmptyQueue(q)) // the Queue is empty, it will become the first element
		{
			q->head = node;
		}
		else // if not empty, add after the last one that already exsists
		{
			q->tail->next = node;
		}
		q->tail = node // updating our tail
	}
}

unsigned int dequeue(Queue* q)
{
	// add your code here
}

int isEmptyQueue(const Queue* q)
{
	return (q->head == NULl && q->tail == NULL ? 1 : 0);
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	// add your code here
}

void cutAndReplace(Queue* q)
{
	// add your code here
}

void sortKidsFirst(Queue* q)
{
	// add your code here
}