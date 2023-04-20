#include<stdio.h>
#include<stdlib.h>
int findMax(int *arr,int n){
    int max = arr[0];
    for(int i =1 ;i <n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void countSort(int *A, int n){
    int max;
    int *count;
    max = findMax(A,n);
    count = (int*)malloc(sizeof(int)*(max+1));
    for(int i =0; i<=max;i++){
        count[i] = 0;
    }
    for(int i =0; i<n; i++){
        count[A[i]]++;
    }
    int i=0,j=0 ;
    while(j<=max){
        if(count[j]>0){
            A[i] = j;
            i++;
            count[j]--;
        }
        else{
            j++;
        }
    }

}

int main(){
    int arr[] = { 5, 3, 8, 4, 2 ,12, 20,0, 10 };
    int size = sizeof(arr) / sizeof(int);
    countSort(arr, size);
    //displaying sorted array
    for(int i =0; i<size;i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}