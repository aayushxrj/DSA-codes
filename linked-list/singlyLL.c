#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    // link first and second
    head->data = 7;
    head->next = second;

    // link second and third
    second->data = 10;
    second->next = third;

    // link third and fourth
    third->data = 13;
    third->next = fourth;

    // terminating the list
    fourth->data = 15;
    fourth->next = NULL;

    linkedListTraversal(head);

    return 0;
}