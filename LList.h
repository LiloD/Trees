#include "Link.h"
#include "List.h"
#ifndef _LLIST_H
#define _LLIST_H

template<class Elem>
class LList: public List<Elem>
{
public:
	typedef Link<Elem>* PtrToNode;
	static const int DefaultListSize = 100;

	LList(int size = DefaultListSize){ init();}
	~LList(){ removeall();}
	void clear(){ removeall(); init();}

	bool insert(const Elem&);
	bool append(const Elem&);
	bool remove(Elem&);
	void setStart()
	{
		fence = head;
		rightcnt +=leftcnt;
		leftcnt = 0;
	}

	void setEnd()
	{
		fence = tail;
		leftcnt += rightcnt;
		rightcnt = 0;
	}

	void prev();
	void next()
	{
		if (fence != tail)
		{
			fence = fence ->next;
			rightcnt--;
			leftcnt++;
		}
	}

	int leftLength() const { return leftcnt;}
	int rightLength() const { return rightcnt;}

	bool setPos(int pos);
	bool getValue(Elem& it) const 
	{
		if (rightLength() == 0)
		{
			return false;
		}
		it = fence->next->element;
		return true;
	}
	void print() const;


private:
	PtrToNode head;
	PtrToNode tail;
	PtrToNode fence;
	int leftcnt;
	int rightcnt;

	void init()
	{
		fence = tail = head = new Link<Elem>;
		leftcnt = rightcnt = 0;
	}

	void removeall()
	{
		while(head != NULL)
		{
			fence = head;
			head = head->next;
			delete fence;
		}
	}
};


#endif