// Program to reverse a linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
};

// Function declarations
void print_list(struct node *);
void add_node_at_end(struct node *, int);
void reverse_list(struct node *);

int main()
{
    int i = 0, n, input;
    struct node *head, *alpha;

    head = (struct node *)malloc(sizeof(struct node));      // Dynamically allocating memory for head pointer
    alpha = (struct node *)malloc(sizeof(struct node));     // Dynamically allocating memory for alpha pointer

    printf("Enter value of n: ");       // To get input n
    scanf("%d", &n);

    // To add a node to the linked list till i < n
    while(i < n)
    {
        printf("Enter an element: ");       // To get input of node
        scanf("%d", &input);
        add_node_at_end(head, input);        // To add a node at the end of linked list
        i++;
    }

    print_list(head);       // To print the linked list

    printf("\n");

    reverse_list(head);         // To reverse a linked list

    print_list(head);       // To print the linked list
}

void add_node_at_end(struct node *head, int input)           // To add a node to end of linked list
{
    struct node *temp, *result;

    temp = (struct node *)malloc(sizeof(struct node));      // Dynamically allocating memory for temp pointer
    temp->value = input;
    temp->next = NULL;
    result = head;

    while(result != NULL)       // Traversing to the end of linked list
        result = result->next;

    result = temp;
}

void print_list(struct node *head)      // To print the linked list
{
    struct node *temp = head;

    while(temp != NULL)         // Traversing from start to end of linked list
    {
        printf("%d", temp->value);
        temp = temp->next;
    }
}

void reverse_list(struct node *head)        // To reverse the linked list
{
    int i = 0;
    struct node *temp = NULL, *temp2 = NULL;

    while(head != NULL)
    {
        temp = head->next;
        head->next = temp2;
        temp2 = head;
        head = temp;
    }    
    head = temp2;
}
