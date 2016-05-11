#include "stdio.h"

#define MAXSIZE 1000

typedef struct
{
	int data;
	int cur;
}Component,StaticLinkList[MAXSIZE];

int InitList(StaticLinkList space);
int Malloc_SLL(StaticLinkList space);
int ListInstert(StaticLinkList L,int i,int e);
int ListDelete(StaticLinkList L,int i);
void Free_SSL(StaticLinkList space,int k);
int ListLength(StaticLinkList L);


int main()
{






	return 1;
}

int InitList(StaticLinkList space)
{
	int i;
	for(i = 0;i < MAXSIZE - 1;i++)
	{
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0;

	return 1;
}

int Malloc_SLL(StaticLinkList space)
{
	int i = sspace[0].cur;
	if(space[0].cur)
	  space[0].cur = space[i].cur;

	return i;
}
