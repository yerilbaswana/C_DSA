// Program to make an adjacency list and perform traversal of a graph
#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int vertex;
    struct node *next;
};

// Function declarations
void print_list(struct node *);
struct node *add_term_at_end(struct node *, int);

// Start of main
int main()
{
    struct node **adj_list;
    int no_of_vertices, no_of_edges, vertex1, vertex2;

    printf("Enter the number of vertices in the graph: ");      // Input of number of vertices in graph
    scanf("%d", &no_of_vertices);

    printf("Enter the total number of edges in the graph: ");           // Input of number of edges in graph
    scanf("%d", &no_of_edges);

    // (sizeof(struct node *)) - this represents the size of the pointer to struct node. This is multiplied by number of vertices
    // ** is used to specify that it's pointer of pointers.
    adj_list = (struct node **)malloc(sizeof(struct node *) * no_of_vertices);		

    for(int i = 0; i < no_of_vertices; i++)
    {
    	*(adj_list + i) = NULL;		// Initialising all indices of array of pointers to NULL
    }

    for(int i = 0; i < no_of_vertices; i++)
    {
        *(adj_list + i) = add_term_at_end(*(adj_list + i), i); 			// Setting value of i as vertex
    }

    for(int i = 0; i < no_of_edges; i++)
    {
        printf("Enter the vertice connected by an edge");			// Input of vertice 
        scanf("%d %d", &vertex1, &vertex2);
        *(adj_list + vertex1) = add_term_at_end(*(adj_list + vertex1), vertex2);		// Adding vertex to adjacency list
    }

    for(int i = 0; i < no_of_vertices; i++)			// Printing all adjacency lists
       	print_list(*(adj_list + i));

    return 0;
}

// Function definitions // *(*(adj_list + i) + 2)

struct node *add_term_at_end(struct node *head, int vertex_label)			// Adding the term at the end
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));

	temp->vertex = vertex_label;
	temp->next = NULL;

	if(head == NULL)		// If head is NULL then value of temp is returned
		return temp;
	
	struct node *temp2;	
	temp2 = head;
	while(temp2->next != NULL)		// If not NULL then traverse to end of list and add the element
		temp2 = temp2->next;

	temp2->next = temp;
	return head; 
}

void print_list(struct node *head)      // To print the list
{
	struct node *temp;
	temp = head;

	printf("The list for %d is:", temp->vertex);
	temp = temp->next;
    while(temp != NULL)
    {
        printf("%d", temp->vertex);
        temp = temp->next;
    }
    printf("\n");
}
