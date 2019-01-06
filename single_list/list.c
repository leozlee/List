#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
	Position P = L->Next;

	while(P != NULL)
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


/*
 *
 *
 * 链表的五个练习习题
 * 1.链表的反转(头插法)
 * 2.链表中环的检测(快慢指针)
 * 3.两个有序链表的合并
 * 4.删除链表中倒数第n个节点
 * 5.求链表的中间节点(快慢指针)
 *
 *
 * */
//查找中间节点,快慢指针
Position FindMiddle(List L)
{
	if(L == NULL)
	{
		printf("Empty List\r\n");
		return NULL;
	}

	Position slow = L->Next;
	Position fast = L->Next;
	
	while(fast != NULL && fast->Next != NULL)
	{
		slow = slow->Next;
		fast = fast->Next->Next;
	}
	return slow;
}

//查找链表是否有环

bool CheckCirfcle(List L)
{
	if(L == NULL)
	{
		printf("Empty List\r\n");
		return false;
	}

	Position slow = L->Next;
	Position fast = L->Next;
	
	while(fast != NULL && fast->Next != NULL)
	{
		slow = slow->Next;
		fast = fast->Next->Next;
		if(slow == fast)
		{
			return true;
		}
	}
	return false;
}
//拓展一:查找环的入口
Position LocateEntry(List L)
{
	if(L == NULL)
	{
		printf("Empty List\r\n");
		return NULL;
	}

	Position slow = L->Next;
	Position fast = L->Next;

	while(fast != NULL && fast->Next != NULL)
	{
		slow = slow->Next;
		fast = fast->Next->Next;
		
		if(slow == fast)
		{
			break;
		}
	}
	if(fast == NULL || slow == NULL)
	{
		printf("No circle\r\n");
		return NULL;
	}

	slow = L->Next;

	while(slow != fast)
	{
		slow = slow->Next;
		fast = fast->Next;
	}
	return slow;
}

//删除链表中倒数第K个节点
Position FindKNodeInList(List L, int K)
{
	if(L == NULL)
	{
		printf("Empty NULL\r\n");
		return NULL;
	}

	Position slow = L->Next;
	Position fast = L->Next;

	int i = 0;
	for(i = 0; i < K; ++i)
	{
		if(fast->Next == NULL)
		{
			return NULL;
		}
		fast = fast->Next;
	}	
	
	while(fast->Next != NULL)
	{
		slow = slow->Next;
		fast = fast->Next;
	}
	return slow;
}

//合并两个有序的链表
List Merge(List L1, List L2)
{
	List L3 = (List)malloc(sizeof(struct Node));
	if(L3 == NULL)
	{
		return NULL;
	}
	
	L3->Next = NULL;

	Position Pc = L3;
	Position Pa = L1->Next;
	Position Pb = L2->Next;

	while(Pa && Pb)
	{
		if(Pa->Element > Pb->Element)
		{
			Pc->Next = Pa;
			Pc = Pa;
			Pa = Pa->Next;
		}
		else
		{
			Pc->Next = Pb;
			Pc = Pb;
			Pb = Pb->Next;
		}
	}

	Pc->Next = Pa?Pa:Pb;
	
	return L3;
}



