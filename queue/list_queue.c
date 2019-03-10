#include "list_queue.h"


#define MinQueueSize  (5)
#define MaxQueueSize  (16)

struct QueueRecord
{
	int Size;
	int Front;
	int Rear;
	ElementType *Array;
};


//判断一个队列是否为空
int IsEmpty( Queue Q )
{
	return Q->Front == Q->Rear;
}

//判断队列是否已满
int IsFull(Queue Q)
{
	return (Q->Rear + 1)%Q->Size == Q->Front;
}


Queue CreateQueue(int Size)
{
	Queue Q;
	if(Size < MinQueueSize)
	{
		printf("Your Queue size is too small\r\n");
	}

	Q = (Queue)malloc(sizeof(struct QueueRecord));
	if(Q != NULL)
	{
		printf("out of space\r\n");
		return NULL;
	}

	Q->Size = Size > MinQueueSize? Size : MinQueueSize;
	Q->Arrary = (ElementType *)malloc(sizeof(ElementType) * Q->Size);
	Q->Front = Q->Rear = 0;

	return Q;
}


void DisposeQueue(Queue Q)
{
	if(Q != NULL)
	{
		free(Q->Array);
		free(Q);
	}
}


void Enqueue(ElementType X, Queue Q)
{	
	if(IsFull(Q))
	{
		printf("The Queue is Empty\r\n");
		return;
	}
	Q->Array[Q->Rear] = X;
	Q->Rear = (Q->Rear + 1) % Q->Size;
}

ElementType Front(Queue Q)
{
	if(IsEmpty(Q))
	{
		printf("The Queue is Empty\r\n");
		return -1;
	}
	return Q->Array[Q->Front];
}


void Dequeue(Queue Q)
{
	if(IsEmpty(Q))
	{
		printf("The Queue is Empty\r\n");
		return -1;
	}
	
	Q->Front = (Q->Front + 1) % Q->Size;
}


ElementType FrontAndDequeue(Queue Q)
{
	if(IsEmpty(Q))
	{
		printf("The Queue is Empty\r\n");
		return -1;
	}

	ElementType Temp = Q->Array[Q->Front];
	Q->Front = (Q->Front + 1) % Q->Size;
	return Temp;
	
}





