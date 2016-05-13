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
	//test code

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
	int i = space[0].cur;
	if(space[0].cur)
	  space[0].cur = space[i].cur;

	return i;
}

int ListInstert(StaticLinkList L,int i,int e)
{
	int j,k,l;
	k = MAXSIZE - 1;
	if(i < 1 || i > ListLength(L) + 1)
	  return 0;
	j = Malloc_SLL(L);
	if(j)
	{
		L[j].data = e;
		for(l = 1;l <= i - 1;l++)
		{
			k = L[k].cur;
		}
		L[j].cur = L[k].cur;
		L[k].cur = j;
		return 1;
	}
	return 0;
}

int ListDelete(StaticLinkList L,int i)
{
	int j,k;
	if(i < 1||i > ListLength(L))
	{
		return 0;
	}
	k = MAXSIZE - 1;
	for(j = 1;j <= i - 1;j++)
	{
		k = L[k].cur;
	}
	j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SSL(L,j);
	return 1;

}

void Free_SSL(StaticLinkList space,int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

int ListLength(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE - 1].cur;
	while(i)
	{
		i = L[i].cur;
		j++;
	}
	return j;
}
