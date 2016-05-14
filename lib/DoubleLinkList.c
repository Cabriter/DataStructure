#include "stdio.h"

typedef struct DulNode
{
	int data;
	struct DulData *prior;
	struct DulData *next;
}DulNode,*DuLinkList;

int DulListCreate();
int DulListInsert();
int DulListDelete();
int DulListSet();
int DulListFind();
int CalcDulListLength();


int main()
{

	return 0;
}
