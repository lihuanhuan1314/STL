#include<iostream>
using namespace std;
//������Ӧ��
//#include<vector>
//#include<list>
//void PrintVector(vector<int>& v)
//{
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//void PrintList(list<int>& l)
//{
//	list<int>::iterator it = l.begin();
//	while (it != l.end())
//	{	
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//void TestVector()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	PrintVector(v);
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		//������ʧЧ
//		vector<int>::iterator tmp = it;
//		++it;
//		if ((*tmp) % 2 == 0)
//		{
//			v.erase(tmp);
//		}
//
//		(*it)++;
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//void TestList()
//{
//	list<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_back(4);
//
//	PrintList(l);
//	list<int>::iterator it = l.begin();
//	while (it != l.end())
//	{
//		//������ʧЧ
//		/*list<int>::iterator tmp = it;
//		++it;
//		if ((*tmp) % 2 == 0)
//		{
//			l.erase(tmp);
//		}*/
//		//������ʧЧ
//		if ((*it) % 2 == 0)
//		{
//			it=l.erase(it);
//		}
//		else
//		{
//			++it;
//		}
//
//		(*it)++;
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}



#include"List.h"
#include"Vector.h"
#include"Iterator.h"
#include"Alloc.h"
#include"Construct.h"
#include"TypeTraits.h"
#include"Uninitialized.h"
int main()
{
	//TestVector();
	//TestList();
	Test();
	//TestAlloc1();
	//TestAlloc2();
	//TestAlloc3();
	return 0;
}