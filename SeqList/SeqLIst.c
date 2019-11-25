#include"SeqList.h"
#include<assert.h>
#include<malloc.h>
// 基本增删查改接口 
void SeqListInit(SeqList* sl)
{
	assert(sl);
	sl->_array = NULL;
	sl->_size = 0;
	sl->_capacity = 0;
}
void SeqListDestory(SeqList* sl)
{
	assert(sl);
	if (sl->_array)
	{
		free(sl->_array);
		sl->_array = NULL;
		sl->_size = sl->_capacity = 0;
	}
}

void CheckCapacity(SeqList* sl)
{
	assert(sl);
	if (sl->_size == sl->_capacity)
	{
		size_t newcapacity = (sl->_capacity == 0 ? 5 : 2 * sl->_capacity);
		sl->_array = (SLDataType*)realloc(sl->_array, newcapacity * sizeof(SLDataType));
		assert(sl->_array);
		sl->_capacity = newcapacity;
	}
}
void SeqListPushBack(SeqList* sl, SLDataType x)
{
	assert(sl);
	CheckCapacity(sl);
	sl->_array[sl->_size] = x;
	sl->_size++;
}
void SeqListPopBack(SeqList* sl)
{
	assert(sl);
	if (sl->_size > 0)
		sl->_size--;
}
void SeqListPushFront(SeqList* sl, SLDataType x)
{
	assert(sl);
	CheckCapacity(sl);
	//移动元素,从后往前
	size_t end = sl->_size;
	while (end > 0)
	{
		sl->_array[end] = sl->_array[end - 1];
		end--;
	}
	sl->_array[0] = x;
	sl->_size++;
}
void SeqListPopFront(SeqList* sl)
{
	assert(sl);
	size_t start = 0;
	while (start < sl->_size - 1)
	{
		sl->_array[start] = sl->_array[start + 1];
		start++;
	}
	sl->_size--;
}

int SeqListFind(SeqList* sl, SLDataType x)
{
	assert(sl);
	size_t index = 0;
	for (; index < sl->_size; ++index)
	{
		if (sl->_array[index] == x)
			return index;
	}
	return -1;
}
void SeqListInsert(SeqList* sl, size_t pos, SLDataType x)
{
	assert(sl && pos < sl->_size);
	CheckCapacity(sl);
	size_t end = sl->_size;
	while (end > pos)
	{
		sl->_array[end] = sl->_array[end - 1];
		end--;
	}
	sl->_array[pos] = x;
	sl->_size--;
}
void SeqListErase(SeqList* sl, size_t pos)
{
	assert(sl && pos < sl->_size);
	size_t start = pos + 1;
	while (start < sl->_size)
	{
		sl->_array[start - 1] = sl->_array[start];
		start++;
	}
	sl->_size--;
}
void SeqListRemoveAll(SeqList* sl, SLDataType x)
{
	assert(sl);
	size_t index = 0;
	for (size_t i = 0; i < sl->_size; i++)
	{
		if (sl->_array[i] != x)
		{
			sl->_array[index] = sl->_array[i];
			index++;
		}
	}
	sl->_size = index;
}
void SeqListModify(SeqList* sl, size_t pos, SLDataType x)
{
	assert(sl && pos < sl->_size);
	sl->_array[pos] = x;
}
void SeqListPrint(SeqList* sl)
{
	assert(sl);
	for (size_t i = 0; i < sl->_size; i++)
	{
		printf("%d ", sl->_array[i]);
	}
	printf("\n");
}

// 扩展面试题实现
void SeqListBubbleSort(SeqList* sl)
{
	assert(sl);
	//升序
	size_t end = sl->_size;
	while (end > 1)
	{
		//单趟排序
		int flag = 0;
		for (size_t i = 1; i < end; ++i)
		{
			if (sl->_array[i - 1] > sl->_array[i])
			{
				flag = 1;
				SLDataType tmp = sl->_array[i - 1];
				sl->_array[i - 1] = sl->_array[i];
				//存放两者中更大的元素
				sl->_array[i] = tmp;
			}
		}
		if (flag == 0)
			break;
		--end;
	}
}
int SeqListBinaryFind(SeqList* sl, SLDataType x)
{
	assert(sl);
	size_t start = 0;
	size_t end = sl->_size - 1;
	while (start <= end)
	{
		size_t mid = start + (end - start) / 2;
		if (sl->_array[mid] == x)
			return mid;
		else if (sl->_array[mid] > x)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}
// 本题要求：时间复杂度：O(N) 空间复杂度 O(1)
