#pragma once
#include "listnode.h"
/**
 *@brief 链表类的定义，定义了部分用到的函数。
 * 由于单词频率的统计所以设置了一些整型变量。
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