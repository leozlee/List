#include"stack_list.h"
#include "stdio.h"


int main(void)
{
	printf("This is a test for stack_list\r\n");
	Stack S = CreateStack();
	int i = 10;
	for(i = 0; i < 10; ++i)
	{
		Push(i, S);
	}
	PrintStack(S);

	return 0;
}
