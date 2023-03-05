#include<stdio.h>

int main(){
    int arr[5] = {1,2,3,4,5};
    int n = 5;
    int p;
    scanf("%d",&p) ;

    //logic1 - n^2 time complexity
    while (p--){
        int temp = arr[0];
        for(int i = 0;i<n-1;i++) {
            arr[i] = arr[i+1];
        }
        arr[n-1] = temp;
    }
    for(int i =0;i<n;i++) {
        printf("%d\t",arr[i]);
    }

    //logic2 - n time complexity

    return 0;

}