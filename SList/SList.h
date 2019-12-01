#include<stdio.h>

//��ͷ�����ѭ��������ɾ���ʵ��
typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _head;
}SList;

void SListInit(SList* plist); 
void SListDestory(SList* plist);
SListNode* CreateSListNode(SLTDataType x);

void SListPushFront(SList* plist, SLTDataType x);
void SListPushFront(SList* plist, SLTDataType x);
void SListPopFront(SList* plist); 
void SListPopBack(SList* plist);

SListNode* SListFind(SList* plist, SLTDataType x); 
// ��pos�ĺ�����в��� 
void SListInsertAfter(SListNode* pos, SLTDataType x); 
void SListEraseAfter(SListNode* pos); 
void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SList* plist);