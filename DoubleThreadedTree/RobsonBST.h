#pragma once
#include "TreeNode.h"

class RobsonBST
{
private:
	enum class VisitAlgorithm {preOrder, inOrder, postOrder};
	TreeNode* pRoot;
	TreeNode* pPres;
	TreeNode* pPrev;
	TreeNode* pTop;
	TreeNode* pStack;
	TreeNode* pNext;
	TreeNode* pAvail;
	VisitAlgorithm visitAlg;

	void visit();
	void display(TreeNode* pRoot);

public:
	RobsonBST();

	void insert(int key);
	void display();

	void inOrder();
	void postOrder();
	void preOrder();

};

