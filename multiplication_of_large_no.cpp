// Program for multiplication of two 18 digit numbers
// Libraries
#include<stdio.h>

// Function declarations
void number_parts(long long int, long long int *);
void multiplication(long long int, long long int, long long int *);

int main()
{
    long long int num1, num2, temp_result, num1_parts[2], num2_parts[2], prod_parts_a_c[2], prod_parts_a_d[2], prod_parts_b_c[2], prod_parts_b_d[2], result[4];
    int carry = 0; 

    printf("Enter the first number: ");     // To input first number
    scanf("%lld", &num1);

    printf("Enter the second number: ");        // To input second number
    scanf("%lld", &num2);

    number_parts(num1, num1_parts);         // To make segments of 9 digits of both numbers
    number_parts(num2, num2_parts);

    multiplication(num1_parts[0], num2_parts[0], prod_parts_a_c);           // To multiply segements formed and make segments of the product
    multiplication(num1_parts[0], num2_parts[1], prod_parts_a_d);
    multiplication(num1_parts[1], num2_parts[0], prod_parts_b_c);
    multiplication(num1_parts[1], num2_parts[1], prod_parts_b_d);

    result[3] = prod_parts_b_d[1];              // The last 9 digits of product of b & d forms last 9 digits of the result
    
    temp_result = prod_parts_b_d[0] + prod_parts_b_c[1] + prod_parts_a_d[1];            // The sum  of first 9 digits of b & d, last 9 of b & c, last 9 of a & d is assigned to temp_result
    result[2] = temp_result % 1000000000;               // The mod of temp_result gives the next 9 digits of result  
    carry = temp_result / 1000000000;               // The div of temp_result gives carry

    temp_result = prod_parts_b_c[0] + prod_parts_a_d[0] + prod_parts_a_c[1] + carry;        // The sum  of first 9 digits of a & d, first 9 of b & c, last 9 of a & c and previous carry is assigned to temp_result
    result[1] = temp_result % 1000000000;           // The mod of temp_result gives the next 9 digits of result
    carry = temp_result / 1000000000;           // The div of temp_result gives carry

    result[0] = prod_parts_a_c[0] + carry;          // The sum of first 9 digits of a & c and carry gives first 9 digits of result

    printf("The result is: ");
    for(int i = 0; i < 4; i++)              // To display product of the numbers
        printf("%lld", result[i]);

    return 0;
}

// Function definitions

void number_parts(long long int num, long long int *num_parts)            // To make segments of 9 digits of both numbers
{
    num_parts[0] = num / 1000000000;
    num_parts[1] = num % 1000000000;
}

void multiplication(long long int a, long long int b, long long int *prod_parts)              // To multiply segments and make segments of their products
{
    prod_parts[0] = (a * b) / 1000000000;
    prod_parts[1] = (a * b) % 1000000000;
}