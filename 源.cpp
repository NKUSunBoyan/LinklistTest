/**
 * 
 * @file main.cpp
 * @breif 程序的主要部分，实现字符串查找比较，以及主要文件流输入输出的实现
 * @author sunboyan 2011756
 * @email 1363011411@qq.com
 * @version 1.0.0
 * @date 9/17/2021 18:00
 * 
 */



#include<iostream>
#include<fstream>
#include<iomanip>
#include "listnode.h"
#include "linklist.h"
#include "node.h"
#include "dictree.h"
using namespace std;






/**
 * @brief 主函数用于输入输出文件，构建对象，完成主要功能。
 * @param 控制行命令参数省略。
 * @return 返回0说明正常运行。
 */

int main()
{

/**
 *定义字符串数组暂时存放stopwords 
 */
	char* stopwords[883];

/**
 *stopwords文件输入流
 */
	fstream fstopwords;
	fstopwords.open("stopwords.txt", ios::in);
	if (!fstopwords.is_open())
		return 0;

/**
 * 循环按行读取时用于字符串计数的局部变量
 */
	int stopwords_in_ptr = 0;
	while (!fstopwords.eof())
	{

/**
 * 用于字符串长度计数的局部变量
 */
		int stopwords_buffer_size = 0;
		char stopwords_buffer[100] = { 0 };
		fstopwords.getline(stopwords_buffer, 100);
		while (*(stopwords_buffer + stopwords_buffer_size) != 0)
		{
			stopwords_buffer_size++;
		}
		stopwords[stopwords_in_ptr] = new char[stopwords_buffer_size + 1];
		for (int i = 0; i < stopwords_buffer_size; i++)
		{
			stopwords[stopwords_in_ptr][i] = stopwords_buffer[i];
		}
		stopwords[stopwords_in_ptr][stopwords_buffer_size] = 0;
		stopwords_in_ptr++;
	}

	fstopwords.close();
	Dictree stopwordstree;
	for (int i = 0; i < 883; i++)
	{

/**
 * 插入字典树
 */
		stopwordstree.insert(stopwords[i]);
	}
	for (int i = 0; i < 883; i++)
	{
		delete[] stopwords[i];
	}

/**
 * 新建链表的指针数组
 */
	LinkList**wordslist = new LinkList*[27];
	for (int i = 0; i < 27; i++)
	{
		wordslist[i] = new LinkList;
	}

/**
 * 长文本intext文件流对象
 */
	fstream fintext;
	fintext.open("intext.txt", ios::in|ios::out);
	char a = ' ';
	while (!fintext.eof())
	{

/**
 * 读取规则：遇到合法字符开始输入单词。
 */
		while ((a < 'A' || (a > 'Z' && a < 'a') || a>'z') && a != 39 && (!fintext.eof()))
		{
			fintext.get(a);
		}
		char s[30] = { 0 };
		int i = 0;
		while (((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || a == 39) && (!fintext.eof()))
		{
			if (a >= 'A' && a <= 'Z')
				a = a - 'A' + 'a';
			s[i] = a;
			i++;
			fintext.get(a);
		}
		if (fintext.eof())
			break;
		if (!stopwordstree.search(s))
		{

/**
 * 新建链表节点对象按顺序存入此时输入的单词。
 */
			ListNode* snode = new ListNode(s);
			if (s[0] == 39)
			{

/**
 * 若出现"'"开头的单词，存入第二十七个链表。
 */
				wordslist[26]->insert(snode);
				wordslist[26]->increment();
			}
			else
			{
				wordslist[s[0] - 'a']->insert(snode);
				wordslist[s[0] - 'a']->increment();
			}
		}
		
	}
	fintext.close();

/**
 *各个链表指针进行交换，完成按词频排序。
 */
	/*for (int i = 0; i <27; i++)
	{
		for (int j = 26; j > i; j--)
		{
			if (wordslist[j-1]->gettotalcount()<wordslist[j]->gettotalcount())
			{
				LinkList* temp = wordslist[j - 1];
				wordslist[j - 1] = wordslist[j];
				wordslist[j] = temp;
			}
		}
	}
	*/
	for (int i = 0; i < 26; i++)
	{
		wordslist[i]->asort();
	}

/**
 * 输出单词统计结果至"outtext"。
 */
	fstream fouttext;
	fouttext.open("outtext.txt", ios::out);
	for (int i = 0; i < 27; i++)
	{
		if (wordslist[i]->totalcount == 0)
		{
			fouttext << endl;
			continue;
		}
		ListNode* ptr = wordslist[i]->gethead();
		ptr = ptr->next;
		fouttext << "以" << ptr->entry[0] << "为开头的单词总共有：" << wordslist[i]->gettotalcount() << "个" << endl;
		while (ptr->next)
		{
			fouttext <<setiosflags(ios::left)<< setw(20) << ptr->entry << ": " << ptr->num << endl;
			ptr = ptr->next;
		}
		fouttext << setiosflags(ios::left) << setw(20) << ptr->entry << ": " << ptr->num << endl;
		fouttext << endl;
	}

/**
 * 堆内存清理
 */
	for (int i = 0; i < 27; i++)
	{
		wordslist[i]->~LinkList();
	}
	stopwordstree.remove(stopwordstree.entry);
	return 0;
}
