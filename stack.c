#include <stdio.h>
#include <stdlib.h>

#include "header.h"


void exitError(char *pszMessage, char *pszDiagnosticInfo) 
{
	fprintf(stderr, "Error: %s %s\n" , pszMessage, pszDiagnosticInfo);
	exit(ERROR_PROCESSING);

}


StackNode* newNode(char cItem) 
{
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->cItem = cItem;
    node->pNext = NULL;
    return node;
}

void push(StackNode** root, char cItem)
{
    StackNode* new = newNode(cItem);
    new->pNext = *root;
    *root = new;
    printf("%c pushed to Stack\n", new->cItem);
}

void display(StackNode* root)
{
    if (isEmpty(root)) 
    {
        printf("Stack is empty.");
        return;
    }
    StackNode *p;
    printf("Stack: \n");
    for(p = root; p != NULL; p = p->pNext)
    {
        printf("%c", p->cItem);
    }
    printf("\n");
}

char pop(StackNode** root)
{
    if (isEmpty(*root)) 
    {
        printf("Stack is empty.");
        return -1;
    }
    StackNode* node = *root;
    *root = node->pNext;
    char popped = node->cItem;
    free(node);
    return popped;
}

int isEmpty(StackNode* root)
{
    if (root == NULL)
        return TRUE;
    else
        return FALSE;
}

int stackSize(StackNode* root)
{
    if (root == NULL)
        return 0;
    return 1 + stackSize(root->pNext);
}