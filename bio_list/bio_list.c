#include"bio_list.h"
#include <stdio.h>
#include <stdlib.h>


//双向循环链表的实现方式
 



List MakeEmpty(List L)
{
	L = (List)malloc(sizeof(struct Node));
	if(L != NULL)
	{
		L->Pre = L;
		L->Next = L;
	}
	return L;
}
                    
                                              
int IsEmpty(List L)
{
	if(L != NULL)
		return L->Next == L && L->Pre == L;
	return 0;	
}



int IsLast(Position P, List L)
{
	return P->Next == L;
}



Position Find(ElementType X, List L)
{
	Position P = L->Next;

	while(P != L && P->Element != X)
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
		P->Pre = P->Next = L;
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
	if(TmpCell == NULL)
	{
		perror("Out of Space");
		return;
	}

	TmpCell->Element = X;
	TmpCell->Next 	 = P->Next;
	TmpCell->Pre     = P;
	P->Next->Pre     = TmpCell;
	P->Next          = TmpCell;
}


void DeleteList(List L)
{
	Position P, Tmp;
	P = L->Next;
	L->Next = L;
	
	while(P != L)
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
	while(P != L)
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

	while(P != L)
	{
		cnt++;
		P = P->Next;
	}
	return cnt;
}












