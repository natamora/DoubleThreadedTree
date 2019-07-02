// DoubleThreadedTree.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include "DoubleThreadedBST.h"
#include "RobsonBST.h"

int main()
{
	DoubleThreadedBST tree = DoubleThreadedBST();
	tree.insert(7);
	tree.insert(4);
	tree.insert(8);
	tree.insert(3);
	tree.insert(5);
	tree.insert(2);
	tree.insert(10);
	tree.insert(9);
	tree.insert(6);

	tree.inOrder();
	tree.preOrder();
	tree.postOrder();

	// Robson
	RobsonBST robsonTree = RobsonBST();
	robsonTree.insert(7);
	robsonTree.insert(4);
	robsonTree.insert(8);
	robsonTree.insert(3);
	robsonTree.insert(5);
	robsonTree.insert(2);
	robsonTree.insert(10);
	robsonTree.insert(9);
	robsonTree.insert(6);

	robsonTree.inOrder();
	robsonTree.preOrder();
	robsonTree.postOrder();

	//robsonTree.display();
}

