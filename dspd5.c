#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary tree (BST)
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);
    // duplicate values are ignored
    return root;
}

// Inorder Traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Search for a node
void search(struct Node* root, int key) {
    if (root == NULL) {
        printf("NULL\n");
    } else if (root->data == key) {
        printf("Found\n");
    } else if (key < root->data) {
        search(root->left, key);
    } else {
        search(root->right, key);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value, searchKey, i;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter the node values:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");
    
    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");
    
    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");
    
    printf("Enter value to search: ");
    scanf("%d", &searchKey);
    search(root, searchKey);
    
    return 0;
}