#include <stdio.h>
#include "header.h"



int main() {
	NodeT *pRoot = insertT(pRoot, 30);
	pRoot = insertT(pRoot, 20);
	pRoot = insertT(pRoot, 40);
	pRoot = insertT(pRoot, 50);
	pRoot = insertT(pRoot, 45);
	pRoot = insertT(pRoot, 10);
	
	printT(pRoot, 0);

	return 0;
}
