#ifndef _LIST_H
#define _LIST_H

template<class T>
class List
{
public:
	//Reinitialize the list. The client is responsible for reclaiming the storage used by the list elements
	virtual void clear() = 0;

	//Insert an element at the front of the right partition. 
	//return true if successful, false if the list is full.
	virtual bool insert(const T&) = 0;

	//Append an element at the end of the right partition
	//Return true if successful, false if right partition is empty
	virtual bool append(const T&) = 0;


	//Remove the first element of the right partition.
	//return true if successful, false if right partition is empty
	//The element removed is returned in the parameter.(?)
	virtual bool remove(T&) = 0;

	//Place fence at list start, making left partition empty
	virtual void setStart() = 0;

	//Place fence at list end, making right partition empty
	virtual void setEnd() = 0;

	//Move fence one step left; no change if already at the start
	virtual void prev() = 0;

	//Move fence one step right; no change if already at the end
	virtual void next() = 0;

	//Return length of left partition
	virtual int leftLength() const = 0;

	//Return length of right partition
	virtual int rightLength() const = 0;

	//If pos or more elements are in the list,set the size of 
	// left partition to pos and return true. Otherwise, do nothing
	// and return false
	virtual bool setPos(int pos) = 0;

	//Return in first parameter the first element  of the
	//right partition. Return true if successful, false
	//if the right partition is empty
	virtual bool getValue(T&) const = 0;

	// Print the contents of the list
	virtual void print() const = 0;
};



#endif 
