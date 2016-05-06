#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define MAXSIZE 20
#define ERROR 0

typedef struct Node //Node struct
{
	int data;
	struct Node* next;
}Node;

typedef struct Node* LinkList;//def Link List

int GetElem(LinkList L,int i,int* e);
int ListInsert(LinkList* L,int i,int e);
int ListDelete(LinkList* L,int i,int* e);
void CreateListHead(LinkList* L,int n);
void CreateListTail(LinkList* L,int n);
int ClearList(LinkList* L);
int CalcListLength(LinkList L);

int main()
{
	//Test Code

	//Node n;
	LinkList L;// = &n;
	CreateListHead(&L,20);
	//CreateListTail(&L,20);
	//int i;
	//for(i = 0;i < MAXSIZE;i++)
	//{
	//	 ListInsert(&L,i + 1,i + 1);
	//}

	int index;
	int value;
	do
	{
		scanf("%d",&index);
		if(index == 100)
		{
		  ClearList(&L);
		  printf("L lenth = %d\n",CalcListLength(L));
		  index = 99;
		}
		if(GetElem(L,index,&value))
		{
			printf("pos %d = %d.\n",index,value);
		}else
		{
			printf("ERROR\n");
		}
	}while(index != 99);

	return 0;
}

int GetElem(LinkList L,int i,int* e)
{
	if(CalcListLength(L) == 0)return ERROR;
	int j;
	LinkList p;
	p = L->next;
	j = 1;
	while(p && j < i)
	{
		p = p->next;
		++j;
	}
	if(!p || j > i)
	  return ERROR;
	*e = p->data;
	return 1;
}

int ListInsert(LinkList* L,int i,int e)
{
	int j;
	LinkList p,s;
	p = *L;
	j = 1;
	while(p && j < i)
	{
		p = p->next;
		++j;
	}
	if(!p || j > i)
	  return ERROR;
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 1;
}

int ListDelete(LinkList* L,int i,int* e)
{
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	while(p->next && j < i)
	{
		p = p->next;
		++j;
	}
	if(!(p->next) || j > i)
	  return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return 1;
}

void CreateListHead(LinkList* L,int n)
{
	LinkList p;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for(i = 0;i < n;i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;//1-100
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

void CreateListTail(LinkList* L,int n)
{
	LinkList p,r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for(i = 0;i < n;i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;//1~100
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

int ClearList(LinkList* L)
{
	LinkList p,q;
	p = (*L)->next;
	while(p)
	{
		printf("free data = %d\n",p->data);
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return 1;
}

int CalcListLength(LinkList L)
{
	LinkList p;
	int length = 0;
	p = L->next;
	while(p)
	{
		length++;
		p = p->next;
	}
	return length;
}
