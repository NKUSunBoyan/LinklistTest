#pragma once
#include "listnode.h"
/**
 *@brief ������Ķ��壬�����˲����õ��ĺ�����
 * ���ڵ���Ƶ�ʵ�ͳ������������һЩ���ͱ�����
 */

class LinkList {
public:
	LinkList();
	~LinkList();
	void operator=(const LinkList& copy);
	void insert(ListNode* listNode);
	void remove(int position);
	void insert(ListNode* a, ListNode* b);
	int gettotalcount();
	void increment();
	int totalcount;
	ListNode*gethead();
	void asort();
protected:
	int count;		
	ListNode* head;

};