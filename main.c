#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main()
{
    StackNode *root = NULL;
    char str[20];

    printf("Enter a string to reverse: ");
    scanf("%s", str);

    printf("%s\n", str);

    char* c = &str[0];

    while(*c) 
    {
        push(&root, *c);
        *c++;
    }

    
    int i;
    int max = stackSize(root);
    char *pszRev = (char*)malloc(max+1);
    char *pCnt = pszRev;
    
    for(i = 0; i < max; i++) {
        *pCnt = pop(&root);
        *pCnt++;
    }
    *pCnt = '\0';

    printf("%s\n", pszRev);
    

    return 0;
}