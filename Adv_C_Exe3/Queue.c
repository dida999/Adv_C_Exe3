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
	q->head->next = q->tail;
	intNode* temp;
	temp = q->tail;
	q->tail = q->tail->next;
	temp->next = NULL;
	q->head = temp;
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
	int size = 0;
	intNode* current = q->head;
	while (current != NULL) {
		size++;
		current = current->next;
	}

	for (int i = 1; i <= size; i++)
	{
		int min_index = minIndex(q, size - i, size);
		insertMinToRear(q, min_index, size);
	}
}

// Queue elements after sortedIndex are
// already sorted. This function returns
// index of minimum element from front to
// sortedIndex
int minIndex(Queue* q, int sortedIndex, int size)
{
	int min_index = -1;
	int min_val = _CRT_INT_MAX;

	for (int i = 0; i < size; i++)
	{
		int curr = q->head;
		dequeue(q);

		// we add the condition i <= sortedIndex
		// because we don't want to traverse
		// on the sorted part of the queue,
		// which is the right part.
		if (curr <= min_val && i <= sortedIndex)
		{
			min_index = i;
			min_val = curr;
		}
		enqueue(q, curr);
	}
	return min_index;
}

// Moves given minimum element to rear of
// queue
void insertMinToRear(Queue* q, int min_index, int size)
{
	int min_val;
	for (int i = 0; i < size; i++)
	{
		int curr = q->head;
		dequeue(q);
		if (i != min_index)
			enqueue(q, curr);
		else
			min_val = curr;
	}
	enqueue(q, min_val);
}