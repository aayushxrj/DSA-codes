#include<stdio.h>
#include<stdlib.h>

struct Node{       //Node of a BST
    int data;
    struct Node *left;
    struct Node *right;
};


struct Node *createNode(int data){        //function to create each node of the BST
    struct Node *Node = (struct Node*)malloc(sizeof(struct Node));
    if(!Node){
        printf("Heap overflow.\n");
        exit(0);
    }
    Node->data = data;
    Node->left = Node->right = NULL;
    return Node;
}

struct Node *insert(struct Node *root, int data){     //function for inserting nodes in a BST
    if(root == NULL){
        root = createNode(data);
    }
    else{
        if(data < root->data){
            root->left = insert(root->left, data);
        }   
        else if(data > root->data){
            root->right = insert(root->right, data);
        }
    }
    return root;
}

struct Node *createBST(int *arr, int n){     //function to generate the BST using insertion n times
    struct Node *root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

int greatestSmaller(struct Node *root, int data){   //function to find the greatest smaller to the left of each element of the array
    int output = 0;

    if(root->data == data){
        return output;
    }
    else{
        struct Node *temp = root;

        if(root->data < data){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }

        while(temp){
            if(temp->data < data){
                output = temp->data;
                temp = temp->right;
            }
            else{
                if(temp == root->right){
                    output = root->data;
                }
                return output;
            }
        }
        return output;
    } 
}

int main(){
    //input from the user
    int n;
    printf("Enter the number of elements of the array :");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array : ");
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    //creating BST from the given array
    struct Node *root = createBST(arr, n);

    //output the substituted values of the integer
    printf("Substitued values : ");
    for(int i =0; i<n; i++){
        printf("%d ",greatestSmaller(root,arr[i]));
    }

    return 0;
}