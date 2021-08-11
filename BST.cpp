#include "BST.h"
#include <fstream>
using namespace std;

void BST::insert(StudentNode* newStudent)
{
	//IF the root is NULL(tree is empty), then make this student the root
	if (root == NULL)
	{
		root = newStudent;
		return; // exit function early, we are done here

	}
	//some pointers to help us navigate the tree to find where to put the new student
	StudentNode* current = root; //current node we're pointing at
	StudentNode* parent = NULL; //parent of current node (node visitored last time)


	while (true)//infinite loop
	{
		//lets keep track of where we were before moving down further
		parent = current;
		// LEFT or RIGHT
		//if new students studentID is less than the student at ccurrent node
		//, then go down LEFT

		if (newStudent->studentID < current->studentID)
		{
			// < means we go down deeper into tree on left side
			current = current->leftChild;
			//if current is NULL, we just found an empty space to insert
			// our newStudent
			if (current == NULL)
			{
				//done, stick student here
				parent->leftChild = newStudent;
				return; //done
			}
		}
		else
		{
			//go down right path
			current = current->rightChild;
			//if current is NULL, insert there
			if (current == NULL)
			{
				parent->rightChild = newStudent;
				return;
			}

		}
	}
}

StudentNode* BST::search(int studentID, bool showSearchPath)
{
	//if tree empty, can't find student amtching studentID then
	if (root == NULL)
	{
		return NULL;
	}
	StudentNode* current = root;

	//keep looping until I find a match
	while (current->studentID != studentID)
	{


		if (showSearchPath)
		{
			cout << current->studentID << " " << endl;
		}

		//haven't found it yet, lets explore left or right down in the tree 
		if (studentID < current->studentID)
		{
			//go left
			current = current->leftChild;
		}
		else
		{
			//go right
			current = current->rightChild;
		}
		//if current is NULL, search studentID cannot be found
		if (current == NULL)
		{
			return NULL;
		}
	}
	return current; //should be pointing to match tree
}


//outputs stuff in the tree in ascending order
void BST::inOrderTraversal(StudentNode* current)
{
	//current == NUL is end of this branch path, this if
	//stops from infinite looping
	if (current != NULL)
	{
		inOrderTraversal(current->leftChild);
		cout << current->studentID << " " << endl;
		inOrderTraversal(current->rightChild);
	}
}

void BST::preOrderTraversal(StudentNode* current)
{
	if (current != NULL)
	{
		cout << current->studentID << " " << endl;
		preOrderTraversal(current->leftChild);
		preOrderTraversal(current->rightChild);
	}
}

void BST::postOrderTraversal(StudentNode* current)
{
	if (current != NULL)
	{
		postOrderTraversal(current->leftChild);
		postOrderTraversal(current->rightChild);
		cout << current->studentID << " " << endl;
	}
}


//outputs bfs tree to text file
void BST::show(StudentNode* p)
{
	ofstream  writeFile;
	writeFile.open("OutputFile.txt");
	// Base Case 
	if (root == NULL)  return;

	// Create an empty queue for level order traversal 
	queue<StudentLevelNode> q;

	// Enqueue Root and initialize height 
	q.push(StudentLevelNode(root, 0));

	int previousOutputLevel = -1;

	while (q.empty() == false)
	{
		// Print front of queue and remove it from queue 
		StudentLevelNode node = q.front();
		if (node.level != previousOutputLevel)
		{
			writeFile << endl;
			writeFile << node.level << " : ";
			previousOutputLevel = node.level;
		}
		writeFile << node.student->studentID << ", ";
		q.pop();

		/* Enqueue left child */
		if (node.student->leftChild != NULL)
			q.push(StudentLevelNode(node.student->leftChild, node.level + 1));

		/*Enqueue right child */
		if (node.student->rightChild != NULL)
			q.push(StudentLevelNode(node.student->rightChild, node.level + 1));
		
		
	}
	writeFile.close();
}
