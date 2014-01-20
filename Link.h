#ifndef _LINK_H
#define _LINK_H
#include <cstddef>
template<class Elem>
class Link
{
public:
	Elem element;		//value for this node
	Link *next;		//Pointer to next node
	Link(const Elem& elemval, Link* nextval = NULL)
	{
		element = elemval;
		next = nextval;
	}
	Link(Link* nextval = NULL)
	{
		next = nextval;
	}
};
#endif