// Program to make an adjacency list and perform traversal of a graph
#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int vertices;
	struct node *next;
};

// Function declarations
void add_node_at_end(struct node *, int);
void print_list(struct node *);

int main()
{
	struct node *head;
	int no_of_vertices, no_of_edges, label, choice, vertice1, vertice2;

	printf("Enter the number of vertices in the graph: ");		// Input of number of vertices in graph
	scanf("%d", &no_of_vertices);

	printf("Enter the total number of edges in the graph: ");			// Input of number of edges in graph
	scanf("%d", &no_of_edges);

	head = (struct node *)malloc(sizeof(struct node) * no_of_vertices);		// Dynamic memory allocation of head array of type struct node

	for(int i = 0; i < no_of_vertices; i++)		// To store head and label of each vertice in the graph
	{
		printf("Enter the label of vertice %d: ", i+1);		// Input of label of graph
		scanf("%d", &label);
		add_node_at_end(&head[i], label);		// To store label of graph
	}

	for(int i = 0; i < no_of_vertices; i++)			// To print the array containing head pointers
		print_list(&head[i]);

	for(int i = 0; i < no_of_edges; i++)			// To add nodes to head pointers
	{
		printf("Enter vertices which are connected by an edge: ");
		scanf("%d %d", &vertice1, &vertice2);
		add_node_at_end(head[vertice1], vertice2);
		add_node_at_end(head[vertice2] , vertice1);
	}

	for(int i = 0; i < no_of_vertices; i++)			// To print the array containing head pointers
	{
		print_list(&head[i]);
		printf("\n");
	}

	return 0;
}

// Function definitions

void add_node_at_end(struct node *head, int input)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));

	temp->vertices = input;
	temp->next = NULL;

	if(head == NULL)
		head = temp;

	else
	{
		while(head->next != NULL)
			head = head->next;
		head->next = temp;
	}
}

void print_list(struct node *head)		// To print the list
{
	while(head != NULL)
	{
		printf("%d", head->vertices);
		head = head->next;
	}
}
