/**
 *
 * @file node.cpp
 * @breif ʵ����ֻ����һ��node�Ĺ��캯��
 * @author sunboyan 2011756
 * @email 1363011411@qq.com
 * @version 1.0.0
 * @date 9/17/2021 18:00
 *
 */

#include "node.h"

Node::Node()
{
	value = true;
	for (int i = 0; i < 29; i++)
	{
		child[i] = nullptr;
	}
}