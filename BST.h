#pragma once
#include <queue>
#include "StudentNode.h"


//Binary Search Tree 
//root node sort of acting as center
//everything smaller than root, is stored o left branch somewhere
// everything else to the right

//Helper class to output
class StudentLevelNode {
public:
	StudentNode* student;
	int level;

	//constructor
	StudentLevelNode(StudentNode* student, int level)
	{
		this->student = student;
		this->level = level;
	}
};

//StudentNode class
class BST
{
public:
	StudentNode* root = NULL;
	virtual void insert(StudentNode* newStudent);
	StudentNode* search(int studentID, bool showSearchPath = false);


	//recursive traversal functions
	void inOrderTraversal(StudentNode* current);
	void preOrderTraversal(StudentNode* current);
	void postOrderTraversal(StudentNode* current);

	//show function for output file
	void show(StudentNode* p);
};
