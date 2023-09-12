#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

bool isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (rear == front - 1);
}

bool isEmpty() {
    return front == -1;
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (front == -1)
        front = rear = 0;
    else if (rear == MAX_SIZE - 1)
        rear = 0;
    else
        rear++;

    queue[rear] = item;
    printf("%d enqueued to the queue.\n", item);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int item = queue[front];
    if (front == rear)
        front = rear = -1;
    else if (front == MAX_SIZE - 1)
        front = 0;
    else
        front++;

    return item;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    int i = front;
    printf("Queue elements: ");
    if (front <= rear) {
        while (i <= rear)
            printf("%d ", queue[i++]);
    } else {
        while (i < MAX_SIZE)
            printf("%d ", queue[i++]);
        i = 0;
        while (i <= rear)
            printf("%d ", queue[i++]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    enqueue(60);
    enqueue(70);

    display();

    return 0;
}

