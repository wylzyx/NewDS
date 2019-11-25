#pragma once
#include<stdlib.h>

typedef int SLDataType;
// 顺序表的动态存储 
typedef struct SeqList 
{     
	SLDataType* _array; // 指向动态开辟的数组   
	size_t _size ;     // 有效数据个数   
	size_t _capacity ; // 容量空间的大小
}SeqList;

// 基本增删查改接口 
void SeqListInit(SeqList* sl);
void SeqListDestory(SeqList* sl);

void CheckCapacity(SeqList* sl); 
void SeqListPushBack(SeqList* sl, SLDataType x); 
void SeqListPopBack(SeqList* sl);
void SeqListPushFront(SeqList* sl, SLDataType x); 
void SeqListPopFront(SeqList* sl);

int SeqListFind(SeqList* sl, SLDataType x);
void SeqListInsert(SeqList* sl, size_t pos, SLDataType x);
void SeqListErase(SeqList* sl, size_t pos);
void SeqListRemoveAll(SeqList* sl, SLDataType x); 
void SeqListModify(SeqList* sl, size_t pos, SLDataType x); 
void SeqListPrint(SeqList* sl);

// 扩展面试题实现
void SeqListBubbleSort(SeqList* sl);
int SeqListBinaryFind(SeqList* sl, SLDataType x); 
// 本题要求：时间复杂度：O(N) 空间复杂度 O(1)
