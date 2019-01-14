#include "sequence_queue.h"
#include <stdlib.h>

#define MinQueueSize (5)

struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	ElementType *Array;
};

//判断数据是否为空
int IsEmpty( Queue Q )
{
	if(Q != NULL)
	{
		printf("Queue is NULL\r\n");
		return -1;
	}
	else
	{
		return Q->Size == 0;
	}
}

int IsFull(Queue Q)
{
	return Q->Capacity == Q->Size;
}



//构造空队列的例程--数组实现
void MakeEmpty( Queue Q )
{
	Q->Size  = 0;
	Q->Front = 1;
	Q->Rear  = 0;
}

static int Succ(int Value, Queue Q)
{
	if(++Value == Q->Capacity)
		Value = 0;
	return Value;
}



void Enqueue(ElementType X, Queue Q)
{
	if(IsFull(Q))
	{
		printf("Full queue\r\n");
	}
	else
	{
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X;
	}
}

void Dequeue(Queue Q)
{
	if(IsEmpty(Q))
	{
		printf("Empty queue\r\n");
	}
	else
	{
		Q->Size--;
		Q->Rear = Succ(Q->Rear, Q);
	}
}

ElementType Front(Queue Q)
{
	if(IsEmpty(Q))
	{
		printf("Empty queue\r\n");
		return -1;
	}
	else
	{
		return Q->Array[Q->Front];
	}
}

ElementType FrontAndDequeue(Queue Q)
{
	if(IsEmpty(Q))
	{
		printf("Empty queue\r\n");
		return -1;
	}
	else
	{
		ElementType temp = Q->Array[Q->Front];
		Q->Size--;
		Q->Rear = Succ(Q->Rear, Q);
		return temp;
	}
}

void DisposeQueue(Queue Q)
{
	if(Q == NULL)
	{
		printf("queue is null\r\n");
		return;
	}
	else
	{
		free(Q->Array);
		free(Q);
	}
}


