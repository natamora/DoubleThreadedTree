// DoubleThreadedTree.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include "DoubleThreadedBST.h"

int main()
{
	DoubleThreadedBST tree = DoubleThreadedBST();
	tree.insert(5);
	tree.inOrder();
	tree.insert(7);
	tree.inOrder();
	tree.insert(2);
	tree.inOrder();
	tree.insert(1);
	tree.inOrder();
	tree.insert(8);
	tree.inOrder();
	tree.insert(3);
	tree.inOrder();
	tree.insert(6);
	tree.inOrder();
}

