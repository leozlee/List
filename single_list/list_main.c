#include "list.h"
#include <stdlib.h>
#include <stdio.h>




int main(void)
{
	printf("This is a Test for single list\r\n");
	

	List L = NULL;
	L = MakeEmpty(L);
	Insert(9, L, L);
	Insert(5, L, L);
	Insert(2, L, L);
	Insert(1, L, L);
	Insert(3, L, L);
	Insert(8, L, L);
	Insert(7, L, L);
	Insert(4, L, L);
	PrintList(L);


	printf("This list length is %d\r\n", GetListLength(L));


	Position T = Find(5, L);
	if(T != NULL)
	{
		printf("ElementType found %d\r\n", T->Element);
	}
	else
	{
		printf("No data found\r\n");
	}

	T = Find(0, L);
	if(T != NULL)
	{
		printf("ElementType found\r\n");
	}
	else
	{
		printf("No data found\r\n");
	}


	Delete(5, L);
	PrintList(L);

//	Reversal(L);
//	PrintList(L);

	//ReversePrint(L);
	//BubbleSort(L);


	//SortList(L);
	//PrintList(L);
	

	QuickSort(L->Next, NULL);
	PrintList(L);


	DeleteList(L);
	free(L);
	
	
}









