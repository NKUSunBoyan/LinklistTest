
#pragma once
/**
 *@brief ����Ľڵ��࣬���ݳ�Ա�����ַ����������Ƶ��������ָ���̽ڵ��ָ�롣
 * ͬʱҲʵ���˲�������������ر��ڱȽ�����
 * ����Ȩ����Ϊpublic���ڲ�����
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