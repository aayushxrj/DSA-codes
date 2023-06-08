#include<stdio.h>
#include<stdlib.h>

struct binaryTreeNode{          // node of a binary tree 
    int data;
    struct binaryTreeNode *left;
    struct binaryTreeNode *right;
};

struct binaryTreeNode *createNode(int data){            //creating node
    struct binaryTreeNode *newNode = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct binaryTreeNode* createBinaryTree(int* arr, int size) { //constructing the binary tree
    if (size <= 0) {
        return NULL;
    }

    struct binaryTreeNode** queue = (struct binaryTreeNode**)malloc(sizeof(struct binaryTreeNode*) * size);
    int front = 0;
    int rear = 0;

    struct binaryTreeNode* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < size) {
        struct binaryTreeNode* parent = queue[front++];
        struct binaryTreeNode* leftChild = NULL;
        struct binaryTreeNode* rightChild = NULL;

        leftChild = createNode(arr[i++]);
        queue[rear++] = leftChild;

        if (i < size) {
            rightChild = createNode(arr[i++]);
            queue[rear++] = rightChild;
        }

        parent->left = leftChild;
        parent->right = rightChild;
    }
    return root;
}

int evenLevelSum = 0;
int oddLevelSum = 0;

void alternateLevelSum(struct binaryTreeNode *root) {//finding the sum of alternate levels and storing them in evenLevelSum and oddLevelSum
    if (root == NULL) {
        printf("The tree is empty.\n");
        return;
    }

    int level = 1;

    struct binaryTreeNode **queue = (struct binaryTreeNode **)malloc(sizeof(struct binaryTreeNode *) * 100);
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front != rear) {
        int currentLevelSize = rear - front;
        int levelSum = 0;

        for (int i = 0; i < currentLevelSize; i++) {
            struct binaryTreeNode *node = queue[front++];
            levelSum += node->data;
            if (node->left) {
                queue[rear++] = node->left;
            }

            if (node->right) {
                queue[rear++] = node->right;
            }
        }

        if (level % 2 == 0) {
            evenLevelSum += levelSum;
        } else {
            oddLevelSum += levelSum;
        }
        level++;
    }
}

int main(){

    //input from the user 
    printf("Enter the no. of houses : ");
    int n;
    scanf("%d", &n);

    int root[n]; 
    printf("Enter the houses : ");
    for(int i=0; i<n; i++){
        scanf("%d", &root[i]);         //take NULL as 0
    }    

    //creating the binary tree
    struct binaryTreeNode *rootNode = createBinaryTree(root, n);

    //calling the function and calculating the 
    alternateLevelSum(rootNode);

    //output
    printf("The theif has looted a total of : ");
    if(evenLevelSum > oddLevelSum){
        printf("%d", evenLevelSum);
    }
    else{
        printf("%d", oddLevelSum);
    }

    return 0;
}