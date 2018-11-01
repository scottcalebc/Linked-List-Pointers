#include <stdio.h>
#include "header.h"



int main() {
	Node *pHead = NULL;	//set pHead to NULL initially

	int i;
	for(i = 0; i < 10; i++) {
		insertLL(&pHead, i);		//adds 10 new objects to Linked List and orders them
	}
	//prints contents of Linked List
	printLL(pHead);
	
	printf("Number of Nodes: %d\n", countNodes(pHead));
	printf("Sum of Nodes: %d\n", sumLL(pHead));


	return 0;
}
