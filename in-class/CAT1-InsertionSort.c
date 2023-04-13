// INSERTION SORT ----------- C, A, Z, S, P, S

#include<stdio.h>

void insertionSort(char *arr, int n){
    for(int i = 1; i < n; i++){
        char key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        } 
        arr[j+1] = key;       
    }
}

int main(){
    char arr[] = {'C', 'A', 'Z', 'S', 'P', 'S','\0'};
    insertionSort(arr,6);
    printf("The array after sorting : ");
    for(int i =0; i<6; i++){
        printf("%c ",arr[i]);
    }    
    return 0;
}