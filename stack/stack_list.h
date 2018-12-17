#ifndef _Stack_h_
#define _Stack_h_

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;
typedef int ElementType;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

void PrintStack(Stack S);

#endif 
