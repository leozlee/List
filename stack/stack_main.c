#include <stdio.h>
#include "stack.h"

int main(void)
{
	printf("This is a stack test\r\n");
	
	Stack S = CreateStack(10);
	printf("cap is %d\r\n", S->Capacity);
	int i = 0;
	for(i = 0; i < 10; ++i)
	{
		printf("%d ", i);
		Push(i, S);
	}
	printf("top is %d\r\n", S->TopOfStack);
	PrintStack(S);	
	return 0;
}
