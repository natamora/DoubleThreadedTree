
#include "pch.h"
#include "DoubleThreadedBST.h"

#include <cstdlib>
#include <iostream>
DoubleThreadedBST::DoubleThreadedBST()
{
	//tworzymy element powy¿ej korzenia drzewa(head)
	this->pRoot = new TreeNode();
	this->pRoot->lTag = 0;
	this->pRoot->rTag = 0;
	this->pRoot->pLeft = pRoot->pRight = pRoot;
}

void DoubleThreadedBST::insert(int key)
{
	TreeNode* qNode = new TreeNode();
	qNode->key = key;

	//sprawdzamy czy to pierwszy element
	if (pRoot->pRight == pRoot && pRoot->pLeft == pRoot) {

		//podczepiamy pod left nowego node jego poprzednik (czyli pRoot pusty)
		qNode->pLeft = pRoot;
		qNode->lTag = 0;	//skoro left wskazuje na poprzednika -> ltag = 0

		//podpinamy pod right nowego node jego nastepnik (którego nie ma, czyli pod pRoot)
		qNode->pRight = pRoot;
		qNode->rTag = 0;

		//podpinamy nowy element pod drzewo (lewa strona)
		pRoot->pLeft = qNode;
		pRoot->lTag = 1; //czyli zawiera poddrzewo

	}
	else {
		//w innym wypadku szukamy kolejnych wêz³ów
		TreeNode* pNode = pRoot->pLeft;
		while (true) {	//dopóki nie przerwiemy przechodŸ przez kolejne wêz³y w poszukiwaniu miejsca
		
			if (qNode->key > pNode->key) { //przechodzimy na prawo
				if (pNode->rTag == 1) {	// jesli jest poddrzewo to idziemy dalej
					pNode = pNode->pRight;		//na prawo
				}
				else {
					break;		// jeœli nie ma poddrzewa ju¿ to wychodzimy z petli i przechodzimy do podpinania
				}
			}
			else {	// przechodzimy na lewo
				if (pNode->lTag == 1) {
					pNode = pNode->pLeft;
				}
				else {
					break;
				}
			
			}
		}

		//faza pod³¹czania nowego wêz³a
		if (qNode->key > pNode->key) {	//jesli nowy wiêkszy od wêz³a to pod³¹cz na prawo
			//parametry nowego dziecka
			qNode->pLeft = pNode; //ustawiam poprzednika (rodzica)
			qNode->lTag = 0;
			qNode->pRight = pNode->pRight; // podpinam nastepnik (czyli nastepnik rodzica - bo wstawiamy wartosc pomiedzy)
			qNode->rTag = 0;

			//parametry rodzica
			pNode->pRight = qNode;	// podpinam nowy wezel na prawo
			pNode->rTag = 1;


		}
		else {
			//parametry nowego dziecka
			qNode->pLeft = pNode->pLeft;	// poprzednikiem bedzie poprzednik rodzica ( bo wart pomiedzy)
			qNode->lTag = 0;
			qNode->pRight = pNode;	// nastepnikiem bedzie rodzic
			qNode->rTag = 0;

			//parametry rodzica
			pNode->pLeft = qNode;
			pNode->lTag = 1;
		}

	}
}

TreeNode* DoubleThreadedBST::inOrderSuccessor(TreeNode * pNode)
{
	TreeNode* qNode = pNode->pRight;
	//jeœli prawe poddrzewo jest puste to idziemy w górê i dostajemy nastepnik
	if (pNode->rTag == 0) {
		return qNode;
	}
	// w innym przypadku zidziemy po odsylaczach by zwróciæ dziecko najbardzije na lewo
	if (pNode->rTag == 1) {
		while (qNode->lTag == 1) {	//dopóki lewe poddrzewo nie jest puste przechodŸ w dó³
			qNode = qNode->pLeft;
		}
	}
	return qNode;
}

TreeNode * DoubleThreadedBST::preOrderSuccessor(TreeNode* pNode)
{
	// jeœli wêze³ ma lewe poddrzewo to nastepnikiem jest jego lewe dziecko
	if (pNode->lTag == 1) {
	
		return pNode->pLeft;
	}
	//dopóki wêze³ nie bêdzie mia³ prawego poddrzewa lub nie bêdzie pRootem
	// - przechodŸ za nastepnikami inorder
	while (pNode->rTag == 0 && pNode != pRoot) {
		pNode = pNode->pRight;
	}
	return pNode->pRight;
}

TreeNode * DoubleThreadedBST::postOrderSuccessor(TreeNode* pNode)
{
	if (pNode->rTag == 1)
	{
		return pNode->pRight;
	}

	pNode = pNode->pRight;
	if (pNode->lTag == 1)
	{
		pNode = pNode->pLeft;
	}

	return pNode;
}

void DoubleThreadedBST::postOrder(TreeNode * pNode)
{
	if (pNode == pRoot) {
		return;
	}
	if (pNode->lTag == 1) {
		postOrder(pNode->pLeft);
	}
	if (pNode->rTag == 1) {
		postOrder(pNode->pRight);
	}
	printf("%d ", pNode->key);
}

void DoubleThreadedBST::inOrder() {

	printf("Double Threaded Tree InOrder:\n");
	//zaczynamy od lewego dziecka pustego wêz³a
	TreeNode* pNode = pRoot->pLeft;

	//szukamy elementu najbardziej na lewo
	while (pNode->lTag == 1) {
		pNode = pNode->pLeft;
	}

	//lecimy po nastepnikach
	while (pNode != pRoot) {
		printf("%d ", pNode->key);
		pNode = inOrderSuccessor(pNode);
	}
	printf("\n\n");
}

void DoubleThreadedBST::preOrder()
{
	printf("Double Threaded Tree PreOrder:\n");
	//zaczynamy od korzenia i lecimy po nastepnikach preOrder
	TreeNode* pNode = pRoot->pLeft;
	while (pNode != pRoot) {	
		printf("%d ", pNode->key);
		pNode = preOrderSuccessor(pNode);
	}

	printf("\n\n");
}

void DoubleThreadedBST::postOrder()
{
	printf("Double Threaded Tree PreOrder:\n");

	TreeNode* node = pRoot->pLeft;
	postOrder(node->pLeft);
	postOrder(node->pRight);
	printf("%d ", node->key);
	
	printf("\n\n");
}
