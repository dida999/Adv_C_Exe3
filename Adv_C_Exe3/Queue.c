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
	Queue* temp;
	while (q->head != NULL)
	{
		temp = q->head;
		q->head = q->head->next;
		free(temp);
	}
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
		int temp = q->head->data;
		intNode* p = q->head;
		q->head = q->head->next;
		if (q->head == NULL) //if queue gets empty
			q->tail = NULL;//both front and rear NULL
		free(p);
		return temp;
}

int isEmptyQueue(const Queue* q)
{
	return (q->head == NULL && q->tail == NULL ? 1 : 0);
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	Queue* tmp;
	initQueue(tmp);
	while (q->head->next!= NULL)
	{
		enqueue(tmp, dequeue(q));
	}
	while (tmp->head != NULL)
	{
		enqueue(q, dequeue(tmp));
	}
}

void cutAndReplace(Queue* q)
{
	// add your code here
}

void sortKidsFirst(Queue* q)
{
	intNode* tmp = (intNode*)malloc(sizeof(intNode));
	if (tmp == NULL)
	{
		printf("error");
	}
	while()
}