#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node *front = NULL, *rear = NULL;
void enqueue(int x)
 {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}
int dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    struct Node* temp = front;
    int val = temp->data;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    return val;
}
void display() {
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("Queue: ");
    display();
    printf("Dequeued: %d\n", dequeue());
    printf("Queue after dequeue: ");
    display();
    return 0;
}
