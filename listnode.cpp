/**
 *
 * @file listnode.cpp
 * @breif 实现ListNode类中成员函数的定义
 * @author sunboyan 2011756
 * @email 1363011411@qq.com
 * @version 1.0.0
 * @date 9/17/2021 18:00
 *
 */

#include "listnode.h"

ListNode::ListNode()
{
	num = 1;
	entry = nullptr;
	next = nullptr;
}

ListNode::ListNode(char* s)
{
	int i = 0;
	num = 1;
	while (s[i])
	{
		i++;
	}
	entry = new char[i + 1];
	for (int j = 0; j < i; j++)
	{
		entry[j] = s[j];
	}
	entry[i] = 0;
	this->next = nullptr;
}

bool ListNode::operator==(ListNode* listnode)
{
	int i = 0;
	while (this->entry[i] || listnode->entry[i])
	{
		if (this->entry[i] != listnode->entry[i])
			return false;
		else
			i++;
	}
	return true;
}

bool ListNode::operator<(ListNode* listnode)
{
	int i = 0;
	while (!this->entry[i] == 0 || !listnode->entry[i] == 0)
	{
		if (this->entry[i] > listnode->entry[i])
			return false;
		else if (this->entry[i] < listnode->entry[i])
			return true;
		else
			i++;
	}
	return false;
}

bool ListNode::gt(ListNode* listnode)
{
	return this->num>listnode->num;
}

bool ListNode::eq(ListNode* listnode)
{
	return this->num==listnode->num;
}

void ListNode::add()
{
	num++;
}

ListNode::~ListNode()
{
	delete[] entry;
}
