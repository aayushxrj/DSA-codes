// reversing a linked list
// finding cycle
// find size

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node
{
    int data;
    struct Node *next;
};


void traversal(struct Node *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}


struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->next = head;
    temp->data = data;
    return temp;
}


bool hasCycle(struct Node *head){
    struct Node *slow = head;
    struct Node *fast = head;
    while(slow!=NULL && fast!=NULL && fast->next !=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}


struct Node *revLL(struct Node *head){
    struct Node *p = head;
    struct Node *q = NULL;
    struct Node *r = NULL;

    while(p!=NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
    return head;
}


struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    // ptr->next = head;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node *deleteAtLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node *deleteAtValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != value && q->next != NULL) 
    {
        p = p->next;
        q = q->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = arr[0];
    struct Node *temp = head;
    for (int i = 1; i < 5; i++)
    {
        struct Node *next = (struct Node *)malloc(sizeof(struct Node));
        next->data = arr[i];
        temp->next = next;
        temp = next;
    }
    temp->next = NULL;
    traversal(head);
    printf("\n");
    if(hasCycle(head)){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }

    head = revLL(head);
    traversal(head);

    return 0;
}


// Function to reverse a linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}


// Function to check if a singly linked list is a palindrome
bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return true;

    // Find the middle of the linked list using slow and fast pointers
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    ListNode* secondHalf = reverseList(slow->next);

    // Compare the first half with the reversed second half
    ListNode* firstHalf = head;
    while (secondHalf != nullptr) {
        if (firstHalf->val != secondHalf->val)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

// Function to merge a linked list into another linked list at alternate positions
void mergeLists(struct ListNode** list1, struct ListNode** list2) {
    struct ListNode* curr1 = *list1;
    struct ListNode* curr2 = *list2;
    struct ListNode* next1;
    struct ListNode* next2;

    while (curr1 != NULL && curr2 != NULL) {
        next1 = curr1->next;
        next2 = curr2->next;

        curr1->next = curr2;
        curr2->next = next1;

        curr1 = next1;
        curr2 = next2;
    }

    *list2 = curr2;
}
mergeLists(&list1, &list2);