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
void addition(struct node *);
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
	printf("\n");
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
		return temp;
	
	struct node *temp2;	
	temp2 = poly;
	while(temp2->next != NULL)
		temp2 = temp2->next;

	temp2->next = temp;
	return poly; 
}

struct node *multiplication(struct node *poly1, struct node *poly2, struct node *result)		// Product of poly1 and poly2. Stored in result.
{
	struct node *temp, *temp2, *temp3;
	temp = poly1;
	temp2 = poly2;
	temp3 = result;
	int coefficient, exponent;

	while(temp != NULL)
	{
		while(temp2 != NULL)
		{
			coefficient = temp->coef * temp2->coef;
			exponent = temp->expnt + temp2->expnt;
			result = add_term_at_end(result, coefficient, exponent);
			temp2 = temp2->next;
		}
		temp2 = poly2;
		temp = temp->next;
	}
	addition(result);		// ******ISSUE: The whole list isn't sent in this case as well and in the return statement as well.
	return result;
}

void addition(struct node *result)			// To add the terms with same exponent
{
	struct node *temp, *temp2, *temp3;
	temp2 = result;

	while(temp2->next != NULL)
	{
		temp = temp2;
		while(temp->next != NULL)
		{
			if(temp2->expnt == temp->next->expnt)
			{
				temp3 = temp->next;
				temp2->coef = temp2->coef + temp->next->coef;
				temp->next = temp->next->next;
				free(temp3);
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
		temp2 = temp2->next;
	}
}

void print_list(struct node *poly)			// To print the list
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp = poly;

	while(temp != NULL)
	{
		printf("%dx^", temp->coef);
		printf("%d", temp->expnt);
		if(temp->next != NULL)
			printf(" + ");
		temp = temp->next;
	}
}
