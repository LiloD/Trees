#include <iostream>
#include "BinaryTree.h"
#include <string>
using namespace std;


class PrintStringNode
{
public:
	static void handle(string node)
	{
		cout<<"My Name is "<<node<<endl;
	}
};

class PrintIntNode
{
public:
	static void handle(int node)
	{
		cout<<"The Number is "<<node<<endl;
	}
};

template<class ElemHandle,class Elem>
void preorder_traversal(BinaryTree<Elem>* r, ElemHandle* handler)
{
	if(r == NULL)
	{
		return;
	}
	handler->handle(r->getRootVal());
	preorder_traversal(r->getLeftChild(),handler);
	preorder_traversal(r->getRightChild(),handler);
}


int main()
{

	BinaryTree<string> bt( string("Zhizhuo Ding") );
	bt.insertRight( string("Luise") );
	bt.insertLeft( string("Merry") );
	(bt.getLeftChild())->insertRight( string("DX") );

	PrintStringNode Stringhandler;
	preorder_traversal(&bt, &Stringhandler);

	BinaryTree<int> bt2( 1 );
	bt2.insertRight( 112 );
	bt2.insertLeft( 23 );
	(bt2.getLeftChild())->insertRight( 3 );

	PrintIntNode inthandler;
	preorder_traversal(&bt2, &inthandler);
	
	// BinaryTree<int> bt(1);
	// cout<<bt.getRootVal()<<endl;
	// bt.insertRight(10);
	// bt.insertLeft(100);

	// BinaryTree<int> *t = bt.getLeftChild();
	// cout<<t->getRootVal()<<endl;
	// t = bt.getRightChild();
	// cout<<t->getRootVal()<<endl;


	// BinaryTree<string> bt(string("Ding"));
	// cout<<bt.getRootVal()<<endl;
	// bt.insertRight(string("Zhi"));
	// bt.insertLeft(string("Zhuo"));

	// BinaryTree<string> *t = bt.getLeftChild();
	// cout<<t->getRootVal()<<endl;
	// t = bt.getRightChild();
	// cout<<t->getRootVal()<<endl;
	return 0;
}