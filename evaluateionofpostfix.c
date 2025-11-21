#include <stdio.h>
#include <ctype.h>
#define SIZE 40
int stack[SIZE], top = -1;
void push(int val) { stack[++top] = val; }
int pop() 
{ 
return stack[top--];
}
int main() 
{
    char postfix[SIZE]; int i, a, b;
    printf("Enter postfix expr: "); 
    scanf("%s", postfix);
    for (i = 0; postfix[i]; i++) 
       {
         if (isdigit(postfix[i]))
          push(postfix[i] - '0');
         else
           {
            b = pop(); a = pop();
            switch(postfix[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }
    printf("Result = %d\n", pop());
    return 0;
}
