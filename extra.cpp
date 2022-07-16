// Program to reverse a linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
};

void print_list(struct node *);
void add_element_at_end(struct node *, int);
void reverse_list(struct node *);

int main()
{
    int i = 0, n, input;
    struct node *head, *alpha;

    head = (struct node *)malloc(sizeof(struct node));
    alpha = (struct node *)malloc(sizeof(struct node));

    printf("Enter value of n: ");
    scanf("%d", &n);

    while(i < n)
    {
        printf("Enter an element: ");
        scanf("%d", &input);
        add_element_at_end(head, input);
        i++;
    }

    print_list(head);

    printf("\n");

    reverse_list(head);

    print_list(head);
}

void add_element_at_end(struct node *head, int input)
{
    struct node *temp, *result;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->value = input;
    temp->next = NULL;
    result = head;

    while(result != NULL)
        result = result->next;

    result = temp;
}

void print_list(struct node *head)
{
    struct node *temp = head;

    while(temp != NULL)
    {
        printf("%d", temp->value);
        temp = temp->next;
    }
}

void reverse_list(struct node *head)
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