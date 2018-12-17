#include "circle_list.h"
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
		L->Next = L;
	}
	return L;
}


/* return true if L is empty  */
int IsEmpty(List L)
{
	return L->Next == L;
}

/* return true if P is the last position in list L*/
int IsLast(Position P, List L)
{
	return P->Next == L;
}

/* return Position of X in L, Null if not found */
Position Find(ElementType X, List L)
{
	Position P = L->Next;
	
	while(P != L && P->Element != X)
		P = P->Next;

	return P;
}


/* find the previous position of specified elementtype  */
Position FindPrevious(ElementType X, List L)
{
	Position P = L;
	while(P->Next != L && P->Next->Element != X)
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
	L->Next = L;

	while(P != L)
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
	while(P != L)
	{
		printf("%d-->", P->Element);
		P = P->Next;
	}
	printf("Header\r\n");
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


/* 单链表反转 */
void Reversal(List L)
{
	if(L == NULL)
		return;

	Position P = L->Next;
	Position Tmp = P->Next;
	L->Next = NULL;

	while(P != L)
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
	printf("%d->", L->Element);
}


void swap(ElementType *w1, ElementType *w2)
{
	ElementType tmp = *w1;
	*w1 = *w2;
	*w2 = tmp;   
}


//冒泡排序1

void SortList(List L)
{
	if(L == NULL)
		return;

	Position P = L->Next;
	Position tail = NULL;
	Position cur = L->Next;

	for(; P != NULL; P = P->Next)
	{
		for(cur = L->Next; cur->Next != tail; cur = cur->Next)
		{
			if(cur->Element > cur->Next->Element)
				swap(&cur->Element, &cur->Next->Element);
		}
		
		tail = cur;
	}
}

//冒泡排序2

void BubbleSort(List L)
{
	if(L == NULL)
		return ;

	Position P = L->Next;
	Position Tmp = L->Next;
	for(;P != NULL; P = P->Next)
	{
		for(Tmp = L->Next; Tmp->Next != NULL; Tmp = Tmp->Next)
		{
			if(Tmp->Element > Tmp->Next->Element)
			{
				swap(&Tmp->Element, &Tmp->Next->Element);
			}
		}
	}
	
}
//链表的快速排序
void QuickSort(Position L, Position end)
{
	if(L == NULL || L == end)
		return;
	Position slow = L;
	Position fast = slow->Next;
	ElementType mid = slow->Element;

	printf("%d\r\n", mid);

	while(fast != end)
	{
		if(fast->Element < mid)
		{
			slow = slow->Next;
			swap(&fast->Element, &slow->Element);
		}
		fast = fast->Next;
	}
	

	swap(&L->Element, &slow->Element);
	QuickSort(L, slow);
	QuickSort(slow->Next, end);
}



