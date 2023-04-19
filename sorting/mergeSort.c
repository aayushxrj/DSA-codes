#include<stdio.h>

void Merge(int *A, int*B, int m, int n){       // WHEN  TWO SEPERATE LISTS ARE PRESENT
    int i, j, k;
    i = j = k =0;
    int C[m+n];
    while(i <m && j<n){
        if(A[i] < B[i]){
            C[k] = A[i];
            k++;
            i++;
        }
        else{
            C[k] = B[i];
            k++
            j++;
        }
    }
    for(i, i<m; i++){
        C[k] = A[i];
        k++;
    }
    for(j, j<n; i++){
        C[k] = B[j];
        k++;
    }
}

void Merge(int *A, int l, int mid, int h){                     // WHEN DIVIDING A SINGLE LIST IN TWO HALFS
    int i, j, k;
    i = l; j = mid+1; k =l;
    int C[h+1];
    while(i <= mid && j <= h){
        if(A[i] < A[j]){
            C[k] = A[i];
            k++; i++;
        }
        else{
            C[k] = A[j];
            k++; j++;
        }
    }
    for(i; i<= mid; i++){
        C[k] = A[i];
        k++;
    }
    for(j; j<=h; j++){
        C[k] = A[j];
        k++;
    }
    for(int i=l; i<=h; i++){
        A[i] = C[i];
    }
}

//recursive method
void MergeSort(int *A, int l, int h){
    if(l<h){
        int mid;
        mid =  (l+h)/2;
        MergeSort(A,l,mid); 
        MergeSort(A,mid+1,h); 
        Merge(A,l,mid,h); 
    }
}

//iterative method


int main(){
    int arr[] = { 5, 3, 8, 4, 2 ,12, 20,0, 10 };
    int size = sizeof(arr) / sizeof(int);
    MergeSort(arr, 0,size-1);
    //displaying sorted array
    for(int i =0; i<size;i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}