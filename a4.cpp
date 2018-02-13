#include "bst.h"
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
using  namespace std;

void toLower(string & str);

int main(int argc, char*argv[])
{ 
	//int argc = 3;  char*argv[3] = { "a4.exe", "fouly.txt", "frequentWord" };
	if (argv[1] == NULL)   { cout << "File not found"; return 0; }
	ifstream fin;
	fin.open(argv[1], ios::in);

	bst <string> Bst1;
	string item;
	node <string> *temp;
	
	//Case InSensitive 
	while (fin >> item)
	{
		toLower(item);
		Bst1.bstInsert(item);
	}

	if (Bst1.bstTotCount() == 0) { cout << "File not found"; return 0; }
	if (strcmp(argv[2],"wordCount")==0)
		cout << Bst1.bstTotCount() << " words";
	else if (strcmp(argv[2], "frequentWord") == 0)
		cout << "Most frequent word is " << Bst1.bstFreqWord(Bst1.bstGetRoot());
	else if (strcmp(argv[2], "distWords") == 0)
		cout << Bst1.bstDistCount() << " distinct words";
	else if (strcmp(argv[2],"printInorder")==0)
		Bst1.bstTraverseInOrder(Bst1.bstGetRoot());
	else if (strcmp(argv[2],"printPreorder")==0)
		Bst1.bstTraversePreOrder(Bst1.bstGetRoot());
	else if (strcmp(argv[2],"printPostorder")==0)
		Bst1.bstTraversePostOrder(Bst1.bstGetRoot());
	else if (strcmp(argv[2],"countWord")==0)
	{
		if (argc < 4)
			cout << "Incorrect number of arguments";
		else
		{
			string str(argv[3]);
			toLower(str);
			temp = (Bst1.bstSearch(Bst1.bstGetRoot(), str));
			if (temp == NULL)
				cout << str << " is repeated 0 times";
			else
				cout << str << " is repeated " << temp->freq << " times";
		}
	}
	else cout << "Undefined command";

}

void toLower(string & str)
{

	for (unsigned int i = 0; i<str.size(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] -= 'Z' - 'z';
	}

}