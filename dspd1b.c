#include <stdio.h>
#include <stdbool.h>

bool binarySearch(int searchList[], int size, int target) {
    
    if (searchList == NULL || size <= 0) {
        return false;  
    }

    int start = 0;
    int end = size - 1;

    
    while (start <= end) {
        int mid = (start + end) / 2;
        printf("Middle value: %d (Index: %d)\n", searchList[mid], mid);

        if (searchList[mid] == target) {
            printf("Value found at index %d.\n", mid);
            return true;
        } 
        else if (target > searchList[mid]) {
            printf("Target is greater, adjusting start to mid + 1 (Index: %d)\n", mid + 1);
            start = mid + 1;
        } 
        else {
            printf("Target is smaller, adjusting end to mid - 1 (Index: %d)\n", mid - 1);
            end = mid - 1;
        }
    }

    
    printf("Value not found in the list.\n");
    return false;
}

int main() {
    int n, target;

    
    printf("Enter number of elements (sorted): ");
    scanf("%d", &n);

    
    if (n <= 0) {
        printf("Empty list. Exiting.\n");
        return 0;
    }

    int searchList[n];

    printf("Enter %d sorted numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &searchList[i]);
    }

    printf("Enter the value to search for: ");
    scanf("%d", &target);

    bool found = binarySearch(searchList, n, target);

    if (found)
        printf("Search successful.\n");
    else
        printf("Search unsuccessful.\n");

    return 0;
}
