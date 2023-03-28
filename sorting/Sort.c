#include<stdio.h>

// void swap(int *arr,int x, int y){
//     int temp = arr[x];
//     arr[x] = arr[y];
//     arr[y] = temp;    
// }

void Sort(int *arr,int size){
    //logic
    for(int i = 0;i<size; i++){
        for(int j =i+1; j<size; j++){
            if(arr[i] > arr[j]){ // > for ascending
                // swap(arr,i,j);
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;                  
            }
        }
    }
}

int main(){
    int arr[] = { 5, 3, 8, 4, 2 }; 
    int size = sizeof(arr) / sizeof(int);
    Sort(arr, size);
    //displaying sorted array
    for(int i =0; i<size;i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}