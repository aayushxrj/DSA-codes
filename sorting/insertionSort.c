#include<stdio.h>


//using while loop
void insertionSort(int *arr, int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j --;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int arr[] = { 5, 3, 8, 4, 2 };
    int size = sizeof(arr) / sizeof(int);
    insertionSort(arr, size);
    //displaying sorted array
    for(int i =0; i<size;i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}