// Program for polynomial multiplication using linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int coef, expnt;
	struct node *next;
};

// Function declarations
struct node *add_term_at_end(struct node *, int, int);
struct node *multiplication(struct node *, struct node *, struct node *);
struct node *addition(struct node *);
void print_list(struct node *);

int main()
{
	struct node *poly1, *poly2, *result;
	int choice, exponent, coefficient;

	poly1 = NULL;
	poly2 = NULL;
	result = NULL;
	
	printf("Enter the polynomial the term belongs to: ");
	scanf("%d", &choice);

	while(choice)		// Loops till choice != 0. 0 signifies end of input.
	{
		printf("Enter the coefficient and the exponent of the term in decreasing order\n");		
		scanf("%d %d", &coefficient, &exponent);		// Input of polynomial number, coefficient and exponent
		if(choice == 1)
			poly1 = add_term_at_end(poly1, coefficient, exponent);			// Adding at end since linked list to be arranged in decreasing order.
		else
			poly2 = add_term_at_end(poly2, coefficient, exponent);

		printf("Enter the polynomial the term belongs to: ");		
		scanf("%d", &choice);		// Input of polynomial number, coefficient and exponent.
	}
	print_list(poly1);
	print_list(poly2);

	result = multiplication(poly1, poly2, result);			// Product of poly1 and poly2. Stored in result.

	printf("The product of the two polynomials is:\n");
	print_list(result);

	return 0;
}

// Function definitions
struct node *add_term_at_end(struct node *poly, int coefficient, int exponent)			// Adding the term at the end
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));

	temp->coef = coefficient;
	temp->expnt = exponent;
	temp->next = NULL;

	if(poly == NULL)
		poly = temp;
	else
	{
		while(poly->next != NULL)
			poly = poly->next;

		poly->next = temp;
	} 
	return poly;
}

struct node *multiplication(struct node *poly1, struct node *poly2, struct node *result)		// Product of poly1 and poly2. Stored in result.
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp = poly2;
	int coefficient, exponent;

	while(poly1 != NULL)
	{
		while(poly2 != NULL)
		{
			coefficient = poly1->coef * poly2->coef;
			exponent = poly1->expnt + poly2->expnt;
			result = add_term_at_end(result, coefficient, exponent);
			poly2 = poly2->next;
		}
		poly2 = temp;
		poly1 = poly1->next;
	}
	result = addition(result);
	return result;
}

struct node *addition(struct node *result)			// To add the terms with same exponent
{
	struct node *temp, *temp2;
	temp = (struct node *)malloc(sizeof(struct node));
	temp = result;

	while(result->next != NULL)
	{
		temp = result;
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
	return result;
}

void print_list(struct node *result)			// To print the list
{
	while(result != NULL)
	{
		printf("Coefficient - %d ", result->coef);
		printf(" Exponent - %d\n", result->expnt);
		result = result->next;
	}
}
