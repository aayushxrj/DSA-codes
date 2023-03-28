#include<stdio.h>

// void bubbleSort(int *arr, int n){
//     for(int i = 0; i<n-1; i++){
//         for(int j =0; j<n-i-1; j++){
//             if(arr[j] > arr[j+1]){
//                 int temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }        
//     }
// }

//improved version
void bubbleSort(int *arr, int n){
    for(int i = 0; i<n-1; i++){
        int swapped = 0;
        for(int j =0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }   
        if(swapped == 0){
            break;
        }     
    }
}

int main(){
    int arr[] = { 5, 3, 8, 4, 2 ,12, 69,0, 10 };
    int size = sizeof(arr) / sizeof(int);
    bubbleSort(arr, size);
    //displaying sorted array
    for(int i =0; i<size;i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}