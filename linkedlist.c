/*********** linkedlist.c *******************
FIX ME

contains all functions pertaining to linked list
in program

*******************************************/

//includes for stdio lib and for
#include <stdio.h>
#include <stdlib.h>
#include "header.h"



/******searchLL******
Purpose:
	searchs linearly through an already created ordered Linked List
	starting with *pHead until finds Node with info that matches iMatch

Parameters:
	Node *pHead      		Pointer to first Node in Linked List
		int  iMatch      	Information to match in Node
	Node **ppPrecedes		pointer to Previous Node to be returned

Notes:
	Will return a pointer to Node that was found or will return NULL
		if nothing matched
	Keeps track of preceding Node through ** to return to Previous
		function
********************/
Node * searchLL(Node *pHead, int iMatch, Node **ppPrecedes) {
	Node *p;							//declare Node pointer
	*ppPrecedes = NULL;		//set the pointer for Precedes to NULL

	//loops through all Nodes by assigned p to p->pNext
	for(p = pHead; p != NULL; p = p->pNext) {
		//check if iInfo matches
		if (p->iInfo == iMatch)
			return p;
		//check if iMatch is less than returns NULL
		if (iMatch < p->iInfo)
			return NULL;

		//sets pointer to preceding Node
		*ppPrecedes = p;
	}

	//No match was found and returns NULL
	return NULL;


}

/* printLL
Purpose:
	prints Linked List

Parameters:
	Node *pHead			pointer to begining of Linked list

*/
void printLL(Node *pHead) {
	Node *p;		//declare Node Pointer

	//printing Headers for Linked List Info
	printf("Pointer \t Info\n");
	for(p = pHead; p != NULL; p = p->pNext) {
		//prints the pointer as well as the attribute iInfo to stdout
		printf("%7p \t %-7d\n",p, p->iInfo);
	}
}



/* insertLL
Purpose:
	insert new Node and Information into Ordered Linked List

Parameters:
	Node **ppHead				Pointer to pointer of Head of array
	int  iNewInfo				New info to be inserted into array

Return:
	Node * to item that was added or found in array

Notes:
	First attempts to find if Node with same info already exists in Linked list
	Second keeps track of previous Nodes with Precedes pointer
	ppHead is of type ** to allow modification of pointer in case
		pNew is at start
*/
Node * insertLL(Node **ppHead, int iNewInfo) {
	Node *pNew;						//declare pointer to New Node
	Node *pFind;					//declare pointer for return value of searchLL
	Node *pPrecedes;			//declare pointer for parameter of searchLL

	//first attempt to see if Node with item already exists
	pFind = searchLL(*ppHead, iNewInfo, &pPrecedes);

	//if pFind is not NULL info already in array return pointer to Node
	if (pFind != NULL)
		return(pFind);

	//if info is not in array allocate a new Node with Information and assign to pNew
	pNew = allocateNode(iNewInfo);

	//if pPrecedes is NULL from searchLL than pNew should be at beginning of array
	if (pPrecedes == NULL) {
		pNew->pNext = *ppHead;						//assign pNext of new Node to what ppHead is pointing at
		*ppHead = pNew;										//set ppHead to point at new Node
	} else {
		pNew->pNext = pPrecedes->pNext;		//set pNext of new Node to what pPrecedes is point at
		pPrecedes->pNext = pNew;					//set pNext of pPrecedes to new Node
	}

	return pNew;		//return pointer to new Node
}




/* allocateNode
Purpose:
	Allocate memory for new Node to be inserted into ordered Linked list

Parameters
	int iNewInfo			Information to be stored in Node

Return
	Node *						Pointer to Node item to be inserted

Notes
	If malloc does not work will retunr error message and exit with
		exitError function
*/
Node * allocateNode(int iNewInfo) {
	Node *pNew;															//declare pointer to Node
	//must cast malloc to type (Node *)
	pNew = (Node *)malloc(sizeof(Node));		//allocate memory for type Node and set pointer of pNew

	//if malloc does not work exit with error message
	if (pNew == NULL)
		exitError("Memory allocation Error", "");

	pNew->iInfo = iNewInfo;									//set iInfo of Node to iNewInfo
	pNew->pNext = NULL;											//set pNext of Node to NULL/will get set in insertLL
	return pNew;														//return pointer to Node
}


void removeLL(Node **pHead, int iMatch) {
	Node *pPrecedes;
	Node *pFind;

	pFind = searchLL(*pHead, iMatch, &pPrecedes);

	if (pFind != NULL) {
		if (pPrecedes == NULL) {
			*pHead = pFind->pNext;
		}
		else {
			pPrecedes->pNext = pFind->pNext;
		}

		freeNode(pFind);
	}
}

void freeNode(Node *p) {
	free(p);
}


int countNodes(Node *pHead) {
	Node *p;
	int iNodeCount = 0;
	for(p = pHead; p != NULL; p = p->pNext) {

		iNodeCount++;
	}

	return iNodeCount;
}

int sumLL(Node *pHead) {
	Node *p;
	int sum = 0;

	for (p = pHead; p != NULL; p = p->pNext) {
		sum += p->iInfo;
	}

	return sum;

}


void exitError(char *pszMessage, char *pszDiagnosticInfo) {
	fprintf(stderr, "Error: %s %s\n" , pszMessage, pszDiagnosticInfo);
	exit(ERROR_PROCESSING);

}
