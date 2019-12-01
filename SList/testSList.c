#include"SList.h"

void testSList()
{
	SList sl;
	
	SListInit(&sl);
	SListPushBack(&sl, 1);	
	SListPushBack(&sl, 1);
	SListPushBack(&sl, 2);
	SListPushBack(&sl, 3);
	SListPushBack(&sl, 2);
	SListPrint(&sl);
	
	SListPushFront(&sl, 3);
	SListPrint(&sl);

	SListRemove(&sl, 2);
	SListPrint(&sl);
	
	SListPopFront(&sl);
	SListPopBack(&sl);
	SListPrint(&sl);
	
	SListDestory(&sl);
}

int main()
{
	testSList();
	getchar();
	return 0;
}