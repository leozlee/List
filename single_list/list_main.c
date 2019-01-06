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


	List L1 = NULL;
	List L2 = NULL;
	List L3 = NULL;

	L1 = MakeEmpty(L1);
	Insert(1, L1, L1);
	Insert(3, L1, L1);
	Insert(5, L1, L1);
	Insert(7, L1, L1);
	Insert(9, L1, L1);

	printf("List1 is :\r\n");
	PrintList(L1);

	L2 = MakeEmpty(L2);
	Insert(2, L2, L2);
	Insert(4, L2, L2);
	Insert(6, L2, L2);
	Insert(8, L2, L2);
	printf("List2 is :\r\n");
	PrintList(L2);

	L3 = Merge(L1, L2);

	printf("List3 is :\r\n");
	PrintList(L3);


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
	Position Middle = FindMiddle(L);
	printf("The middle is %d\e\n", Middle->Element);

	//SortList(L);
	//PrintList(L);
	

	QuickSort(L->Next, NULL);
	PrintList(L);


	DeleteList(L);
	free(L);
	
	
}









