#include <stdio.h>
#include <stdlib.h>

#define MAX 10  // Maximum size of stack

int stack[MAX];
int top = -1;

// Function to push an element
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("%d pushed onto stack.\n", value);
    }
}

// Function to pop an element
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Nothing to pop.\n");
    } else {
        printf("Popped element: %d\n", stack[top--]);
    }
}

// Function to display stack
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top to bottom):\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

// Function to check if a number is palindrome using stack
void checkPalindrome() {
    int num, temp, digit, rev = 0;
    top = -1; // Clear stack for palindrome checking

    printf("Enter a number to check palindrome: ");
    scanf("%d", &num);
    temp = num;

    // Push each digit onto stack
    while (temp > 0) {
        digit = temp % 10;
        push(digit);
        temp /= 10;
    }

    temp = num; // Reset
    while (temp > 0) {
        digit = temp % 10;
        if (digit != stack[top--]) {  // Compare with popped values
            printf("%d is not a palindrome.\n", num);
            return;
        }
        temp /= 10;
    }

    printf("%d is a palindrome.\n", num);
}

// Main program
int main() {
    int choice, value;

    while (1) {
        printf("\n---- STACK MENU ----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check Palindrome\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                checkPalindrome();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
