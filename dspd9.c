#include <stdio.h>

#define SIZE 7

int hash(int key) {
    return key % SIZE;
}

void insert(int hashTable[], int key) {
    int index = hash(key);
    int startIndex = index;  // to track loop

    // Linear probing in case of collision
    while(hashTable[index] != -1) {
        index = (index + 1) % SIZE;
        if(index == startIndex) {
            printf("Hash Table is full, cannot insert %d\n", key);
            return;
        }
    }
    hashTable[index] = key;
}

void display(int hashTable[]) {
    printf("Final hash table:\n");
    for(int i=0; i<SIZE; i++) {
        if(hashTable[i] == -1)
            printf("Slot %d: Empty\n", i);
        else
            printf("Slot %d: %d\n", i, hashTable[i]);
    }
}

int main() {
    int hashTable[SIZE];
    int n, key;

    // Initialize hash table slots to -1 to indicate empty
    for(int i=0; i<SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of elements to insert (<= %d): ", SIZE);
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &key);
        insert(hashTable, key);
    }

    display(hashTable);

    return 0;
}
