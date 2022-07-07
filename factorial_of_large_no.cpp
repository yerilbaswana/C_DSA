// Program for finding factorial of a large number
// Libraries
#include<stdio.h>

//Start of main()
int main()
{
	int num, temp_result, carry = 0, i = 2, size = 1;
	int result[1000] = {1};

	printf("Enter number for finding factorial: ");			// Input number 
	scanf("%d", &num);
	// The result will be stored in reverse order to accomodate carry as new digit easily
	while(i <= num)			// i goes from i = 2 to i = n
	{
		carry = 0;
		for(int j = 0; j < size; j++)		// To multiply each digit in the array
		{
			temp_result = i * result[j] + carry;			// Store result in variable temp_result
			carry = temp_result / 10;			// Carry is added to the next digit
			result[j] = temp_result % 10;			// The first digit is stored in the array
		}
		while(carry != 0)		// To store carry as new digit if all numbers are already multiplied
		{
			result[size] = carry % 10;
			carry = carry / 10;
			size++;
		}
		i++;		// Incrementing value of i
	} 		
	printf("The factorial of %d is: ", num);
	for(int j = size - 1; j >= 0; j--)			// To print factorial of the number
		printf("%d", result[j]);

	return 0;
}	
// End of main()
