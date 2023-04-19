#include<stdio.h>

int partition(int *A,int low, int high){
    int pivot_item = A[low];
    int left= low;
    int right = high;
    while(left<right){
        while(A[left] <= pivot_item && left!= high){
            left++;
        }
        while(A[right] > pivot_item){
            right--;
        }
        if(left<right){
            swap(A[left],A[right]);
        }
    }
    A[low] = A[right];
    A[right] = pivot_item;
    return right;
}

void quickSort(int *A, int low, int high){
    if(low < high){
        int pivot = partition(A,low high);
        quickSort(A,low,pivot-1);
        quickSort(A,pivot+1,high);
    }
}


int main(){
    int arr[] = { 5, 3, 8, 4, 2 ,12, 20,0, 10 };
    int size = sizeof(arr) / sizeof(int);
    quickSort(arr, size);
    //displaying sorted array
    for(int i =0; i<size;i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}