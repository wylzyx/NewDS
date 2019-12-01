#include"SList.h"
#include<assert.h>
#include<malloc.h>

void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}
void SListDestory(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		SListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
}
SListNode* CreateSListNode(SLTDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->_data = x;
	newNode->_next = NULL; 
	return newNode;
}

void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* newNode = CreateSListNode(x);
	newNode->_next = plist->_head;
	plist->_head = newNode;
}
void SListPushBack(SList* plist, SLTDataType x)
{
	assert(plist);
	if (plist->_head == NULL)
	{
		plist->_head = CreateSListNode(x);
	}
	else
	{
		SListNode* tail = plist->_head;
		while (tail->_next)
		{
			tail = tail->_next;
		}
		tail->_next = CreateSListNode(x);
	}
}
void SListPopFront(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	plist->_head = cur->_next;
	free(cur);
	cur = NULL;
}
void SListPopBack(SList* plist)
{
	assert(plist);
	SListNode *tail = plist->_head;
	SListNode *prev = NULL;
	if (tail->_next == NULL)
	{
		free(tail);
		plist->_head = NULL;
	}
	else
	{
		while (tail->_next)
		{
			prev = tail;
			tail = tail->_next;
		}
		free(tail);
		prev->_next = NULL;
	}
}

SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
// 在pos的后面进行插入 
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* newNode = CreateSListNode(x);
	SListNode* next = pos->_next;
	pos->_next = newNode;
	newNode->_next = next;
}
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode* next = pos->_next;
	SListNode* nextNext = next->_next;
	pos->_next = nextNext;
	free(next);
	next = NULL;
}
void SListRemove(SList* plist, SLTDataType x)
{
	assert(plist);

	SListNode *prev = plist->_head;
	SListNode *cur = prev->_next;
	while (cur)
	{
		if (cur->_data == x)
		{
			prev->_next = cur->_next;
			free(cur);
			cur = prev->_next;
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
	}
	if (plist->_head->_data == x)
		plist->_head = plist->_head->_next;
}

void SListPrint(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}