#include"SeqList.h"
#include<stdlib.h>
#include<time.h>

void testSeqList()
{
	SeqList sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 0);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);
	SeqListErase(&sl, 1);
	SeqListModify(&sl, 2, 10);
	SeqListPushFront(&sl, 2);
	for (int i = 0; i < 10; i++)
		SeqListPushBack(&sl, i);
	SeqListRemoveAll(&sl, 2);
	SeqListBubbleSort(&sl);
	printf("%d\n", SeqListBinaryFind(&sl, 3));
	SeqListPrint(&sl);
	SeqListDestory(&sl);
}

void test2SeqList()
{
	SeqList sl;
	SeqListInit(&sl);
	printf("生成数列：");
	for (int i = 0; i < 10; i++)
	{
		SeqListPushBack(&sl, rand() % 10 + 1);
	}
	SeqListPrint(&sl);
	printf("冒泡排序：");
	SeqListBubbleSort(&sl);
	SeqListPrint(&sl);
	SeqListDestory(&sl);
}

int main()
{
	srand((unsigned int)time(NULL));
	//testSeqList();
	test2SeqList();
	//当我们需要生成a - b的随机数的时候，我们可以使用rand() % (b - a + 1) + a
	/*int rand_num = 0;
	for (int i = 0; i < 10; i++)
	{
	printf("rand_num = %d\n", rand() % 10 + 1);
	}*/
	getchar();
	return 0;
}