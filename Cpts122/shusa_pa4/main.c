#include "Header.h"
int main(void)
{
	srand(time(NULL));
	Queue normal, express, temp;
	normal.pHead = NULL;
	normal.pTail = NULL;
	express.pTail = NULL;
	express.pHead = NULL;

	int tempcustn = 0, tempcuste = 0, total = 0, countn = 0, length = 0, arrival = 0, expressval = 0, normalval = 0, expressvala = 0, normalvala = 0, time = 0, counte=0;

	printf("*****GROCERY STORE FUN TIMES******\n\n\n\n\n");

	printf("How many minutes would you like this simulation to last? Please enter a number over 10\n");

	scanf("%d", &length);

	while (time < length)
	{
		if (countn == 0)
		{
			countn++;
			normalvala = arrivaltime(False);
			normalval = servicetime(False);
		}
		if (counte == 0)
		{
			counte++;
			expressval = servicetime(True);
			expressvala = arrivaltime(True);
		}
		normalvala--;
		expressvala--;

		if (normalvala == 0)
		{
			tempcustn++;
			printf("customer %d has arrived in the normal line\n", tempcustn);
			enqueque(&normal, tempcustn, normalval, 0);
			temp = normal;
			temp.pTail->serviceTime = servicetime(False);
			temp.pTail->customerNumber = tempcustn;
			while(temp.pHead)
			{
				total += temp.pHead->serviceTime;
				temp.pHead = temp.pHead->pNext;
			}
			normal.pTail->totalTime = total;
			total = 0;
			countn = 0;
		}
		if (expressvala == 0)
		{
			tempcuste++;
			printf("customer %d has arrived in the express line\n",tempcuste);
			enqueque(&express, tempcustn, expressval, 0);
			temp = express;
			temp.pTail->serviceTime = servicetime(True);
			temp.pTail->customerNumber = tempcuste;
			while (temp.pHead)
			{
				total += temp.pHead->serviceTime;
				temp.pHead = temp.pHead->pNext;
			}
			express.pTail->totalTime = total;
			total = 0;
			counte = 0;
		}

		if (Empty(normal) == False)
		{
			

			if (normal.pHead->serviceTime <= 0)
			{
				printf("customer # %d has just left the normal line\n", normal.pHead->customerNumber);
				dequeue(&normal);
			}
			if (Empty(normal) == False)
			{
				normal.pHead->serviceTime--;
			}
		}
		if (Empty(express) == False)
		{
			
			if (express.pHead->serviceTime <=0)
			{
				printf("customer # %d has just left the express line\n", express.pHead->customerNumber);
				dequeue(&express);
			}
			if (Empty(express) == False)
			{
				express.pHead->serviceTime--;
			}
			
			
		}
		if (((time % 10)==0)&&(time>0))
		{
			printf("Normal line STATTTSSSSSS\n");
			print_queue(normal);
			printf("\n\n\n\n\n");
			printf("EXPRESS LINE STATS\n");
			print_queue(express);
			printf("\n\n\n\n\n");
		}

		time++;
	}
}

