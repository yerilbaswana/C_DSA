// Program for polynomial multiplication using linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int coef, expnt;
	struct node *next;
};

// Function declarations
void add_term_at_end(struct node *, int, int);
void multiplication(struct node *, struct node *, struct node *);
void addition(struct node *);
void print_list(struct node *);

int main()
{
	struct node *poly1, *poly2, *result;
	int choice, exponent, coefficient;

	poly1 = (struct node *)malloc(sizeof(struct node));			// Dynamically allocating memory for poly1.
	poly2 = (struct node *)malloc(sizeof(struct node));			// Dynamically allocating memory for poly1.

	printf("Enter the polynomial the term belongs to: ");
	scanf("%d", &choice);

	while(choice != 0)		// Loops till choice != 0. 0 signifies end of input.
	{
		printf("Enter the coefficient and the exponent of the term in decreasing order\n");		
		scanf("%d %d", &coefficient, &exponent);		// Input of polynomial number, coefficient and exponent
		if(choice == 1)
			add_term_at_end(poly1, coefficient, exponent);			// Adding at end since linked list to be arranged in decreasing order.
		else
			add_term_at_end(poly2, coefficient, exponent);

		printf("Enter the polynomial the term belongs to: ");		
		scanf("%d", &choice);		// Input of polynomial number, coefficient and exponent.
	}

	multiplication(poly1, poly2, result);			// Product of poly1 and poly2. Stored in result.

	print_list(result);

	return 0;
}

// Function definitions
void add_term_at_end(struct node *head, int coefficient, int exponent)			// Adding the term at the end
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));

	temp->coef = coefficient;
	temp->expnt = exponent;
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

void multiplication(struct node *poly1, struct node *poly2, struct node *result)		// Product of poly1 and poly2. Stored in result.
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));

	while(poly1 != NULL)
	{
		while(poly2 != NULL)
		{
			temp->coef = poly1->coef * poly2->coef;
			temp->expnt = poly1->expnt + poly2->expnt;
			temp->next = NULL;
			add_term_at_end(result, temp->coef, temp->expnt);
			poly2 = poly2->next;
		}
		poly1 = poly1->next;
	}
	addition(result);
}

void addition(struct node *result)			// To add the terms with same exponent
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp = result;

	while(result != NULL)
	{
		temp = result->next;
		while(temp->next != NULL)
		{
			if(result->expnt == temp->next->expnt)
			{
				result->coef = result->coef + temp->next->coef;
				temp->next = temp->next->next;
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
		result = result->next;
	}
}

void print_list(struct node *result)			// To print the list
{
	printf("\n");
	while(result != NULL)
	{
		printf("%d\t", result->coef);
		printf("%d", result->expnt);
		result = result->next;
	}
}