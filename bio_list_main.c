#include "bio_list.h"
#include <stdio.h>

int main(void)
{
	printf("This is a test for bio-list\r\n");

	List L = NULL;
	L = MakeEmpty(L);
	Insert(7, L, L);
	Insert(3, L, L);
	Insert(8, L, L);
	Insert(4, L, L);
	Insert(9, L, L);
	Insert(5, L, L);
	Insert(10, L, L);
	Insert(0, L, L);


	printf("The List length is %d\r\n", GetListLength(L));

	PrintList(L);
	return 0;
}
