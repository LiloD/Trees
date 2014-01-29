#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <cstddef>

template<class Elem>
class BinaryTree
{
private:
	Elem element;
	BinaryTree* lc;
	BinaryTree* rc;

	void removeall();
public:
	BinaryTree(const Elem& e, BinaryTree* l = NULL, BinaryTree* r = NULL)
	{
		element = e;
		lc = l;
		rc = r;
	}
	BinaryTree(BinaryTree* l = NULL, BinaryTree* r = NULL)
	{
		lc = l;
		rc = r;
	}
	~BinaryTree()
	{
		removeall();
	}

	void insertLeft(const Elem&);
	void insertRight(const Elem&);

	BinaryTree* getRightChild(){return rc;}
	BinaryTree* getLeftChild(){return lc;}
	Elem getRootVal(){return element;}
	void setRootVal(const Elem& e){element = e;}

};

template<class Elem>
void BinaryTree<Elem>::insertLeft(const Elem& e)
{
	BinaryTree* newnode = new BinaryTree(e);
	if(lc == NULL)
	{
		lc = newnode;
	}else{
		newnode->lc = lc;
		lc = newnode;
	}
}

template<class Elem>
void BinaryTree<Elem>::insertRight(const Elem& e)
{
	BinaryTree* newnode = new BinaryTree(e);
	if(rc == NULL)
	{
		rc = newnode;
	}else{
		newnode->rc = rc;
		rc = newnode;
	}
}

template<class Elem>
void BinaryTree<Elem>::removeall()
{
	delete lc;
	delete rc;
}

#endif /*BINARY_TREE_H*/