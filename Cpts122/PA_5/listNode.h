#pragma once
template <class T>
class listNode
{
	~listNode();
public:
	listNode();
	listNode* getnext() { return next; }
	void setnext(listNode *elem) { next = elem;}
	listNode<T>(const T&d) { data = d; }
	T getdata() { return data; }
private:
	listNode <T> *next = nullptr;
	T data;
};

template <class T>
listNode<T>::listNode()
{
	next = nullptr;
}

template <class T>
listNode<T>::~listNode()
{

}

template <class T>

listNode<T> *makenode(T newdata) { return new listNode<T>(newdata);}