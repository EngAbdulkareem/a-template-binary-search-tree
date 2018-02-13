#ifndef BST_H
#define BST_H
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
template <typename T>
struct node
{
	T data;
	node* left;
	node*right;
	int freq;
};

template <typename T>
class bst
{
private:
	int TotCount;
	int DistCount;
	node<T> * root;
public:
	//////////////////////////////////
	//Protorype Declarations:
	bst();
	void bstDestroy();
	void  bstInsert(T dataIn);

	node<T>* bstSearch(node<T> * root, T key);

	void bstTraverseInOrder(node<T> *root);
	void bstTraversePreOrder(node<T> *root);
	void bstTraversePostOrder(node<T> *root);

	bool bstFull();
	int  bstCount();

	node<T>* bstGetRoot();
	char* bstFreqWord(node<T> *root);
	void bstSetRoot(node<T> * pRoot);

	bool bstInsertrec(T dataIn);
	node<T>* _insert(node<T>* root, node<T>*addedNode);

	int bstTotCount();
	int bstDistCount();

};

template <typename T>
bst<T>::bst()
{
	root = NULL;
	DistCount = 0;
	TotCount = 0;
}

///////////////////////////////////////////////////
template <typename T>
void bst<T>::bstInsert(T dataIn)
{
	node <T>* addedNode = new node<T>;

	addedNode->right = NULL;
	addedNode->left = NULL;
	addedNode->data = dataIn;
	addedNode->freq = 1;

	TotCount++;
	if (root == NULL)
		root = addedNode;
	else
	{
		node<T>* temp = root;

		while (temp != NULL)
		{
			if (addedNode->data < temp->data)
				if (temp->left != NULL)
					temp = temp->left;
				else
				{
					temp->left = addedNode;
					break;
				}
			else if (addedNode->data > temp->data)
				if (temp->right != NULL)
					temp = temp->right;
				else
				{
					temp->right = addedNode;
					break;
				}
			else //if(addedNode->data == temp->data )
			{
				temp->freq++;
				return;
			}
		}
	}
	DistCount++;
}

///////////////////////////////////////////////////////
template <typename T>
node<T>* bst<T>::bstSearch(node<T> * root, T key)
{
	if (key < root->data)
		if (root->left == NULL)
			return NULL;
		else
			return bstSearch(root->left, key);

	else if (key> root->data)
		if (root->right == NULL)
			return NULL;
		else
			return 	bstSearch(root->right, key);
	else //( key == root->data )
		return root;
}

///////////////////////////////////////////////////
template <typename T>
void bst<T>::bstTraverseInOrder(node<T> *root)
{
	if (root == NULL)
		return;
	else
	{
		bstTraverseInOrder(root->left);
		cout << root->data << " " << root->freq << " ";
		bstTraverseInOrder(root->right);
	}
}
//////////////////////////////////////////////////
template <typename T>
void bst<T>::bstTraversePreOrder(node<T> *root)
{
	if (root == NULL)
		return;
	else
	{
		cout << root->data << " " << root->freq << " ";
		bstTraversePreOrder(root->left);
		bstTraversePreOrder(root->right);
	}
}
///////////////////////////////////////////////////////
template <typename T>
void bst<T>::bstTraversePostOrder(node<T> *root)
{
	if (root == NULL)
		return;
	else
	{
		bstTraversePostOrder(root->left);
		bstTraversePostOrder(root->right);
		cout << root->data << " " << root->freq << " ";
	}
}

////////////////////////////////
template <typename T>
node<T>* bst<T>::bstGetRoot()
{
	return root;
}

template <typename T>
void bst<T>::bstSetRoot(node<T> * pRoot)
{
	root = pRoot;
}


////////////////////////////////////////////////////
template <typename T>
bool bst<T>::bstFull()
{
	node<T> *newNode = new node<T>;
	if (newNode == NULL)return true;

	{delete newNode; return false; }

}
////////////////////////////////////////////////////
template <typename T>
int bst<T>::bstTotCount()
{
	return TotCount;
}

template <typename T>
int bst<T>::bstDistCount()
{
	return DistCount;
}
int maxFreq=0;
char* freqWord;
string word, word1; bool flag=true;
template <typename T>
char* bst<T>::bstFreqWord(node<T> *root)
{
	if (root == NULL)
		return "0";
	else
	{
		bstFreqWord(root->left);
		if (root->freq > maxFreq && flag)
		{
			maxFreq = root->freq; word1 = root->data; word = root->data;  freqWord = const_cast<char*> (word.c_str());
		}
		else if (root->freq == maxFreq && root->data != word1 && flag)
		{
			word = word+" " + root->data; freqWord = const_cast<char*> (word.c_str());
		}
		flag = false;
		bstFreqWord(root->right);
		if (root->freq > maxFreq)
		{
			maxFreq = root->freq;  word1 = root->data; word = root->data; freqWord = const_cast<char*> (word.c_str());
		}
		else if (root->freq == maxFreq && root->data != word1)
		{
			word = word +" "+ root->data; freqWord = const_cast<char*> (word.c_str());
		}
		
		return freqWord;
	}flag = true;
}

#endif