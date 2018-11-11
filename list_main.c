#include "list.h"
#include <stdlib.h>
#include <stdio.h>




int main(void)
{
	printf("This is a Test for single list\r\n");
	

	List L = NULL;
	L = MakeEmpty(L);
	Insert(1, L, L);
	Insert(5, L, L);
	Insert(2, L, L);
	Insert(5, L, L);
	Insert(4, L, L);
	Insert(8, L, L);
	Insert(7, L, L);
	Insert(9, L, L);
	PrintList(L);


	Position T = Find(5, L);
	if(T != NULL)
	{
		printf("ElementType found\r\n", T->Element);
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

	DeleteList(L);
	free(L);
	
	
}









