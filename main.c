#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main()
{
    StackNode *root = NULL;

    push(&root, 1);
    push(&root, 2);
    push(&root, 3);

    printf("Size of Stack is %d\n", stackSize(root));

    int i = pop(&root);

    push(&root, 4);
    push(&root, i+5);

    display(root);

    return 0;
}