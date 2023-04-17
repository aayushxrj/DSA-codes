#include<stdio.h>
#include<stdlib.h>

int main(){
    int *arr = (int*)malloc(10*sizeof(int));
    for(int i =0; i<10; i++){
        scanf("%d",(arr+i));
    }
    // now find the maxm
    int maxm = 0;
    for(int i =0; i<10; i++){
        if(*(arr+i)>=maxm){
            maxm = *(arr+i);
        }
    }
    printf("%d",maxm);
}