#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// ctrl c v geeksforgeeks

/* Link list node */
struct Node {
    int data;
    struct Node* next;
};

/* Function to push a node */
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
/* TODO make delete last */

/* TODO make delete from index */

/* Function to print linked list */
void printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

/* Function to reverse the linked list */
static void reverse(struct Node** head_ref)
{
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

/* Driver code*/
int main()
{
    /* Start with the empty list */
    struct Node* linked_list = NULL;
 
    push(&linked_list, 20);
    push(&linked_list, 4);
    push(&linked_list, 15);
    push(&linked_list, 85);
 
    printf("Given linked list\n");
    printList(linked_list);
    reverse(&linked_list);
    printf("\nReversed Linked list \n");
    printList(linked_list);
    getchar();
}