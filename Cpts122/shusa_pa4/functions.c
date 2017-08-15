#include "Header.h"

int arrivaltime(Bool express)
{
	int arrival = 0;

	if (express)
	{
		arrival = rand() % 5 + 1;
	}
	else
	{
		arrival = rand() % 5 + 3;
	}

	return arrival;
}

QueueNode*makenode(int customer, int servicetime, int totaltime)
{
	QueueNode *pMem = NULL;
	
	pMem = malloc(sizeof(QueueNode));

	pMem->customerNumber = customer;

	pMem->serviceTime = servicetime;

	pMem->totalTime = totaltime;

	pMem->pNext = NULL;

	return pMem;
}
int servicetime(Bool express)
{
	int service = 0;

	if (express)
	{
		service = rand() % 5 + 1;
	}
	else
	{
		service = rand() % 5 + 3;
	}

	return service;
}

Bool Empty(Queue line)
{
	return (line.pHead == NULL);
}

void print_queue(Queue list) 
{
	if (list.pHead != NULL)
	{
		{
			printf("customer number: %d  , total time : %d\n", list.pHead->customerNumber, list.pTail->totalTime);
		}
		list.pHead = list.pHead->pNext;
		print_queue(list);
	}
}

void enqueque(Queue *plist, int customer, int servicetime, int totaltime)
{
	Queue *list = plist;
	QueueNode *cust = makenode(customer, servicetime, totaltime);
	if (Empty(*list))
	{
		list->pHead = cust;
		list->pTail = cust;
	}
	else
	{
		list->pTail->pNext = cust;
		list->pTail = cust;
	}
}

void dequeue(Queue *pQueue)
{
	QueueNode *pTemp = NULL;

	// if the queue is not empty, delete the first node
	if (Empty(*pQueue)==False )
	{
		if (pQueue->pHead == pQueue->pTail)
		{
			pQueue->pTail = NULL;
		}

		pTemp = pQueue->pHead;
		pQueue->pHead = pQueue->pHead->pNext;
		free(pTemp);
	}
} 

