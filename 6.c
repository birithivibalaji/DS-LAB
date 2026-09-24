#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int height;
    struct Node *left;
    struct Node *right;
};

int height(struct Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct Node *createNode(int data) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int getBalance(struct Node *node) {
    if (node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

struct Node *insert(struct Node *root, int data) {

    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;

    root->height = 1 + max(height(root->left),
                            height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

struct Node *minValueNode(struct Node *node) {
    struct Node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

struct Node *deleteNode(struct Node *root, int data) {

    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);

    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else {

        if (root->left == NULL || root->right == NULL) {

            struct Node *temp;

            if (root->left != NULL)
                temp = root->left;
            else
                temp = root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else {
                *root = *temp;
            }

            free(temp);
        }
        else {

            struct Node *temp =
                minValueNode(root->right);

            root->data = temp->data;

            root->right =
                deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left),
                            height(root->right));

    int balance = getBalance(root);

    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 &&
        getBalance(root->left) < 0) {

        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 &&
        getBalance(root->right) > 0) {

        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preorder(struct Node *root) {

    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {

    struct Node *root = NULL;

    int values[] = {5, 0, -1, 2, 1, 9, 6, 10, 11};
    int n = 9;

    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    printf("Preorder traversal of the constructed AVL tree is:\n");
    preorder(root);

    root = deleteNode(root, 10);

    printf("\n\nPreorder traversal after deletion of 10:\n");
    preorder(root);

    printf("\n");

    return 0;
}

OUTPUT:
Preorder traversal of the constructed AVL tree is
5 0 -1 1 2 9 6 10 11
Preorder traversal after deletion of 10
5 0 -1 1 2 9 6 11
