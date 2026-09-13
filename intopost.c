#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 200

char stack[MAX];
int top = -1;

int evalStack[MAX];
int evalTop = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

void pushEval(int x)
{
    evalStack[++evalTop] = x;
}

int popEval()
{
    return evalStack[evalTop--];
}

int precedence(char x)
{
    if (x == '^')
        return 3;
    if (x == '*' || x == '/')
        return 2;
    if (x == '+' || x == '-')
        return 1;

    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char ch;

    top = -1;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        // Ignore spaces
        if (ch == ' ')
            continue;

        // If number, copy the complete number
        if (isdigit(ch))
        {
            while (isdigit(infix[i]))
            {
                postfix[j++] = infix[i++];
            }

            postfix[j++] = ' ';
            i--;
        }

        // Opening bracket
        else if (ch == '(')
        {
            push(ch);
        }

        // Closing bracket
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }

            if (top != -1)
                pop();
        }

        // Operator
        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }

            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1)
    {
        postfix[j++] = pop();
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[])
{
    int i = 0;
    int num, a, b, result;
    char ch;

    evalTop = -1;

    while (postfix[i] != '\0')
    {
        // Skip spaces
        if (postfix[i] == ' ')
        {
            i++;
            continue;
        }

        // Read complete number
        if (isdigit(postfix[i]))
        {
            num = 0;

            while (isdigit(postfix[i]))
            {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }

            pushEval(num);
        }

        // Operator
        else
        {
            ch = postfix[i];

            b = popEval();
            a = popEval();

            switch (ch)
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;

                case '^':
                    result = 1;

                    for (int k = 0; k < b; k++)
                        result *= a;

                    break;
            }

            pushEval(result);
            i++;
        }
    }

    return popEval();
}

int main()
{
    int choice;
    char infix[MAX];
    char postfix[MAX];

    do
    {
        printf("\n===== MENU =====\n");
        printf("1. Convert Infix to Postfix\n");
        printf("2. Evaluate Postfix Expression\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter infix expression: ");
                scanf(" %[^\n]", infix);

                infixToPostfix(infix, postfix);

                printf("Postfix expression: %s\n", postfix);
                break;

            case 2:
                printf("Enter postfix expression: ");
                scanf(" %[^\n]", postfix);

                printf("Result: %d\n", evaluatePostfix(postfix));
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}