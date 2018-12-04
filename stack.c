#include "stack.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>


#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};


Stack CreateStack(int MaxElements)
{
	Stack S;

	if(MaxElements < MinStackSize)
	{
		printf("Stack size is too small\r\n");
	}
	
	S = malloc(sizeof(struct StackRecord));
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
