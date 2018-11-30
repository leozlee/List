#include"bio_list.h"
#include <stdio.h>
#include <stdlib.h>


//双向链表的实现方式，非双向循环
 



List MakeEmpty(List L)
{
	L = (List)malloc(sizeof(struct Node));
	if(L != NULL)
	{
		L->Pre = NULL;
		L->Next = NULL;
	}
	return L;
}
                    
                                              
int IsEmpty(List L)
{
	if(L != NULL)
		return L->Next == NULL && L->Pre == NULL;
	return 0;	
}



int IsLast(Position P, List L)
{
	return P->Next == NULL;
}



Position Find(ElementType X, List L)
{
	Position P = L->Next;

	while(P != NULL && P->Element != X)
		P = P->Next;
	
	return P;

}

//如果是双向循环链表，这里的删除函数会有点不同
void Delete(ElementType X, List L)
{
	Position P = Find(X, L);
	
	if(!IsLast(P, L))
	{
		P->Pre->Next = P->Next;
		P->Next->Pre = P->Pre;
		P->Pre = P->Next = NULL;
		free(P);
	}
	else
	{
		P->Pre->Next = NULL;
		P->Pre = NULL;
		P->Next = NULL;
		free(P);
	}

}


void Insert(ElementType X, List L, Position P)
{
	Position TmpCell = (Position)malloc(sizeof(struct Node));
	if(TmpCell != NULL)
	{
		perror("Out of Space");
		return;
	}
	TmpCell->Next = P->Next;
	TmpCell->Pre  = P;
	P->Next->Pre  = TmpCell;
	P->Next       = TmpCell;
}


void DeleteList(List L)
{
	Position P, Tmp;
	P = L->Next;
	L->Next = NULL;
	
	while(P != NULL)
	{
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}	
}


void PrintList(List L)
{
	if(L == NULL)
		return;
	Position P = L->Next;

	printf("Header->");
	while(P != NULL)
	{
		printf("%d<-->", P->Element);
		P = P->Next;
	}

	printf("NULL\r\n");

}



int GetListLength(List L)
{
	if(L == NULL)
		return 0;
	int cnt = 0;
	Position P = L->Next;

	while(P != NULL)
	{
		cnt++;
		P = P->Next;
	}
	return cnt;
}












