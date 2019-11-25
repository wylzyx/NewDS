#pragma once
#include<stdlib.h>

typedef int SLDataType;
// ˳���Ķ�̬�洢 
typedef struct SeqList 
{     
	SLDataType* _array; // ָ��̬���ٵ�����   
	size_t _size ;     // ��Ч���ݸ���   
	size_t _capacity ; // �����ռ�Ĵ�С
}SeqList;

// ������ɾ��Ľӿ� 
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

// ��չ������ʵ��
void SeqListBubbleSort(SeqList* sl);
int SeqListBinaryFind(SeqList* sl, SLDataType x); 
// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
