/**
 *
 * @file linklist.cpp
 * @breif 实现LinkList类中成员函数的定义
 * @author sunboyan 2011756
 * @email 1363011411@qq.com
 * @version 1.0.0
 * @date 9/17/2021 18:00
 *
 */

#include "linklist.h"
#include "listnode.h"

LinkList::LinkList()
{
	count = 0;
	totalcount = 0;
	head = new ListNode();
}

LinkList::~LinkList()
{
	while (count > 0)
	{
		ListNode* temp = head->next;
		head->next = head->next->next;
		count--;
		delete temp;
	}
}

void LinkList::operator=(const LinkList& copy)
{
	ListNode* ptr = this->head;
	while (ptr->next != nullptr)
	{
		head->next = ptr->next;
		delete ptr;
		ptr = head;
	}
	this->head->next = copy.head->next;
}

void LinkList::insert(ListNode* listNode)
{
	ListNode* ptr = head;
	while (ptr->next)
	{
		if (*listNode < ptr->next)
		{
			break;
		}
		ptr = ptr->next;
	}
	if (ptr == head)
	{
		listNode->next = head->next;
		head->next = listNode;
		count++;
		return;
	}
	if ((*ptr) == listNode)
	{
		ptr->add();
		delete listNode;
		return;
	}
	else
	{
		listNode->next = ptr->next;
		ptr->next = listNode;
		count++;
		return;
	}

}

void LinkList::remove(int position)
{
	int ptr_pos = 0;
	ListNode* ptr = head;
	while (ptr_pos < position)
	{
		ptr = ptr->next;
		ptr_pos++;
	}
	ListNode* temp = ptr->next->next;
	delete ptr->next;
	ptr->next = temp;
	count--;
}

void LinkList::insert(ListNode* a, ListNode* b)
{
	ListNode* temp = b->next->next;
	b->next->next = a->next;
	a->next = b->next;
	b->next = temp;
}

int LinkList::gettotalcount()
{
	return this->totalcount;
}

void LinkList::increment()
{
	totalcount++;
}

ListNode* LinkList::gethead()
{
	return head;
}

void LinkList::asort()
{
	ListNode* ptr = head;
	while (ptr->next != nullptr)
	{
		ListNode* mptr = ptr;
		ListNode* maxptr = mptr;
		while (mptr->next != nullptr)
		{
			if (mptr->next->gt(maxptr->next))
			{
				maxptr = mptr;
			}
			mptr = mptr->next;
		}
		if (ptr != maxptr)
		{
			insert(ptr, maxptr);
		}
		ptr = ptr->next;
		if (ptr == nullptr)
			return;
	}
}

