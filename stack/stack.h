#ifndef __STACK_H_
#define __STACK_H_

struct StackRecord;
typedef struct StackRecord* Stack;
typedef int ElementType;

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};


int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElement);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType x,Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);
void PrintStack(Stack S);

#endif
