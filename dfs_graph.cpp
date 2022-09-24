// Program to depth first search (DFS) traversal of a graph.
#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int vertex;
	bool visited;
	struct node *next;
};

// Function declarations
void print_list(struct node *);
struct node *add_term_at_end(struct node *, int);
void dfs_traversal(struct node **, int);

// Start of main
int main()
{
	struct node **adj_list;
	int no_of_vertices, no_of_edges, vertex1, vertex2, chosen_vertex;

	printf("Enter the number of vertices in the graph: ");      // Input of number of vertices in graph
	scanf("%d", &no_of_vertices);

	printf("Enter the total number of edges in the graph: ");           // Input of number of edges in graph
	scanf("%d", &no_of_edges);

	// (sizeof(struct node *)) - this represents the size of the pointer to struct node. This is multiplied by number of vertices
	// ** is used to specify that it's pointer of pointers.
	adj_list = (struct node **)malloc(sizeof(struct node *) * no_of_vertices);		

	for(int i = 0; i < no_of_vertices; i++)
		*(adj_list + i) = NULL;		// Initialising all indices of array of pointers to NULL

	for(int i = 0; i < no_of_vertices; i++)
		*(adj_list + i) = add_term_at_end(*(adj_list + i), i); 			// Setting value of i as vertex

	printf(" ");

	for(int i = 0; i < no_of_edges; i++)
	{
		printf("Enter the vertice connected by an edge");			// Input of vertices
		scanf("%d %d", &vertex1, &vertex2);
		*(adj_list + vertex1) = add_term_at_end(*(adj_list + vertex1), vertex2);		// Adding vertex to adjacency list
	}

	for(int i = 0; i < no_of_vertices; i++)			// Printing all adjacency lists
		print_list(*(adj_list + i));

	// Adjacency list has been created.
	// It will be used for selecting neighbouring vertices for DFS traversal.

	for(int i = 0; i < no_of_vertices; i++)			// Initialising value of visited (bool data type) to false
	{
		struct node *temp;
		temp = *(adj_list + i);
		temp->visited = false;
	}	

	printf("Enter the starting vertex for dfs traversal: ");		// To select the starting vertex for dfs traversal
	scanf("%d", &chosen_vertex);

	dfs_traversal(adj_list, chosen_vertex);		// Recursive implementation of dfs traversal

	return 0;
}

// Function definitions

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

void dfs_traversal(struct node **adj_list_pointer, int chosen_vertex)			// Recursive implementation of dfs traversal.
{
	// pointer to pointer has been passed to this function.
	// It is used to access each vertex depending on the chosen_vertex.
	struct node *temp;
	temp = *(adj_list_pointer + chosen_vertex);		// Storing head pointer of chosen_vertex in temp to acess it's adjacency list.
	temp->visited = true;			// To mark that the vertex has been visited.
	printf("%d", temp->vertex);			// Printing DFS vertices. 
	while(temp != NULL)			// To find neighbouring unmarked vertices.
	{
		if(temp->visited == false)
			dfs_traversal(adj_list_pointer, temp->vertex);
		temp = temp->next;
	}
}