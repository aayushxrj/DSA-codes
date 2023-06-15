//linear and binary search
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int linearSearch(int *arr, int n, int key){
    for(int i =0; i<n; i++){
        if(arr[i]==key){
            return i;
        }
    }
}

int binarySearch(int *arr,int n, int key){
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if (arr[mid] > key){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,24,65,87,23, 56};
    int n = sizeof(arr)/sizeof(int);
    int key = 23;
    printf("%d", linearSearch(arr,n,key));
    return 0;
}