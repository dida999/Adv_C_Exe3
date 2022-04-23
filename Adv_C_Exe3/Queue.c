#include <stdio.h>
#include "Queue.h"
#include <stdlib.h>

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
	q->head = NULL;
	q->tail = NULL;
}

void destroyQueue(Queue* q)
{
	intNode* temp;
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
		q->tail = node; // updating our tail
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
	Queue* tmp = (Queue*)malloc(sizeof(Queue));
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
	intNode* node, * node1, * node2, * temp;
	int count, sum = 0, ave;
	if (isEmptyQueue(q))
	{
		return;
	}
	// count how many elements we have in our queue
	for (node = q->head, count = 0; node != NULL; node = node->next, count++)
	{
		sum += node->data;
	}
	//if the number of elements are even
	if (count % 2 != 0)
	{
		ave = sum / count;
		node = (intNode*)malloc(sizeof(intNode));
		node->data = ave;
		node->next = NULL;
		q->tail->next = node;
		q->tail = node;
		count++;
	}

	//node2 will point the last element, and node1 will point the center element
	for (node1 = q->head, node2 = q->head->next; node2->next != NULL; node1 = node1->next, node2 = node2->next->next)
	{
	}
	// we will change node1 to point on the next element from the middle since we wont it to be from the tail side
	node = node1->next;
	// 
	temp = node->next;
	node->next = q->head;
	node1->next = NULL;
	q->tail = node1;
	while (temp != NULL)
	{
		node1 = node;
		node = temp;
		temp = temp->next;
		node->next = node1;
	}
	q->head = node;
	printf("after cut and replace\n");

}

void printQueue(Queue* q)
{
	intNode* node;
	for (node = q->head; node != NULL; node = node->next)
	{
		printf("%d ", node->data);
	}
	printf("\n");
}

void sortKidsFirst(Queue* q)
{
	intNode* tmp = (intNode*)malloc(sizeof(intNode));
	if (tmp == NULL)
	{
		printf("error");
	}
	
}