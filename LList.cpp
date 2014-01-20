#include "LList.h"
#include <iostream>
using namespace std;

template<class Elem>
bool LList<Elem>::insert(const Elem& item)
{
	fence->next = new Link<Elem>(item, fence->next);
	if (tail == fence) 
	{
		tail = fence->next; // new tail?
	}
	rightcnt++;
	return true;
}

template<class Elem>
bool LList<Elem>::append(const Elem& item)
{
	tail = tail->next = new Link<Elem>(item,NULL); //pay attention here!
	rightcnt++;
	return false;
}

template<class Elem>
bool LList<Elem>::remove(Elem& it)
{
	if (fence->next == NULL)
	{
		return false;
	}

	it = fence->next->element;

	Link<Elem>* ltemp = fence->next;	
	fence->next = ltemp->next;

	//don't forget to handle the tail
	if (tail == ltemp)
	{
		tail = fence;
	}

	delete ltemp;
	rightcnt--;
	return true;
}


template<class Elem>
void LList<Elem>::prev()
{
	Link<Elem>* temp = head;
	if (fence == head)
	{
		return; //no previous element
	}

	//find the node before the fence node
	while(temp->next != fence)
	{
		temp = temp->next;
	}
	fence = temp;
	leftcnt--;
	rightcnt++;
}


template<class Elem>
bool LList<Elem>::setPos(int pos)
{
	if ( (pos<0) || (pos>rightcnt+leftcnt) )
	{
		return false;
	}

	fence = head;
	for (int i = 0; i < pos; ++i)
	{
		fence = fence->next;
	}
	return true;
}

template<class Elem>
void LList<Elem>::print() const
{
	Link<Elem>* temp = head;
	cout<< " < ";
	while(temp != fence)
	{
		cout<< temp->next->element << " ";
		temp = temp->next; 
	}
	cout<< " | ";
	while(temp->next != NULL)
	{
		cout<<temp->next->element<< " ";
		temp = temp->next;
	}
	cout<<" >\n";
}

int main()
{
	LList<int> llist;
	llist.append(1);
	llist.append(3);
	llist.append(20);
	llist.append(14);
	llist.next();
	llist.print();
	return 0;
}