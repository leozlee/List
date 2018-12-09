#include "stack.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>


//栈的数组实现

#define EmptyTOS (-1)
#define MinStackSize (5)

//struct StackRecord
//{
//	int Capacity;
//	int TopOfStack;
//	ElementType *Array;
//};


//创建一个空栈
void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}

//创建一个栈
Stack CreateStack(int MaxElements)
{
	Stack S;

	if(MaxElements < MinStackSize)
	{
		printf("Stack size is too small\r\n");
	}
	
	S = (Stack)malloc(sizeof(struct StackRecord));
	if(S == NULL)
	{
		perror("out of space");
		return NULL;
	}
		

	S->Array = malloc(sizeof(ElementType) * MaxElements);
	if(S->Array == NULL)
	{
		printf("Out of space");
		return NULL;
	}
	S->Capacity = MaxElements;
	MakeEmpty(S);

	return S;
}


//销毁栈的函数
void DispostStack(Stack S)
{
	if(S != NULL)
	{
		free(S->Array);
		free(S);
	}
}



// 判断栈是否为空
int IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S)
{
	return S->TopOfStack == S->Capacity - 1;
}

void Push(ElementType X, Stack S)
{
	if(IsFull(S))
	{
		printf("Full Stack\r\n");
		return ;
	}
	else
	{
		S->Array[++S->TopOfStack] = X;
	}
}

ElementType Top(Stack S)
{
	if(!IsEmpty(S))
	{
		return S->Array[S->TopOfStack];
	}
	printf("Empty Stack\r\n");
	return 0;
}


void Pop(Stack S)
{
	if(IsEmpty(S))
	{
		printf("Empty Stack\r\n");
	}
	else
	{
		S->TopOfStack--;
	}
}


ElementType TopAndPop(Stack S)
{
	if(!IsEmpty(S))
	{
		return S->Array[S->TopOfStack--];
	}
	printf("Empty Stack\r\n");
	return 0;
}


void PrintStack(Stack S)
{
	if(!IsEmpty(S))
	{
		int n = S->TopOfStack;
		printf("top->");
		for(; n>=0; --n)
		{
			printf("%d->",S->Array[n]);
		}		
		printf("bottom\r\n");
		return;
	}
	printf("Stack is Empty\r\n");
}




