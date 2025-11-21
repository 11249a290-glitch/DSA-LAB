#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node *next;
};
struct Node* createNode(int x) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    return n;
}
void insertEnd(struct Node **head, int x) 
{
    struct Node *n = createNode(x), *temp = *head;
    if (*head == NULL) 
 { *head = n; return; 
}
    while (temp->next != NULL) temp = temp->next;
    temp->next = n;
}
void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    display(head);
    return 0;
}
