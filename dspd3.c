
        printf("'%c' inserted into queue.\n", value);
    }
}

// Function to delete an element from the queue
void deleteElement() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Nothing to delete.\n");
        front = rear = -1;
    } else {
        printf("Deleted element: '%c'\n", queue[front]);
        front++;
    }
}

// Function to display the queue
void displayQueue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%c ", queue[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice;
    char value;

    while (1) {
        printf("\n---- QUEUE MENU ----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:#include <stdio.h>
#include <string.h>

#define MAX 10  // Maximum size of the queue

char queue[MAX];
int front = -1, rear = -1;

// Function to insert an element into the queue
void insertElement(char value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert '%c'.\n", value);
    } else {
        if (front == -1)
            front = 0;  // first element
        rear++;
        queue[rear] = value;
                printf("Enter a character to insert: ");
                scanf(" %c", &value);  // space before %c ignores newline
                insertElement(value);
                break;

            case 2:
                deleteElement();
                break;

            case 3:
                displayQueue();
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
