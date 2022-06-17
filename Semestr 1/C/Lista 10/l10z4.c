#include <stdio.h>
#include <stdlib.h>

struct el
{
    int x;
    struct el* next;
};

void AddOnStart(struct el** node, int data)
{
    struct el* newNode = malloc(sizeof(struct el));
    newNode->x = data;
    if(*node == NULL)
    {
        newNode->next = NULL;
        *node = newNode;
        return;
    }
    newNode->next = *node;
    *node = newNode;
}

void PrintElements(struct el *node)
{
    while(node != NULL)
    {
        printf("%d ", node->x);
        node = node->next;
    }
}

int main(void) {

    struct el* node = NULL;

    AddOnStart(&node, 4);
    AddOnStart(&node, 6);
    AddOnStart(&node, 9);
    AddOnStart(&node, 12);

    PrintElements(node);

    return 0;
}
