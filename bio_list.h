#ifndef _BIO_LIST_H__
#define _BIO_LIST_H__

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;


struct Node
{
	ElementType Element;
	Position Pre;
	Position Next;
};


List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);


#endif
