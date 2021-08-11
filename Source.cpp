#include <iostream>
#include <string>
#include <chrono> //time stuff
#include <fstream> //file reading/writing stuff
#include <windows.h> //used this for sleep, you wont need it likely
#include <vector>//for storage
#include "AVL.h"
#include "Source.h"
#include "BST.h"

using namespace std;

int main()
{
	//Creating a tree avl1
	AVL avl1;
	//reading input file
	ifstream readFile;
	readFile.open("myfile.txt");
	//ints to store values from input file
	int numberOfNumbers;
	int numbers;
	readFile >> numberOfNumbers;
	//vector to add the numbers to AVL tree one by one
	vector<int>A;
	for (int i = 1; i <= numberOfNumbers; i++)
	{
		readFile >> numbers;
		A.push_back(numbers);
		avl1.insert(new StudentNode(numbers));
	}

	//output file
	//BFS
	avl1.show(avl1.root);
}
	