/* Copyright Liam O'Brien December 2019 
   A C application that focuses primarily on memory allocation and pointer functionality
   Using the stack data structure to convert values from infix to postfix
*/



#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define bool int
#define ELEMENTS 100
#define SIZE 20
#define EMPTY -1
struct stack {

    int items[SIZE];
    int top;

};

void initialize(struct stack* stackPtr);
int full(struct stack* stackPtr);
int push(struct stack* stackPtr, int value);
int empty(struct stack* stackPtr);
int pop(struct stack* stackPtr);
int top(struct stack* stackPtr);
char x[50] = "";
char cArray[50] = "";
char make[50];
char stack[100];
char infix[50];
char *postFix;
char *result;
char *str;
struct stack paren;
struct stack ifix_pfix;
struct stack post;
struct stack intstack;
char* menu();

int isBalancedParenthesis(char *);
int convertToInt(char * c);
int calculate(int a, int b, char op);
int isOperator(char c);
void evaluate(char * postFix);
int getOperatorPriority(char c);
int convertToInt(char * c);
char * convertToPostfix(char *c);
void stackToString(struct stack * nStack, char *make);

int main(void)
{
	while(strcmp(str = menu(), "exit")!=0)
	{
		if (isBalancedParenthesis(str) == 1)
		{
			
			postFix = convertToPostfix(str);
			evaluate(postFix);
		}
		else
		{
			printf("Parenthesis imbalanced");
		}
	}
	return 0;
}


char* menu()
{
	char option;
    char input[50] = "";
	printf("\nEnter 'e' to enter an infix, or enter 'x' to exit the program.\n");
    fflush(stdin);
    fgets(input, 50, stdin);
	sscanf(input, "%c", &option);

	if (option == 'e')
	{
		printf("Please enter an infix:\n");
		fflush(stdin);
		fgets(infix, 50, stdin);
		
		result = (char*)calloc(strlen(infix) + 1, sizeof(char));
		if (result != NULL)
		{
			strcpy(result, infix);
		}

		return result;
	}

	else if (option == 'x')
	{
		
		result = (char*)calloc(strlen("exit") + 1, sizeof(char));
		if (result != NULL)
		{
			strcpy(result, "exit");
		}
		return result;
	}

	else
	{
		printf("Sorry you have entered an invalid character.");
		void exit(int status);
	}
}



int isBalancedParenthesis(char *exp)
{
	initialize(&paren);
	int i = 0;
	for(i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '(')
		{
			push(&paren, exp[i]);
		}
		else if (exp[i] == ')')
		{
			if (!empty(&paren))
			{
				pop(&paren);
			}
			else
			{
				return 0;
			}
			
		}
	}
	if (empty(&paren))
	{

		return 1;
	}
		
	else
	{
		return 0;
	}
}



int isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^' )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



int getOperatorPriority(char c)
{
	if(c =='(')
	{
		return 1;
	}
	else if(c == '+' || c == '-')
	{
		return 2;
	}
	else if(c == '%'|| c == '*' || c == '/')
	{
		return 3;
	}
	else if(c =='^')
	{
		return 4;
	}
	else
	{
		return 0;
	}
}



char * convertToPostfix(char *c)
{
	strcpy(cArray, "");

	int i = 0;
	initialize(&post);
	for(i = 0; i < strlen(c); i++)
	{
	
		
		if (c[i] == ' ')
		{
			continue;
		}
		else if (isOperator(c[i]))
		{
			
			while(!empty(&ifix_pfix) && top(&ifix_pfix) != '(' && getOperatorPriority(top(&ifix_pfix)) > getOperatorPriority(c[i]))
			{
				char x = pop(&ifix_pfix);
				sprintf(cArray, "%s %c", cArray, x);
			}
			push(&ifix_pfix, c[i]);
			strcat(cArray, " ");
		}
		else if(c[i] >= '0' && c[i] <= '9')
		{
			sprintf(cArray, "%s%c", cArray, c[i]);
			
		}
		else if(c[i] == '(')
		{
			push(&ifix_pfix, c[i]);
		}
		else if(c[i] == ')')
		{
			while(!empty(&ifix_pfix) && top(&ifix_pfix) != '(')
			{
				char x = pop(&ifix_pfix);
				sprintf(cArray, "%s %c", cArray, x);
			}
			pop(&ifix_pfix);
		}
	
	}
		while(!empty(&ifix_pfix))
		{
			char x = pop(&ifix_pfix);
			sprintf(cArray, "%s %c", cArray, x);
		}
		printf("\n");
		printf("Output: %s\n", cArray);
		return cArray;
}




int convertToInt(char * c)
{
	char num[50] = "";
	int x = 0;
	int val = 0;
	while(isdigit(c[x]) && x < strlen(c))
	{
		sprintf(num, "%s%c", num, c[x]);
		x++;	
	}
	sscanf(num, "%d", &val);
	return val;
}




void evaluate(char * postFix)
{
	char num[50] = "";
	int i = 0;
	initialize(&intstack);
	int y = 0;
	for(i = 0; i < strlen(postFix); i++)
	{
		if(isdigit(postFix[i]))
		{
			sprintf(num, "%s%c", num, postFix[i]);
		}
		else if(postFix[i] == ' ')
		{
			if(strlen(num))
			{
				y = convertToInt(num);
				push(&intstack, y);
//				printf("y = %d\n", y);
				strcpy(num, "");
			}
		}
		else if (isOperator(postFix[i]))
		{
			int b = pop(&intstack);
			int a = pop(&intstack);
			push(&intstack, calculate(a, b, postFix[i]));
//			printf("calc = %d\n", calculate(a, b, postFix[i]));
			
		}
	}
	printf("Evaluation: %d\n", pop(&intstack));
}




int calculate(int a, int b, char op)
{
	int result;
//	printf("a=%d b=%d op=%c\n", a, b , op);
	if(op == '+')
	{
		result = a + b;
	}
	else if(op == '-')
	{
		result = a - b;
	}
	else if(op == '*')
	{
		result = a * b;
	}
	else if(op == '/')
	{
		result = a / b;
	}
	else if(op == '^')
	{
		result = (int)pow(a, b);
	}
	return result;
}





void initialize(struct stack* stackPtr) 
{
     stackPtr->top = -1;
}




int push(struct stack* stackPtr, int value) 
{

    if (full(stackPtr))
        return 0;

    stackPtr->items[stackPtr->top+1] = value;
    (stackPtr->top)++;
    return 1;
}





int full(struct stack* stackPtr) {
    return (stackPtr->top == SIZE - 1);
}





int empty(struct stack* stackPtr) {
    return (stackPtr->top == -1);
}





int pop(struct stack* stackPtr) 
{

    int retval;

    if (empty(stackPtr))
        return EMPTY;

    retval = stackPtr->items[stackPtr->top];
    (stackPtr->top)--;
    return retval;
}






int top(struct stack* stackPtr) {

    if (empty(stackPtr))
        return EMPTY;

    return stackPtr->items[stackPtr->top];
}




