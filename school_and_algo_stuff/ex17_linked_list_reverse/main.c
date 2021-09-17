#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};
typedef struct node node_t;

void print_llist(node_t *head)
{
    node_t *temp = head;
    while (temp != NULL)
    {
        printf("%d - ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

node_t *create_new_node(int value)
{
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

// what is happening here with ** pointer to a pointer???
node_t *insert_at_head(node_t **head, node_t *node_to_insert)
{
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

// goes trough the list and returns pointer to the node
// that has the searched value
node_t *find_node(node_t *head, int val)
{
    node_t *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value == val)
            return tmp;
    }
    return NULL;
}

int main(void)
{
    node_t *head = NULL;
    node_t *tmp;

    for (size_t i = 0; i < 25; i++)
    {
        tmp = create_new_node(i);
        head = insert_at_head(&head, tmp);
    }

    print_llist(head);

    return 0;
}