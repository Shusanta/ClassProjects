#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
typedef struct queueNode
{
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
	int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes

	struct queueNode *pNext;
} QueueNode;

typedef struct queue
{
	QueueNode *pHead;
	QueueNode *pTail;
} Queue;

typedef enum bool
{
	False,True
}Bool;


int arrivaltime(Bool express);
QueueNode* makenode(int customer, int servicetime, int totaltime);
int servicetime(Bool express);
Bool Empty(Queue line);
void print_queue(Queue list);
void enqueque(Queue *list, int customer, int servicetime, int totaltime);
void dequeue(Queue *pQueue);