#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data){
    struct Node *Node = (struct Node*)malloc(sizeof(struct Node));
    if(!Node){
        printf("Heap overflow.\n");
        exit(0);
    }
    Node->data = data;
    Node->left = Node->right = NULL;
    return Node;
}

struct Node *insert(struct Node *root, int data){
    if(root == NULL){
        root = createNode(data);
    }
    else{
        if(data > root->data){
            root->right = insert(root->right, data);
        }
        else{
            root->left = insert(root->left, data);
        }
    }
    return root;
}

struct Node *createBST(int *arr, int n){
    struct Node *root = NULL;
    for(int i =0; i<n; i++){
        root = insert(root,arr[i]);
    }
    printf("BST CREATED\n");
    return root;
}

struct Node *delete(struct Node *root,int data){
    struct Node *temp ;
    if(!root){
        printf("No elements");
    }
    else if(data < root->data){
        root->left = delete(root->left, data);
    }
    else if(data > root->data){
        root->right = delete(root->right, data);
    }
    else{
        //element found
        if(root->left && root->right){
            //2child
            temp = findMAX(root->left);
            root->data = temp -> data;
            root->left = delete(root->left, root->data);
            
        }
        else{
            // 1 child
            temp = root;
            if(root->left == NULL){
                root= root->right;
            }
            if(root->right == NULL){
                root = root->left;
            }
            free(temp);
        }
    }
    return root;
}

int find(struct Node *root, int data){
    if(root == NULL){
        printf("BST empty");
        return -1;
    }
    while(root){
        if(data > root->data){
            root = root->right;
        }
        else if(data < root->data){
            root = root->left;
        }
        else{
            printf("Found");
            return 1;
        }
    }
    printf("Not found");
    return 0;
}

struct Node *findMAX(struct Node *root){
    if(!root){
        printf("BST EMPTY\n");
    }
    while(root->right!=NULL){
        root = root->right;
    }
    printf("%d", root->data);
    return root;
}

struct Node *findMIN(struct Node *root){
    if(!root){
        printf("BST EMPTY\n");
    }
    while(root->left!=NULL){
        root = root->left;
    }
    printf("%d", root->data);
    return root;
}

void InOrderTraversal(struct Node* root){
    if(root){
        InOrderTraversal(root->left);
        printf("%d\t", root->data);
        InOrderTraversal(root->right);
    }
}

int main(){
    int n = 5;
    int arr[5] = { 10,23, 67 ,9, 2};
    struct Node *root = createBST(arr, n);
    InOrderTraversal(root);
    findMAX(root);
    findMIN(root);

    return 0;
}

