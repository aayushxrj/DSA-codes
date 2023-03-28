#include<stdio.h>


void selectionSort(int *arr, int n){
    int i,j,k;
    for(i=0; i<n-1;i++){
        for(j = k = i; j<n; j++){
            if(arr[j]<arr[k]){
                k = j;
            }
        }
        // swap(arr[i],arr[k]);
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }    
}

int main(){
    int arr[] = { 5, 3, 8, 4, 2 };
    int size = sizeof(arr) / sizeof(int);
    selectionSort(arr, size);
    //displaying sorted array
    for(int i =0; i<size;i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}