#ifndef __LIST_QUEUE_H__
#define __LIST_QUEUE_H__

//顺序队列的另一种实现方式

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef int ElementType;

int IsEmpty(Queue Q);
int IsFull(Queue Q);

Queue CreateQueue(int Size);
void DisposeQueue(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);



#endif
