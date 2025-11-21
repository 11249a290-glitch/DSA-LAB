#include <stdio.h>
#define MAX 5
int queue[MAX], front = 0, rear = 0;
void enqueue(int x) 
{
    if (rear == MAX)
        printf("Queue Overflow\n");
    else
        queue[rear++] = x;
}
int dequeue() 
{
    if (front == rear) {
        printf("Queue Underflow\n");
        return -1;
    } else
        return queue[front++];
}
void display() 
{
    if (front == rear)
        printf("Queue is Empty\n");
    else {
        for (int i = front; i < rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() 
{
    enqueue(10); 
    enqueue(20); 
    enqueue(30); 
    enqueue(40); 
    enqueue(50);
    display();   
    dequeue(); 
    dequeue();
    display();      
    return 0;
}
