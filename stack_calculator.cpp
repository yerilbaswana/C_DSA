// Program for stack calculator
// Libraries
#include<stdio.h>
#include<math.h>

// Function declarations
void tokenise(double *, char , bool);
int evaluation(float, float , char);
int out_stack_operator_precedence(char);
int in_stack_operator_precedence(char);

// Start of main()
int main()
{
    char *expression, *oprtr_stack, scanned_oprtr;
    int n, i = 0, top_oprtr_stk = -1, top_oprnd_stk = -1; 
    float *oprnd_stack, eval_result;
    double result = 0.0, decimal_place, digit;

    printf("Enter the length of the expresssion: ");        // To get length(for dynamic allocation)
    scanf("%d", &n);
    n++;

    expression = (char *)malloc(sizeof(char) * n);         // Dynamically allocating memory for expression
    oprtr_stack = (char *)malloc(sizeof(char) * n);       // Dynamically alocating memory for oprtr stack
    oprnd_stack = (float *)malloc(sizeof(float) * n);         // Dynamically alocating memory for oprnd stack

    printf("Enter the expression: ");          // To get input expression and store in exp
    scanf("%s", expression);

    expression[n - 1] = '#';       // Placing # at the end of the expression
    oprtr_stack[++top_oprtr_stk] = '$';       // Placing $ on top = 0 in oprtr_stack

    while(i < n)        // Loops till i is less than n
    {
        if(expression[i] >= 48 && expression[i] <= 57)        // When a number is scanned
        {
            result = 0.0;
            bool IsDecimal = false;
            while((expression[i] >= 48 && expression[i] <= 57) || expression[i] == 46)       // To tokenise number scanned and store in oprnd stack
            {
                if(expression[i] == 46)         // When a decimal is scanned
                {
                    IsDecimal = true;
                    i++;
                    decimal_place = 1.0;
                    continue;
                }    
                
                digit = expression[i] - '0';         // The num string is tokenised and converted into a float number 
                
                if(IsDecimal == false)
                {       
                    result = result * 10  + digit;
                }
                else
                {
                    decimal_place = decimal_place * 0.1;
                    result = result + digit * decimal_place;
                }    
                i++;   
            }
            oprnd_stack[++top_oprnd_stk] = result;       // The float number is stored in the oprnd stack
        }
        else           // When a operator is scanned
        {
            scanned_oprtr = expression[i];

            if(scanned_oprtr == ')')        // To solve the brackets
            {
                while(oprtr_stack[top_oprtr_stk] != '(')        // All operators inside bracket are popped and evaluated
                { 
                    float current_oprnd;
                    current_oprnd = oprnd_stack[top_oprnd_stk--];
                    eval_result = evaluation(oprnd_stack[top_oprnd_stk--], current_oprnd, oprtr_stack[top_oprtr_stk--]);       
                    oprnd_stack[++top_oprnd_stk] = eval_result;
                }
                top_oprtr_stk--;        // To pop '(' from the stack
                i++;
            }
            else
            {
                // Operator evalualted when precedence of scanned oprtr is less than or equal to precedence of top of oprtr stack
                while(out_stack_operator_precedence(scanned_oprtr) <= in_stack_operator_precedence(oprtr_stack[top_oprtr_stk]))         
                {   
                    float current_oprnd;
                    current_oprnd = oprnd_stack[top_oprnd_stk--];
                    eval_result = evaluation(oprnd_stack[top_oprnd_stk--], current_oprnd, oprtr_stack[top_oprtr_stk--]);       
                    oprnd_stack[++top_oprnd_stk] = eval_result;                        
                }                   
                oprtr_stack[++top_oprtr_stk] = scanned_oprtr;     
                i++;
            }    
        }
    }

    printf("The result is: %lf", oprnd_stack[top_oprnd_stk]);       // To print the result of evalualtion

    return 0;
}
// End of main()


// Function definitions
int in_stack_operator_precedence(char oprtr)            // To get the in stack precedence of a operator using switch case
{
    int priority;
    switch(oprtr)
    {

        case '$':
            priority = -2;
            break;

        case '#':
            priority = -1;
            break;

        case '(':
            priority = 0;
            break;

        case '+':
            priority = 1;
            break;

        case '-':
            priority = 1;
            break;

        case '*':
            priority = 2;
            break;

        case '/':
            priority = 2;
            break;

        case '^':
            priority = 3;
            break;
    }
    return(priority);
}

int out_stack_operator_precedence(char oprtr)            // To get the out stack precedence of a operator using switch case
{
    int priority;
    switch(oprtr)
    {

        case '$':
            priority = -2;
            break;

        case '#':
            priority = -1;
            break;

        case '(':
            priority = 5;
            break;

        case '+':
            priority = 1;
            break;

        case '-':
            priority = 1;
            break;

        case '*':
            priority = 2;
            break;

        case '/':
            priority = 2;
            break;

        case '^':
            priority = 4;
            break;
    }
    return(priority);
}

int evaluation(float x, float y, char oprtr)         // To get result of operator and it's suitable operands
{
    float result;

    switch(oprtr)
    {
        case '+':
            result = x + y;
            break;

        case '-':
            result = x - y;
            break;

        case '*':
            result = x * y;
            break;

        case '/':
            result = x / y;
            break;

        case '^':
            result = pow(x, y);
            break;
    }

    return(result);
}
