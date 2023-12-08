#include <stdio.h>
#include <stdlib.h>

//node strucutre for BST
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

Node *insertNode(Node *root, int value);
Node *newNode(int value);
void printTree(Node *root, int space);

int main(int argc, char *argv[]) {
    Node *root = NULL;

    //parse command line arguments and insert value into BST
    for (int i = 1; i < argc; i++) {
        int value = atoi(argv[i]); 
        root = insertNode(root, value);
    }
    
    printf("Binary search tree: ");
    printTree(root, 0);
}

//function to insert a new node into BST
Node *insertNode(Node *root, int value) {
    if (root == NULL) {
        return  newNode(value);
    }

    if (value < root->key) {
        root->left = insertNode(root->left, value);
    } else if (value > root->key) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

//function to create a new node
Node *newNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//function to print BST in visual way
void printTree(Node *root, int space) {
    if (root == NULL){
        return;  
    }
    space +=5; //increase distance between levels

    printTree(root->right, space); //process right child first

    //print current node after space count
    printf("\n");
    for (int i = 0; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->key);

    printTree(root->left, space); // process left child    
}