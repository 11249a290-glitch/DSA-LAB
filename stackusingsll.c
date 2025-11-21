#include <stdio.h>
#include <stdlib.h>
struct Node
 {
    int data;
    struct Node *next;
};
struct Node *top = NULL;
void push(int x) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    top = n;
}
int pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node *t = top;
    int x = t->data;
    top = top->next;
    free(t);
    return x;
}
void display() {
    struct Node *p = top;
    while (p != NULL) 
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
 {
    push(10);
    push(20);
    push(30);
    display();        
    printf("Popped: %d\n", pop()); 
    display();         
    return 0;
}
