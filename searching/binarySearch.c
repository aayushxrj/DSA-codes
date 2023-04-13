/* Binary Search Algorithm: The basic steps to perform Binary Search are:

Sort the array in ascending order.
Set the low index to the first element of the array and the high index to the last element.
Set the middle index to the average of the low and high indices.
If the element at the middle index is the target element, return the middle index.
If the target element is less than the element at the middle index, set the high index to the middle index – 1.
If the target element is greater than the element at the middle index, set the low index to the middle index + 1.
Repeat steps 3-6 until the element is found or it is clear that the element is not present in the array. */

#include<stdio.h>

// ITERATIVE METHOD
int binarysearch(int arr[], int size, int key){
    //after sorting
    int low = 0, high =size-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==key){
            return mid;
        } 
        else if(key>arr[mid]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

// RECURSIVE METHOD
// int binarysearch(int arr[], int low,int high, int key){
//     while(low<=high){
//         int mid = (high+low)/2;
//         if(arr[mid] == key){
//             return mid;
//         }
//         else if(arr[mid]<key){
//             return binarysearch(arr,mid+1,high,key);
//         }
//         else{
//             return binarysearch(arr,low,mid-1,key);
//         }
//     }
//     return -1;
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
    // printf("%d",binarysearch(arr,n,key));
    printf("%d",binarysearch(arr,0,n-1,key));

    return 0;
}