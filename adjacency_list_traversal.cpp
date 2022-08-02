// Program to make an adjacency list and perform traversal of a graph
#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int vertex;
    struct node *next;
};

// Function declarations
void add_node_at_front(struct node *, int);
void print_list(struct node *);

int main()
{
    struct node **adj_list;
    int no_of_vertices, no_of_edges, vertice1, vertice2;

    printf("Enter the number of vertices in the graph: ");      // Input of number of vertices in graph
    scanf("%d", &no_of_vertices);

    printf("Enter the total number of edges in the graph: ");           // Input of number of edges in graph
    scanf("%d", &no_of_edges);

    // (sizeof(struct node *)) - this represents the size of the pointer to struct node. This is multiplied by number of vertices
    // ** is used to specify that it's pointer of pointers.
    adj_list = (struct node **)malloc(sizeof(struct node *) * no_of_vertices);		

    for(int i = 0; i < no_of_vertices; i++)
    {
    	*(adj_list + i) = NULL;
    	*(adj_list + i)->next = NULL;
    }

    for(int i = 0; i < no_of_vertices; i++)
    {
        *adj_list[i] = add_node_at_front((*adj_list)[i], i);
    }

    for(int i = 0; i < no_of_edges; i++)
    {
        printf("Enter the edges connected by an edge");
        scanf("%d %d", &vertice1, &vertice2);
        add_node_at_front((*adj_list)[vertice1], vertice2);
    }

    for(int i = 0; i < no_of_vertices; i++)
        print_list((*adj_list)[i]);

    return 0;
}

// Function definitions

struct node *add_node_at_front(struct node *head, int value)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    temp->vertex = value;
    temp->next = NULL;

    if(head != NULL)
        temp->next = head;

    head = temp;

}

void print_list(struct node *head)      // To print the list
{
    while(head != NULL)
    {
        printf("%d", head->vertex);
        head = head->next;
    }
}

