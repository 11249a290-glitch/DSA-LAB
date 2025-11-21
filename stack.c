#include <stdio.h>
#define MAX 5
int stack[MAX], top = -1;
void push(int x)
{
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = x;
}
int pop() 
{
    if (top == -1) 
{
        printf("Stack Underflow\n");
        return -1;
   } else
        return stack[top--];
}
void display() {
    if (top == -1) printf("Stack is Empty\n");
    else {
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    push(10); 
    push(20); 
    push(30);
    push(40); 
    push(50);
    display(); 
    pop(); 
    pop();
    display(); 
    return 0;
}
