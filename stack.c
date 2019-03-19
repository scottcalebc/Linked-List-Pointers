#include <stdio.h>
#include <stdlib.h>

#include "header.h"


void exitError(char *pszMessage, char *pszDiagnosticInfo) 
{
	fprintf(stderr, "Error: %s %s\n" , pszMessage, pszDiagnosticInfo);
	exit(ERROR_PROCESSING);

}


StackNode* newNode(int iInfo) 
{
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->iInfo = iInfo;
    node->pNext = NULL;
    return node;
}

void push(StackNode** root, int iInfo)
{
    StackNode* new = newNode(iInfo);
    new->pNext = *root;
    *root = new;
    printf("%d pushed to Stack\n", new->iInfo);
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
        printf("%5d\n", p->iInfo);
    }
}

int pop(StackNode** root)
{
    if (isEmpty(*root)) 
    {
        printf("Stack is empty.");
        return -1;
    }
    StackNode* node = *root;
    *root = node->pNext;
    int popped = node->iInfo;
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