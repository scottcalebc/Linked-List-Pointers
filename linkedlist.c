/*********** linkedlist.c *******************
FIX ME

contains all functions pertaining to linked list
in program

*******************************************/

//includes for stdio lib and for
#include <stdio.h>
#include <stdlib.h>
#include "header.h"



NodeT * searchT(NodeT *pRoot, int iMatch) {
	if (pRoot == NULL)
		return NULL;
	if (iMatch == pRoot->iInfo)
		return pRoot;
	if (iMatch < pRoot->iInfo)
		return searchT(pRoot->pLeft, iMatch);
	else
		return searchT(pRoot->pRight, iMatch);
}

void printT(NodeT *p, int iIndent) {
	int i;
	if ( p == NULL)
		return;
	printT(p->pRight, iIndent+1);
	for(i = 0; i < iIndent*3; i++)
		printf(" ");
	printf("%d\n", p->iInfo);
	printT(p->pLeft, iIndent+1);
}

NodeT * insertT(NodeT *p, int iNewInfo) {
	if (p == NULL)
		return allocateNodeT(iNewInfo);
	if (iNewInfo == p->iInfo)
		return p;
	else if (iNewInfo < p->iInfo)
		p->pLeft = insertT(p->pLeft, iNewInfo);
	else
		p->pRight = insertT(p->pRight, iNewInfo);
	return p;
}

NodeT * allocateNodeT(int iNewInfo) {
	NodeT *pNew;															//declare pointer to Node
	//must cast malloc to type (Node *)
	pNew = (NodeT *)malloc(sizeof(NodeT));		//allocate memory for type Node and set pointer of pNew

	//if malloc does not work exit with error message
	if (pNew == NULL)
		exitError("Memory allocation Error", "");

	pNew->iInfo = iNewInfo;									//set iInfo of Node to iNewInfo
	pNew->pLeft = NULL;											//set pNext of Node to NULL/will get set in insertLL
	pNew->pRight = NULL;
	return pNew;														//return pointer to Node
}




int countT(NodeT *p) {
	if (p == NULL)
		return 0;
	return 1 + countT(p->pLeft) + countT(p->pRight);

}

int sumT(NodeT *p) {
	if (p == NULL)
		return 0;
	return p->iInfo + sumT(p->pLeft) + sumT(p->pRight);

}


void exitError(char *pszMessage, char *pszDiagnosticInfo) {
	fprintf(stderr, "Error: %s %s\n" , pszMessage, pszDiagnosticInfo);
	exit(ERROR_PROCESSING);

}
