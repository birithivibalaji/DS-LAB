#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data);
struct Node *insert(struct Node *root, int data);
struct Node *search(struct Node *root, int key);
void inorder(struct Node *root);
void preorder(struct Node *root);
void postorder(struct Node *root);

int main() {
    struct Node *root = NULL;
    struct Node *result;
    int choice, element, key;

    while (1) {
        printf("\nBST MENU\n");
        printf("1. Create a BST\n");
        printf("2. Search\n");
        printf("3. BST Traversals\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                root = insert(root, element);
                printf("Element inserted successfully.\n");
                break;

            case 2:
                printf("Enter element to search: ");
                scanf("%d", &key);

                result = search(root, key);

                if (result != NULL)
                    printf("Element %d found in BST.\n", key);
                else
                    printf("Element %d not found in BST.\n", key);
                break;

            case 3:
                if (root == NULL) {
                    printf("BST is empty.\n");
                } else {
                    printf("\nBST Traversals:\n");

                    printf("Inorder: ");
                    inorder(root);

                    printf("\nPreorder: ");
                    preorder(root);

                    printf("\nPostorder: ");
                    postorder(root);

                    printf("\n");
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

struct Node *createNode(int data) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *insert(struct Node *root, int data) {

    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    else {
        printf("Duplicate element not allowed.\n");
    }

    return root;
}

struct Node *search(struct Node *root, int key) {

    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

void inorder(struct Node *root) {

    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root) {

    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root) {

    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

OUTPUT:
~~~~BST MENU~~~~
1. Create a BST
2. Search
3. BST Traversals:
4. Exit
Enter your choice: 1
Enter the number of elements: 12
Enter the value: 6
Enter the value: 9
Enter the value: 5
Enter the value: 2
Enter the value: 8
Enter the value: 15
Enter the value: 24
Enter the value: 14
Enter the value: 7
Enter the value: 8
Enter the value: 5
Enter the value: 2
~~~~BST MENU~~~~
1. Create a BST
2. Search
3. BST Traversals:
4. Exit
Enter your choice: 3
The Preorder display: 6 5 2 9 8 7 15 14 24
The Inorder display: 2 5 6 7 8 9 14 15 24
The Postorder display: 2 5 7 8 14 24 15 9 6
~~~~BST MENU~~~~
1. Create a BST
2. Search
3. BST Traversals:
4. Exit
Enter your choice: 2
Enter Element to be searched: 66
Key element is not found in the BST
~~~~BST MENU~~~~
1. Create a BST
2. Search
3. BST Traversals:
4. Exit
Enter your choice: 2
Enter Element to be searched: 14
Key element is present in BST
~~~~BST MENU~~~~
1. Create a BST
2. Search
3. BST Traversals:
4. Exit
Enter your choice: 4
