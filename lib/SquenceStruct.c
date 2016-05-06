#include "stdio.h"

#define MAXSIZE 20
#define ERROR 0

typedef struct
{
	int data[MAXSIZE];
	int length;
}SqList;

int GetElem(SqList L,int i,int *e);
int ListInsert(SqList* L,int i,int e);
int ListDelete(SqList* L,int i,int* e);

int main()
{
	SqList L;
	L.length = 0;
	int e;
	//test code
	int i = 1;
	for(;i <= 20;i++)
	{
		if(ListInsert(&L,i,i))
		{
			printf("%s","insert true Sq\n");
		}else
		{
			printf("%s","insert false\n");
		}
	}

	printf("%s","delete:");
	for(i = 6;i <= 10;i++)
	{
		ListDelete(&L,i,&e);
		printf("delete pos %d =  %d",i,e);
	}

	printf("%s","start:\n");
	
	int index = 0;
	do
	{
		scanf("%d",&index);
		if(index < 0 || index > MAXSIZE) continue;
		if(GetElem(L,index,&e))
		{
			printf("pos %d is %d.\n",index,e);
		}else
		{
			printf("%s","ERROR\n");
		}

	}while(index != 99);
	
	return 1;
}

int ListInsert(SqList* L,int i,int e)
{
	int k;
	if(L->length == MAXSIZE)
	  return ERROR;
	if(i < 0 || i > L->length + 1)
	  return ERROR;
	if(i <= L->length)
	{
		for(k = L->length -1;k > i;k--)
		  L->data[k + 1] = L->data[k];
	}
	L->data[i - 1] = e;
	L->length++;
	return 1;
}

int GetElem(SqList L,int i,int* e)
{
	if(i < 1 || i > MAXSIZE || L.length < i)
	  return 0;
	*e = L.data[i -1];
	return 1;
}

int ListDelete(SqList* L,int i,int* e)
{
	int k;
	if(L->length == 0)
	{
		return ERROR;
	}
	if(i < 1 || i > L->length)
	{
		return ERROR;
	}
	*e = L->data[i - 1];
	if(i < L->length)
	{
		for(k = i;k < L->length;k++)
		  L->data[k - 1] = L->data[k];
	}
	L->length--;
	return 1;
}
