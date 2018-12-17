#include "circle_list.h"
#include <stdio.h>
#include <stdlib.h>


void Josephus(int n, int m, int k)
{
	List L = NULL;
	L = MakeEmpty(L);
	Position Curr = NULL;
	Position Begin = NULL;
	int count = m;
	int i = 0;
	for(i = n ;i >= 1; --i)
	{
		printf("%d\t", i);
		Insert(i, L, L);
	}

	
	PrintList(L);
	printf("The first man is %d\r\n", k);
	Curr = Find(k, L);

	while(Curr->Next != Curr)
	{
		count = m;
		while(--count)
		{
			Curr = Curr->Next;
		}

		Begin = Curr->Next;
		printf("%d man was killed\r\n", Curr->Element);
		free(Curr);
		Curr = Begin;
	}

	printf("The last one is %d\r\n", Curr->Element);
}



int main(void)
{
	printf("This is a solution to josephus\r\n");
	Josephus(41, 3, 1);

	return 0; 
}
