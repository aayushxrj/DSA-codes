// SEARCH FOR CHARACTER GIVEN BY USER
// C, A, Z, S, P, S, R, T

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

int binarySearch(char *arr, int size, char key){
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

int main(){
    char arr[] = {'C', 'A', 'Z', 'S', 'P', 'S', 'R', 'T','\0'};
    insertionSort(arr,8);
    char key;
    printf("Character want to be searched : ");
    scanf("%c",&key);
    printf("The character is preset at the position : %d",binarySearch(arr,8, key));
    return 0;
}