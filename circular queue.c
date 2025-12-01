#include <stdio.h>

#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

void add() {   // Enqueue
    int x;
    if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front) {
        printf("Circular Queue Overflow\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &x);

    if (front == -1)  // First element
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    cq[rear] = x;
    printf("Inserted %d\n", x);
}

void delete() {   // Dequeue
    if (front == -1) {
        printf("Circular Queue Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", cq[front]);

    if (front == rear)  // Only one element
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display() {
    if (front == -1) {
        printf("Circular Queue is empty\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. Add\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
