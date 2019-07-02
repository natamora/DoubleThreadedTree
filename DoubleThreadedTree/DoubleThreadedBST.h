#pragma once
#include "TreeNode.h"
#include "pch.h"
class DoubleThreadedBST {
	TreeNode* pRoot;

	TreeNode* inOrderSuccessor(TreeNode* pNode);
	TreeNode* preOrderSuccessor(TreeNode* pNode);
	TreeNode* postOrderSuccessor(TreeNode* pNode);
	void postOrder(TreeNode* pNode);
public:
	DoubleThreadedBST();
	void insert(int key);

	void inOrder();
	void preOrder();
	void postOrder();
};


