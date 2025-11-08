#include <stdio.h>

int main() {
    int n, i;                     
    int numbers[100];             
    int sum_even = 0, sum_odd = 0;

    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    
    for (i = 0; i < n; i++) {
        if ((i + 1) % 2 == 0)     // (i+1) because positions start from 1
            sum_even += numbers[i];
        else
            sum_odd += numbers[i];
    }

    
    printf("Sum of numbers at even positions: %d\n", sum_even);
    printf("Sum of numbers at odd positions: %d\n", sum_odd);

    return 0;
}