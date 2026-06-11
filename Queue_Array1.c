#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    // The queue is full if the next position for rear hits the front
    if ((rear + 1) % SIZE == front) {
        printf("Queue is Full! Cannot enqueue %d\n", value);
    } else {
        if (front == -1) front = 0; // Set front if queue was empty
        
        // Wrap rear around using modulo
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is Empty!\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        
        // If front and rear are at the same position, the queue is now empty
        if (front == rear) { 
            front = -1;
            rear = -1;
        } else {
            // Wrap front around using modulo
            front = (front + 1) % SIZE;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % SIZE; // Move to next index circularly
        }
        printf("\n");
    }
}

int main() {
    // 1. Fill the queue
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50); 
    display(); // Queue is now entirely full

    // 2. Remove two elements (frees up index 0 and 1)
    dequeue();
    dequeue();   
    display();

    // 3. The "Fix" in action: Adding new elements wraps to the front
    enqueue(60); // Placed at index 0
    enqueue(70); // Placed at index 1
    display();

    return 0;
}
