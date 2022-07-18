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
	int no_of_vertices, label, choice, input;

	printf("Enter the number of vertices in the graph: ");		// Input of number of vertices in graph
	scanf("%d", &no_of_vertices);

	head = (struct node *)malloc(sizeof(struct node) * no_of_vertices);		// Dynamic memory allocation of head array of type struct node

	for(int i = 0; i < no_of_vertices; i++)		// To store head and label of each vertice in the graph
	{
		printf("Enter the label of vertice %d: ", i+1);		// Input of label of graph
		scanf("%d", &label);
		add_node_at_end(&head[i], label);		// To store label of graph
	}

	for(int i = 0; i < no_of_vertices; i++)			// To print the array containing head pointers
		print_list(&head[i]);

	for(int i = 0; i < no_of_vertices; i++)			// To add nodes to head pointers
	{
		printf("For vertice %d.\tEnter 1 to enter a node. 0 to stop.");		// Used as counter in while condition. Acc. to this value, a node will be added or not to a vertice
		scanf("%d", &choice);
		
		while(choice)
		{
			printf("Enter node for vertice %d: ", i);		// To get input of node to be added
			scanf("%d", &input);
			add_node_at_end(&head[i], input);		// Adds node to the vertice
			printf("Enter 1 to enter a node. 0 to stop.");		// Input of choice(counter to while condition)
			scanf("%d", &choice);	
		}
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