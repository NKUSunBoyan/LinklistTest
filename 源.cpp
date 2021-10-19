/**
 * 
 * @file main.cpp
 * @breif �������Ҫ���֣�ʵ���ַ������ұȽϣ��Լ���Ҫ�ļ������������ʵ��
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
 * @brief ������������������ļ����������������Ҫ���ܡ�
 * @param �������������ʡ�ԡ�
 * @return ����0˵���������С�
 */

int main()
{

/**
 *�����ַ���������ʱ���stopwords 
 */
	char* stopwords[883];

/**
 *stopwords�ļ�������
 */
	fstream fstopwords;
	fstopwords.open("stopwords.txt", ios::in);
	if (!fstopwords.is_open())
		return 0;

/**
 * ѭ�����ж�ȡʱ�����ַ��������ľֲ�����
 */
	int stopwords_in_ptr = 0;
	while (!fstopwords.eof())
	{

/**
 * �����ַ������ȼ����ľֲ�����
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
 * �����ֵ���
 */
		stopwordstree.insert(stopwords[i]);
	}
	for (int i = 0; i < 883; i++)
	{
		delete[] stopwords[i];
	}

/**
 * �½������ָ������
 */
	LinkList**wordslist = new LinkList*[27];
	for (int i = 0; i < 27; i++)
	{
		wordslist[i] = new LinkList;
	}

/**
 * ���ı�intext�ļ�������
 */
	fstream fintext;
	fintext.open("intext.txt", ios::in|ios::out);
	char a = ' ';
	while (!fintext.eof())
	{

/**
 * ��ȡ���������Ϸ��ַ���ʼ���뵥�ʡ�
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
 * �½�����ڵ����˳������ʱ����ĵ��ʡ�
 */
			ListNode* snode = new ListNode(s);
			if (s[0] == 39)
			{

/**
 * ������"'"��ͷ�ĵ��ʣ�����ڶ�ʮ�߸�����
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
 *��������ָ����н�������ɰ���Ƶ����
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
 * �������ͳ�ƽ����"outtext"��
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
		fouttext << "��" << ptr->entry[0] << "Ϊ��ͷ�ĵ����ܹ��У�" << wordslist[i]->gettotalcount() << "��" << endl;
		while (ptr->next)
		{
			fouttext <<setiosflags(ios::left)<< setw(20) << ptr->entry << ": " << ptr->num << endl;
			ptr = ptr->next;
		}
		fouttext << setiosflags(ios::left) << setw(20) << ptr->entry << ": " << ptr->num << endl;
		fouttext << endl;
	}

/**
 * ���ڴ�����
 */
	for (int i = 0; i < 27; i++)
	{
		wordslist[i]->~LinkList();
	}
	stopwordstree.remove(stopwordstree.entry);
	return 0;
}
