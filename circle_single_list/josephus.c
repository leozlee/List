#include "circle_list.h"
#include <stdio.h>
#include <stdlib.h>


void Josephus(int n, int m, int k)
{
	List L = NULL;
	Position Curr = NULL;
	Position Begin = NULL;

	//伪头结点
	L = (Position)malloc(sizeof(struct Node));
	L->Element = 1;
	L->Next = L;

	Curr = L;

	int count = m;

	//依次添加后续结点
	int i = 0;
	for(i = 2 ;i <= n; ++i)
	{
		Position Tmp = (Position)malloc(sizeof(struct Node));
		Tmp->Element = i;
		Tmp->Next = Curr->Next;
		Curr->Next = Tmp;
		Curr = Tmp;
	}

	Begin = Curr->Next;
	while(Begin->Element != k)
	{
		Begin = Begin->Next;
	}

	printf("The game begin with %d man\r\n", Begin->Element);
	
	while(Begin->Next != Begin)
	{
		count = m;
		while(--count)
		{
			Curr = Begin;
			Begin = Begin->Next;
		}

		Curr->Next = Begin->Next;
		printf("%d man was killed\r\n", Begin->Element);
		free(Begin);
		Begin = Curr->Next;
	}
	printf("The last one is %d\r\n", Begin->Element);
}



int main(void)
{
	printf("This is a solution to josephus\r\n");
	Josephus(11, 3, 1);

	return 0; 
}
