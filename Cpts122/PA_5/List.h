#pragma once
#include "listNode.h"

template <class T>
class List
{
public:
	List();
	~List();
	int count;
	void insertNode(listNode<T>& e);
	listNode<T>* get_head() { return head; }
	void set_head(T newdata) { head = new listNode<T>(newdata); }
private:
	listNode<T> *head;
};

template <class T> 
void List<T> ::insertNode(listNode<T> & e)
{
	listNode<T> *list = head;
	if (list == nullptr)
	{

		*list = e;
		count++;
	}
	else
	{
		while (list != nullptr)
		{
			list = list->getnext();
			count++;
		}
		list->setnext(&e);

	}

}

template <class T>
List<T>::List()
{
}

template <class T>
List<T>::~List()
{
}


