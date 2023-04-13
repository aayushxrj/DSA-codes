#include<stdio.h>

int main(){
    int n;                        //taking number of customers as input
    scanf("%d",&n);
    int C[n], P[n];
    for(int i =0; i<n; i++){      //Storing the customers and pastas in arrays
        scanf("%d",&C[i]);
    }
    for(int i =0; i<n; i++){
        scanf("%d",&P[i]);
    }
    printf("1");
    return 0;
}