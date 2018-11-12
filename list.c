#include "list.h"
#include <stdio.h>
#include <stdlib.h>

//struct Node
//{
//	ElementType Element;
//	Position Next;
//};




/* 生成一个空链表 */
List MakeEmpty(List L)
{
	L = (List)malloc(sizeof(struct Node));
	if(L != NULL)
	{
		L->Next = NULL;
	}
	return L;
}


/* return true if L is empty  */
int IsEmpty(List L)
{
	return L->Next == NULL;
}

/* return true if P is the last position in list L*/
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

/* return Position of X in L, Null if not found */
Position Find(ElementType X, List L)
{
	Position P = L->Next;
	
	while(P != NULL && P->Element != X)
		P = P->Next;

	return P;
}


/* find the previous position of specified elementtype  */
Position FindPrevious(ElementType X, List L)
{
	Position P = L;
	while(P->Next != NULL && P->Next->Element != X)
		P = P->Next;

	return P;
}



void Delete(ElementType X, List L)
{
	Position P, TmpCell;

	P = FindPrevious(X, L);
	
	if(!IsLast(P, L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}

}


/* Insert after legal position P */
void Insert(ElementType X, List L, Position P)
{
	Position TmpCell = (Position)malloc(sizeof(struct Node));
	if(TmpCell == NULL)
	{
		perror("Out of Space");
		return;
	}

	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
		
}



/* 删除链表L初头结点外的所有结点 */
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


/* 获得链表中头节点的位置  */
Position Header(List L)
{
	return L;

}

/* 获取P链表L中第一个数据节点的位置 */
Position First(List L)
{
	if(L != NULL)
		return L->Next;
	else
		return NULL;
}


/* 获取P位置的后继节点位置 */
Position Advance(Position P)
{
	if(P != NULL)
		return P->Next;
	else
		return NULL;
}


/* 获取P位置节点的数据项 */
ElementType Retrieve(Position P)
{
	if(P != NULL)
		return P->Element;
}


void PrintList(List L)
{
	if(L == NULL)
		return;

	Position P = L->Next;

	printf("Header->");
	while(P != NULL)
	{
		printf("%d-->", P->Element);
		P = P->Next;
	}

	printf("NULL\r\n");
}

int GetListLength(List L)
{
	if(L == NULL)
		return 0;
	int cnt = 0;
	Position P = L;

	while(P != NULL)
	{
		cnt++;
	}
	return cnt;
	
}


/* 单链表反转 */
void Reversal(List L)
{
	if(L == NULL)
		return;

	Position P = L->Next;
	Position Tmp = P->Next;
	L->Next = NULL;

	while(P != NULL)
	{
		Tmp = P->Next;
		Insert(P->Element, L, L);
		free(P);
		P = Tmp;
	}
	
}


void ReversePrint(List L)
{
	if(L == NULL)
		return;

	ReversePrint(L->Next);
	printf("%d->",L->Element);
	
	
}



