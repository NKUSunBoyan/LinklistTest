/**
 *
 * @file main.cpp
 * @breif 实现Dictree中成员函数的定义
 * @author sunboyan 2011756
 * @email 1363011411@qq.com
 * @version 1.0.0
 * @date 9/17/2021 18:00
 *
 */

#include "dictree.h"
#include "node.h"

Dictree::Dictree()
{
	entry = new Node;
}

Dictree::~Dictree()
{
	remove(entry);
}

void Dictree::insert(char* s)
{
	Node* ptr = entry;
	int i = 0;
	while (s[i])
	{
		if (s[i] == 39)
		{
			if (!ptr->child[26])
			{
				ptr->child[26] = new Node;
			}
			ptr = ptr->child[26];
		}
		else if (s[i] == '-')
		{
			if (!ptr->child[28])
			{
				ptr->child[28] = new Node;
			}
			ptr = ptr->child[28];
		}
		else
		{
			if (!ptr->child[s[i] - 'a'])
			{
				ptr->child[s[i] - 'a'] = new Node;
			}
			ptr = ptr->child[s[i] - 'a'];
		}
		i++;
	}
	if (!ptr->child[27])
	{
		ptr->child[27] = new Node;
	}
	return;
}

bool Dictree::search(char* s)
{
	int i = 0;
	Node* ptr = entry;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = s[i] - 'A' + 'a';
		}

		if (s[i] == '-' && ptr->child[28])
		{
			ptr = ptr->child[28];
			i++;
			continue;
		}
		else if (s[i] == 39 && ptr->child[26])
		{
			ptr = ptr->child[26];
			i++;
			continue;
		}
		else if (s[i] >= 'a' && s[i] <= 'z' && ptr->child[s[i] - 'a'])
		{
			ptr = ptr->child[s[i] - 'a'];
			i++;
			continue;
		}
		else
		{
			return false;
		}
	}
	if (ptr->child[27])
	{
		return true;
	}
	else
		return false;
}

void Dictree::remove(Node* ptr)
{
	int i = 0;
	for (int i = 0; i < 29; i++)
	{
		if (ptr->child[i] != nullptr)
		{
			remove(ptr->child[i]);
		}
	}
	ptr->~Node();
	return;
}