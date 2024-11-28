#include<bits/stdc++.h>
#include<queue>
#include "biranytreenode.cpp"
#ifndef __Btree__cpp__
#define __Btree__cpp__
using namespace std;
template <class T>
class BTree{
	private:
		BTreeNode<T> *root;
		int n;
	public:
		BTree(){
			root = NULL;
			n = 0;
		}
		BTree(T data){
			root = new BTreeNode<T>(data);
		}
		BTreeNode<T> *getRoot(){
			return root;
		}
		int size(){
			return n;
		}
		bool empty(){
			return n==0;
		}
		bool isInternal(BTreeNode<T> *node){
			return node->hasLeftChild() || node->hasRightChild();
		}
		bool isExternal(BTreeNode<T> *node){
			return !node->hasLeftChild() && !node->hasRightChild();
		}
		bool isRoot(BTreeNode<T> *node){
			return node == root;
		}
		void preOder(BTreeNode<T> *node, void (*visit)(BTreeNode<T> *)){
			if (node == NULL)
				return;
			visit(node);
			preOder(node->getLeftChild(), visit);
			preOder(node->getRightChild(), visit);
		}
		void inOder(BTreeNode<T> *node, void (*visit)(BTreeNode<T> *)){
			if (node == NULL)
				return;
			inOder(node->getLeftChild(), visit);
			visit(node);
			inOder(node->getRightChild(),visit);
		}
		void postOder(BTreeNode<T> *node, void (*visit)(BTreeNode<T> *)){
			if (node == NULL)
				return;
			postOder(node->getLeftChild(),visit);
			postOder(node->getRightChild(),visit);
			visit(node);
		}
		BTreeNode<T> *find(T data) {
		    if (root == NULL)
		    	return NULL;
		    queue<BTreeNode<T> *> qe;
		    qe.push(root);
		    while (!qe.empty()) {
		    	BTreeNode<T> *p = qe.front();
		     	qe.pop();
		     	if (p->getData() == data)
		        	return p;
		      	if (p->hasLeftChild())
		        	qe.push(p->getLeftChild());
		      	if (p->hasRightChild())
		        	qe.push(p->getRightChild());
		    }
		    return NULL;
		}
		BTreeNode<T> *insert(BTreeNode<T> *parent, T data){
			BTreeNode<T> *t = new BTreeNode<T>(data, parent);
			if (parent == NULL){
				if (n != 0)
					return NULL;
				root = t;
			}
			else if (!parent ->hasLeftChild())
				parent->setLeftChild(t);
			else if (!parent ->hasRightChild())
				parent->setRightChild(t);
			else
				return NULL;
			n++;
			return t;
		}
		void remove(BTreeNode<T> *node){
			if (node == NULL)
				return;
			remove(node->getLeftChild());
			remove(node->getRightChild());
			n--;
			delete node;
		}
};
#endif

