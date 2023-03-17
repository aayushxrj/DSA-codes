#include<stdio.h>

// ITERATIVE METHOD -- only time n and space is O(1)
int linearsearch(int arr[],int size, int el){
    int pos = -1 ;
    int condn = 0;
    for(int i =0; i<size;i++){
        if(arr[i]== el){
            printf("Position : %d\n",i);
            condn = 1;
        }
    }
    if(!condn){
        printf("Element is not present.");
    }
    return pos;
}

//RECURSIVE METHOD --- time and space both n

// int linearsearch(int arr[], int size, int key){
//     if(size == 0){
//         return -1;
//     }  
//     if(arr[size-1] == key){
//         return size-1;
//     }
//     else{
//         linearsearch(arr,size-1,key);
//     }
// }

int main(){
    int n;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    int arr[n];
    for(int i =0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Element to be seached :");
    int key;
    scanf("%d",&key);
    printf("%d",linearsearch(arr,n,key));
    return 0;
}
