#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// create a new node
struct Node *newNode(int value) {
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

// insert a value into BST, returns the root pointer
struct Node *insert(struct Node *root, int value) {
    if (root == NULL) {
        return newNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        // duplicate value, do nothing
        printf("Value %d already exists in BST.\n", value);
    }
    return root;
}

// search for a value in BST, returns pointer to node if found, else NULL
struct Node *search(struct Node *root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// delete a *leaf* node with given key. Returns the root pointer (maybe unchanged).
struct Node *deleteLeaf(struct Node *root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (key < root->data) {
        root->left = deleteLeaf(root->left, key);
    } else if (key > root->data) {
        root->right = deleteLeaf(root->right, key);
    } else {
        // we found the node with root->data == key
        if (root->left == NULL && root->right == NULL) {
            // it's a leaf, safe to delete
            free(root);
            return NULL;
        } else {
            // not a leaf
            printf("Node %d is not a leaf, cannot delete.\n", key);
        }
    }
    return root;
}

// In-order traversal to print tree contents (for debugging / viewing)
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    int choice, value;
    while (1) {
        printf("\n---- BST MENU ----\n");
        printf("1. Search an element in BST\n");
        printf("2. Insert an element in BST\n");
        printf("3. Delete leaf element in BST\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &value);
                if (search(root, value) == NULL) {
                    printf("NULL\n");
                } else {
                    printf("Found\n");
                }
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Current BST (in‐order): ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Enter leaf element to delete: ");
                scanf("%d", &value);
                root = deleteLeaf(root, value);
                printf("Current BST (in‐order): ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
