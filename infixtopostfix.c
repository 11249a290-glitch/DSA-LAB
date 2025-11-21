#include <stdio.h>
#include <ctype.h>
#define SIZE 100
char stack[SIZE]; int top = -1;
void push(char c) 
{ 
stack[++top] = c; 
}
char pop() { 
return stack[top--];
 }
int prec(char c) 
{ return (c=='^')?3 : (c=='*'||c=='/')?2 : (c=='+'||c=='-')?1 : 0; }
void infixToPostfix(char *infix, char *postfix) 
{
    int i=0, j=0; char c;
    while((c=infix[i++])!='\0') {
        if(isalnum(c)) postfix[j++] = c;
        else if(c=='(') push(c);
        else if(c==')') {
            while(top>-1 && stack[top]!='(') postfix[j++]=pop();
            pop();
        } else {
            while(top>-1 && prec(stack[top])>=prec(c)) postfix[j++]=pop();
            push(c);
        }
    }
    while(top>-1) postfix[j++]=pop();
    postfix[j]='\0';
}

int main() {
    char infix[] = "A+B*C";
    char postfix[SIZE];
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    return 0;
}
