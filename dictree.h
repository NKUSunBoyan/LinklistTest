#pragma once
#include "node.h"
/**
 *@brief �����ֵ����࣬ʵ�ּ򵥵�ͣ�ʱ��ʵĲ��룬�Լ��������ղ��ҡ�
 *
 */

class Dictree {
public:
	Dictree();
	~Dictree();
	void insert(char* s);
	bool search(char* s);
	void remove(Node* entry);
	Node* entry;

};
