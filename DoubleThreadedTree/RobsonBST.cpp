#include "pch.h"
#include "RobsonBST.h"
#include <iostream>
#include <cstdlib>

RobsonBST::RobsonBST()
{
	
}

void RobsonBST::insert(int key)
{
	TreeNode* qNode = new TreeNode();
	qNode->key = key;

	if (pRoot == NULL) {
		pRoot = qNode;
		return;
	}

	TreeNode* currNode = pRoot;
	TreeNode* pNode = NULL; //parent

	while (true) {
		pNode = currNode;
		if (key < currNode->key) {
			currNode = currNode->pLeft;
			if (currNode == NULL) {
				pNode->pLeft = qNode;
				return;
			}
		}
		else {
			currNode = currNode->pRight;
			if (currNode == NULL) {
				pNode->pRight = qNode;
				return;
			}
		}
	}
}

void RobsonBST::visit()
{
	pPrev = pPres = pRoot;
	pTop = pStack = NULL;

	bool firstPart = true;
	while (true) {
		if (firstPart) {
			if ((pPres->pLeft == NULL) && (pPres->pRight == NULL)) {	//pkt 2. - doszedl do liscia
				printf("%d ", pPres->key);
				pAvail = pPres;
				// go to 5
			}
			else {
				if (pPres->pLeft != NULL) {	// pkt 3.
					if (visitAlg == VisitAlgorithm::preOrder) {
						printf("%d ", pPres->key);
					}
					pNext = pPres->pLeft;
					pPres->pLeft = pPrev;
					pPrev = pPres;
					pPres = pNext;
					continue; // goto 2
				}
				if (visitAlg == VisitAlgorithm::preOrder || visitAlg == VisitAlgorithm::inOrder) {
					printf("%d ", pPres->key);
				}
				pNext = pPres->pRight;
				pPres->pRight = pPrev;
				pPrev = pPres;
				pPres = pNext;
				continue; // goto 2
			}
		}

		firstPart = true;
		if (pPres == pRoot) {	// pkt 5.
			return; 
		}

		if (pPrev->pRight == NULL) {	// pkt 6.
			if (visitAlg == VisitAlgorithm::inOrder || visitAlg == VisitAlgorithm::postOrder) {
				printf("%d ", pPrev->key);
			}
			pNext = pPrev->pLeft;
			pPrev->pLeft = pPres; // aktualizacja drzewa
			pPres = pPrev;
			pPrev = pNext;
			firstPart = false;
			continue;
			//go to 5 - pomin pierwsz¹ czêœæ
		}
		if (pPrev->pLeft == NULL) {	// pkt 7. - szliœmy prawym odsy³aczem
			if (visitAlg == VisitAlgorithm::postOrder) {
				printf("%d ", pPrev->key);
			}
			pNext = pPrev->pRight;
			pPrev->pRight = pPres; // aktualizacja drzewa
			pPres = pPrev;
			pPrev = pNext;
			//goto 5 - pomin pierwsz¹ czêœæ
			firstPart = false;
			continue;
		}

		if (pPrev == pTop) { // pkt 8. skad wracamy ze stosu?
			// z prawego pkt 10.
			if (visitAlg == VisitAlgorithm::postOrder) {
				printf("%d ", pPrev->key);
			}
			pNext = pStack;
			pTop = pStack->pRight;
			pStack = pStack->pLeft;
			pNext->pLeft = pNext->pRight = NULL; //null w lisciach
			pNext = pPrev->pLeft;
			pPrev->pLeft = pPrev->pRight;
			pPrev->pRight = pPres;	//odbudowa
			pPres = pPrev;
			pPrev = pNext;
			//goto 5 - pomin pierwsz¹ czêœæ
			firstPart = false;
			continue;
		}

		if (visitAlg == VisitAlgorithm::inOrder) {
			printf("%d ", pPrev->key);
		}
		pAvail->pLeft = pStack; //pisanie na stos
		pAvail->pRight = pTop;
		pStack = pAvail;
		pTop = pPrev;
		pNext = pPrev->pRight;
		pPrev->pRight = pPres;
		pPres = pNext;
		//goto 2
	}
	
}

void RobsonBST::inOrder()
{
	visitAlg = VisitAlgorithm::inOrder;
	printf("Robson InOrder: \n");
	visit();
	printf("\n\n");
}

void RobsonBST::postOrder()
{
	visitAlg = VisitAlgorithm::postOrder;
	printf("Robson PostOrder: \n");
	visit();
	printf("\n\n");
}

void RobsonBST::preOrder()
{
	visitAlg = VisitAlgorithm::preOrder;
	printf("Robson PreOrder: \n");
	visit();
	printf("\n\n");
}

void RobsonBST::display() {
	display(pRoot);
}

void RobsonBST::display(TreeNode* pRoot) {
	if (pRoot != NULL) {
		display(pRoot->pLeft);
		printf(" %d", pRoot->key);
		display(pRoot->pRight);
	}
}
