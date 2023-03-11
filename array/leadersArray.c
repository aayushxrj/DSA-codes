#include<stdio.h>

int main(){
    int n;
    printf("Number of elements : ");
    scanf("%d",&n);
    printf("Elements : ");
    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    // int arr[] = {16 ,20 ,10 ,5 ,18};
    int size = sizeof(arr) / sizeof(arr[0]);

    //logic1 - n^2
    // for(int i =0; i<size; i++){
    //     int big = arr[i];
    //     for(int j = i+1;j<size; j++){
    //         if(arr[j]>big){
    //             big = arr[j];
    //             break;
    //         }
    //     }
    //     if(big == arr[i]){
    //         printf("%d \t",arr[i]);
    //     }
    // } 
    //logic2 - n 
    int max = arr[n-1];
    printf("%d\t",max);
    for(int i = n-2;i>=0;i--){
        if(arr[i]>max){
            max = arr[i];
            printf("%d\t",max);
        }
    } 
    return 0;
}