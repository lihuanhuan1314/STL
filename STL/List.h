#pragma once
#include<assert.h>
#include"Iterator.h"
#include"Alloc.h"

template<class T>
struct ListNode
{
	T _data;// 结点数据
	ListNode<T>* _next;// 指向前一个结点的指针
	ListNode<T>* _prev;// 指向后一个结点的指针

	ListNode<T>(const T& x=T())
		: _data(x)
		, _next(NULL)
		, _prev(NULL)
	{}
};
// List的迭代器
//T  T&  T*
template<class T,class Ref,class Ptr>
class ListIterator
{
public:
	typedef ListIterator<T, T&, T*>             Iterator;
	// 这里Ref、Ptr模板参数主要是为了方便复用的方式实现const类型的迭代器ConstIterator
	typedef ListIterator<T, const T&, const T*> ConstIterator;
	typedef ListIterator<T, Ref, Ptr> Self;

	// List是个双向链表，所以它的迭代器是一个双向迭代器类型
	typedef BidirectionalIteratorTag IteratorCategory;
	typedef T ValueType;
	typedef Ptr Pointer;
	typedef Ref Reference;
	typedef ptrdiff_t DifferenceType;

	typedef ListNode<T>* LinkType;
	LinkType _node;// 指向节点的指针

	ListIterator(LinkType x) 
		: _node(x)
	{}
	ListIterator(const Iterator& x)
		:_node(x._node)
	{}
	ListIterator() 
	{}

	bool operator==(const Self& x) const
	{ 
		return _node == x._node; 
	}
	bool operator!=(const Self& x) const
	{ 
		return _node != x._node; 
	}
	Reference operator *() 
	{ 
		return _node->_data;
	}
	Pointer operator ->()
	{
		return &(_node->_data);
	}
	Self& operator ++()
	{
		_node = _node->_next;
		return *this;
	}
	Self operator ++(int)
	{
		Self tmp(_node);
		_node = _node->_next;
		return tmp;
	}
	Self& operator --()
	{
		_node = _node->_prev;
		return *this;
	}
	Self operator --(int)
	{
		Self tmp(_node);
		_node = _node->_prev;
		return tmp;
	}
};
//
// 设计为双向循环链表
//
template<class T, class _Alloc = Alloc>
class List
{
public:
	typedef ListNode<T> Node;
public:
	// 
	// 定义迭代器、const迭代器、逆置迭代器
	//
	typedef ListIterator<T,T&,T*> Iterator;
	typedef ListIterator<T, const T&, const T*> ConstIterator;
	//typedef ReverseIterator<ConstIterator> ConstReverseIterator;
	typedef ReverseIterator<Iterator> ReverseIterator;
	// 重定义空间配置器
	typedef SimpleAlloc<ListNode<T>, _Alloc> DataAllocator;


	List()
		:_head(new Node)
	{
		_head->_next = _head;
		_head->_prev = _head;
	}
public:
	// 在pos前插入一个节点
	Iterator Insert(Iterator pos,const T& x)
	{
		Node* cur = pos._node;
		Node* prev = cur->_prev;
		Node* tmp = new Node(x);

		tmp->_next = cur;
		cur->_prev = tmp;
		tmp->_prev = prev;
		prev->_next = tmp;
		return tmp;
	}
	// 删除pos指向的节点，返回pos之后的一个节点
	Iterator Erease(Iterator pos)
	{
		assert( pos!=End() );
		Node* next = (pos._node)->_next;
		Node* prev = (pos._node)->_prev;

		next->_prev = prev;
		prev->_next = next;
		delete pos._node;
		return next;
	}
	void PushBack(const T& x)
	{
		Insert(End(),x);
	}
	void PushFront(const T& x)
	{
		Insert(Begin(), x);
	}
	void PopFront() 
	{ 
		Erease(Begin()); 
	}
	void PopBack() 
	{
		Erease(--End());
	}
	
	/*void PushBack(const T& x)
	{
		Node* _tail = _head->_prev;
		Node* tmp = new Node(x);
		_tail->_next = tmp;
		tmp->_prev = _tail;

		tmp->_next =_head;
		_head->_prev = tmp;
	}*/
	
	bool Empty() const 
	{ 
		return _head->_next == _head;
	}
	Iterator Begin()
	{
		return _head->_next;
	}
	ConstIterator Begin() const
	{
		return ConstIterator(_head->_next);
	}
	Iterator End()
	{
		return _head;
	}
	ConstIterator End() const
	{
		return ConstIterator(_head);
	}
	ReverseIterator Rbegin() 
	{
		return ReverseIterator(End());
	}
	/*ConstReverseIterator rbegin() const 
	{
		return ConstReverseIterator(End());
	}*/
	ReverseIterator rend() 
	{ 
		return ReverseIterator(Begin()); 
	}
	//ConstReverseIterator rend() const 
	//{
	//	return ConstReverseIterator(Begin());
	//}
protected:
	Node* _head;
};
void Printf(const List<int>& l)
{
	List<int>::ConstIterator it = l.Begin();
	while (it != l.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void Test()
{	
	List<int> l;
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(5);
	l.PushFront(1);
	l.PushFront(6);
	l.PopBack();
	l.PopFront();
	/*List<int>::Iterator it = l.Begin();
	while (it != l.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;*/
	Printf(l);
}