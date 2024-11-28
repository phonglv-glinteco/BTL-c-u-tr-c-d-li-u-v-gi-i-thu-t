#include <bits/stdc++.h>
using namespace std;
#ifndef __biranytreenode__cpp__
#define __biranytreenode__cpp__
template <class T>
class BTreeNode{
	private:
		T data;
		BTreeNode *parent;
		BTreeNode *leftChild;
		BTreeNode *rightChild;
	public:
		BTreeNode(){
			parent = leftChild = rightChild = NULL;
		}
		BTreeNode(T x, BTreeNode *p = NULL, BTreeNode *L = NULL, BTreeNode *R = NULL){
			data = x;
			parent = p;
			leftChild = L;
			rightChild = R;
		}
		T getData(){
			return data;
		}
		BTreeNode *&getParent(){
			return parent;
		}
		BTreeNode *getLeftChild(){
			return leftChild;
		}
		BTreeNode *getRightChild(){
			return rightChild;
		}
		void setData(T x){
			data = x;
		}
		void setParent(BTreeNode *p){
			parent = p;
		}
		void setLeftChild(BTreeNode *L){
			leftChild = L;
		}
		void setRightChild(BTreeNode *R){
			rightChild = R;
		}
		bool hasLeftChild(){ 
			return leftChild != NULL;
		}
   		bool hasRightChild(){ 
   			return rightChild != NULL;
   		}
};
#endif