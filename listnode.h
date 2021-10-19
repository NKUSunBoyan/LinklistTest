
#pragma once
/**
 *@brief 链表的节点类，数据成员包括字符串，计算词频的整数，指向后继节点的指针。
 * 同时也实现了部分运算符的重载便于比较排序。
 * 访问权限设为public便于操作。
 */
class ListNode {
public:

	char* entry;
	ListNode* next;
	int num;
	ListNode();
	~ListNode();
	ListNode(char*);
	bool operator==(ListNode* listnode);
	bool operator<(ListNode* listnode);
	bool gt(ListNode* listnode);
	bool eq(ListNode* listnode);
	void add();
};