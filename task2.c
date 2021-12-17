#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Stack
{
	int top;
	unsigned capacity;
	int* array;
};

struct Stack* createStack( unsigned capacity )
{
	struct Stack* stack = (struct Stack*)
		malloc(sizeof(struct Stack));

	if (!stack)
		return NULL;

	stack->top = -1;
	stack->capacity = capacity;

	stack->array = (int*) malloc(stack->capacity * sizeof(int));

	return stack;
}
int isEmpty(struct Stack* stack)
{
	return stack->top == -1 ;
}
char peek(struct Stack* stack)
{
	return stack->array[stack->top];
}
char pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--] ;
	return '$';
}
void push(struct Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}

int isOperand(char ch)
{
	return (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9');
}

// Ham tra ve mux=c do uu tien cua toan tu da cho
// Neu co muc do uu tien cao hon thi tra ve cao hon
int Prec(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}

int infixToPostfix(char* exp)
{
	int i, k;

	// Tao 1 dung luong ngan xep bang do dai cua bieu thuc
	struct Stack* stack = createStack(strlen(exp));
	if(!stack) // Kiem tra ngan xep da thanh cong hay chua
		return -1 ;

	for (i = 0, k = -1; exp[i]; ++i)
	{
		
		// Neu ki tu la mot toan hang thi them no vao output
		if (isOperand(exp[i]))
			exp[++k] = exp[i];
		
		// Neu ki tu la ‘(‘ thi day no vao stack.
		else if (exp[i] == '(')
			push(stack, exp[i]);
		
		// Nếu ký tự được quét là dấu ‘)’ thi pop và xuat từ stack cho đến khi gặp dấu ‘(‘
		else if (exp[i] == ')') 
		{
			while (!isEmpty(stack) && peek(stack) != '(')
				exp[++k] = pop(stack);
			if (!isEmpty(stack) && peek(stack) != '(')
				return -1; // khong hop le			
			else
				pop(stack);
		}
		else 
		{
			while (!isEmpty(stack) &&
				Prec(exp[i]) <= Prec(peek(stack)))
				exp[++k] = pop(stack);
			push(stack, exp[i]);
		}

	}

	// pop tat ca toan tu from stack
	while (!isEmpty(stack))
		exp[++k] = pop(stack );

	exp[++k] = '\0';
	printf( "%s", exp );
}

int evaluatePostfix(char* exp)
{
    struct Stack* stack = createStack(strlen(exp));
    int i;
 
    if (!stack) return -1;
 
    for (i = 0; exp[i]; ++i)
    {
        if (isdigit(exp[i]))
            push(stack, exp[i] - '0');
        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i])
            {
            case '+': push(stack, val2 + val1); break;
            case '-': push(stack, val2 - val1); break;
            case '*': push(stack, val2 * val1); break;
            case '/': push(stack, val2/val1); break;
            }
        }
    }
    return pop(stack);
}


int main()
{
	char exp[100];
    printf("Input: ");
    fflush(stdin);
    gets(exp);
	infixToPostfix(exp);
    printf ("\npostfix evaluation: %d", evaluatePostfix(exp));
	return 0;
}