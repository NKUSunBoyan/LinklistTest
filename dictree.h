#pragma once
#include "node.h"
/**
 *@brief 定义字典树类，实现简单的停词表单词的插入，以及后续对照查找。
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
