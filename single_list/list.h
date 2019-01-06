#ifndef _LIST_H__
#define _LIST_H__

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

struct Node
{
	ElementType Element;
	Position Next;
};

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position Firtst(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);


void PrintList(List L);
int GetListLength(List L);
void Reversal(List L);
void ReversePrint(List L);
void SortList(List L);
void swap(ElementType *w1, ElementType *w2);
void BubbleSort(List L);


void QuickSort(Position L, Position end);


Position FindMiddle(List L);
List Merge(List L1, List L2);

#endif
