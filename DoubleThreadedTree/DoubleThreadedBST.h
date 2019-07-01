#pragma once
#include "TreeNode.h"
#include "pch.h"
class DoubleThreadedBST {
	TreeNode* pRoot;

	TreeNode* inOrderSuccessor(TreeNode* pNode);

public:
	DoubleThreadedBST();
	void insert(int key);
	void inOrder();
};


