#include<bits/stdc++.h>
#include<queue> 
#include "Btree.cpp"
using namespace std;
int d=0;
void count(BTreeNode<int> *t){
	if (t!=NULL)
		d++;
}
int main(){
	BTree<int> tree;
	int n;
	cout<<"Nhap so nut:";
	cin>>n;
	int a[n];
	cout<<"Nhap lan luot so nut:"<<endl;
	for (int i=1; i<=n; i++){
		do{
			cout<<"a["<<i<<"]=";
			cin>>a[i];
		}while(a[i]>n && a[i]<1);
	}

	queue< BTreeNode<int> *> qe;
	BTreeNode<int> *p = tree.insert(NULL, a[1]);
	qe.push(p);
	int i=2;
	while(i<=n){
		BTreeNode<int> *p = qe.front();
		qe.pop();
		BTreeNode<int> *p1 = tree.insert(p,a[i++]);
		qe.push(p1);
		if (i<=n){
			p1 = tree.insert(p, a[i++]);
			qe.push(p1);
		}
	}

	int x;
	do{
		cout<<"\nNhap vap gia tri x dau tien to mau:";
		cin>>x;
	}while(x>n && x<1);
	p = tree.find(x);
	tree.preOder(p,count);
	if (d > n/2)
		cout<<"false";
	else
		cout<<"true";
}
