#include <iostream>
#include<math.h>
using namespace std;

struct Node 
{
	int data;
	Node* pLeft, *pRight;
};

bool insert2BST(Node* &pRoot, int k);
int getHeight(Node* pRoot);
void printLNR(Node* pRoot);
void printLevelK(Node* pRoot, int k);
int findClosest2K(Node* pRoot, int k);
void removeAll(Node* &pRoot);

int main()
{
	return 0;
}


bool insert2BST(Node* &pRoot, int k)
{
	if(pRoot==NULL){
		Node* New= new Node;
		if(New==NULL)
			return false;
		New->data=k;
		New->pLeft=NULL;
		New->pRight=NULL;
		pRoot=New;
		return true;
	}
	if(k<pRoot->data)
		return insert2BST(pRoot->pLeft,k);
	else if(k>pRoot->data)
		return insert2BST(pRoot->pRight,k);
	else
		return false;
}

int getHeight(Node *pRoot)
{
	if(pRoot == NULL)
		return 0;

	int leftVal = 1 + getHeight(pRoot->pLeft);
	int rightVal = 1 + getHeight(pRoot->pRight);

	if(leftVal > rightVal)
		return leftVal;
	else 
		return rightVal;
}

void printLNR(Node* pRoot)
{
	if(pRoot==NULL)
		return;
	printLNR(pRoot->pLeft);
	cout<<pRoot->data<<" ";
	printLNR(pRoot->pRight);
}

void printLevelK(Node* pRoot, int k)
{
	if (k == 0 || pRoot == NULL)
		return;
	if ( k == 1 )
		cout << pRoot->data << " " ;
	printLevelK(pRoot->pLeft,k-1);
	printLevelK(pRoot->pRight,k-1);
}

void findClosest2K(Node* pRoot, int k,int min,int value)
{
	if(pRoot==NULL)
	{
			return ;
	}
	if(pRoot->data==k)
	{
		cout<<pRoot->data;
		return;
	}
	if(pRoot->data<k)
	{
		if(minvalue(pRoot->pRight)-k>pRoot->data-k)
			cout<<pRoot->data;
		else cout<<minvalue(pRoot->pRight);
	}
	else
	{
		if(maxvalue(pRoot->pRight)-k>pRoot->data-k)
			cout<<pRoot->data;
		else cout<<maxvalue(pRoot->pRight);
	}
}

int minvalue(Node * pRoot)
{
	if(pRoot==NULL)
		return 9999999;
	while(pRoot->pLeft!=NULL)
		pRoot=pRoot->pLeft;
	return pRoot->data;
}

int maxvalue(Node * pRoot)
{
	if(pRoot==NULL)
		return 9999999;
	while(pRoot->pRight!=NULL)
		pRoot=pRoot->pRight;
	return pRoot->data;
}

void removeAll(Node* &pRoot)
{
	if (pRoot != NULL)
	{
		removeAll(pRoot->pLeft);
		removeAll(pRoot->pRight);
		delete pRoot;
	}
}

void removeNode(Node* &pRoot, int k)
{
	if (!pRoot)
		return;
	if (pRoot->data == k)
	{
		if (!pRoot->pLeft || !pRoot->pRight)
		{
			Node* tmp = pRoot;
			pRoot = pRoot->pLeft ? pRoot->pLeft : pRoot->pRight;
			delete tmp;
		}
		else
		{
			Node* cur = pRoot->pLeft;

			if (!cur->pRight)
			{
				//(1a) cur is the biggest
				pRoot->pLeft = cur->pLeft;
				pRoot->data = cur->data;
				delete cur;

				// (1b)
				Node* tmp = pRoot;
				cur->pRight = pRoot->pRight;
				pRoot = cur;
				delete tmp;
			}
			else {
				// (2) cur still has the right subtree
				while (cur->pRight && cur->pRight->pRight)
					cur = cur->pRight;
				Node* tmp = cur->pRight;
				cur->pRight = cur->pRight->pLeft;
				pRoot->data = tmp->data;
				delete tmp;
			}
		}
		return;
	}
	if (pRoot->data < k)
		removeNode(pRoot->pRight, k);
	else
		removeNode(pRoot->pLeft, k);
}
