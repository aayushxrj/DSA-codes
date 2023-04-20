
// QUICK SORT
#include <stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int *A, int low, int high)
{
    int pivot_element = A[low];
    int left = low;
    int right = high;
    while (left < right)
    {
        while (A[left] <= pivot_element && left != right)
        {
            left++;
        }
        while (A[right] > pivot_element && right != low)
        {
            right--;
        }
        if (left < right)
        {
            swap(&A[left], &A[right]);
        }
    }
    A[low] = A[right];
    A[right] = pivot_element;
    return right;
}
void quickSort(int *A, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(A, low, high);
        quickSort(A, low, pivot - 1);
        quickSort(A, pivot + 1, high);
    }
}

// int main()
// {
//     int arr[] = {5, 3, 8, 4, 2, 12, 20, 0, 10};
//     int size = sizeof(arr) / sizeof(int);
//     quickSort(arr, 0, size - 1);
//     // displaying sorted array
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d\t", arr[i]);
//     }
//     return 0;
// }

void bubbleSort(int *arr,int n){
    int swapped;
    for(int i =0; i<n-1; i++){
        swapped = 0;
        for(int j = 0; j<n-1-i;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped =1;
            }
        }
        if(swapped == 0){
            break;
        }
    }
}

void insertionSort(int *arr, int n){
    for(int i =1; i<n ; i++){
        key = arr[i];
        int j = i-1;
        while(j >-1 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void selectionSort(int *arr, int n){
    for(int i =0; i<n-1; i++){
        int j,k;
        for(i = j =k; j< n;j++){
            if(arr[j] < arr[k]){
                j = k;
            }
        }
        swap(arr[i], arr[k]);
    }
}

void countSort(int *arr, int n){
    int max;
    max = findMax(arr, n);
    int *count = (int*)malloc(sizeof(int)*max+1);
    for(int i=0; i<=max; i++){
        count[i] = 0;
    }
    for(int i =0; i<n;i++){
        count[arr[i]]++;
    }
    int i=0,j=0;
    while(j <= max){
        if(count[j]>0){
            arr[i] = j;
            i++;
            count[j]--;                        
        }
        else{
            j++;
        }
    }
}

void merge(int *arr,int l, int mid, int h){
    int i,j,k;
    int c[h+1];
    i = l; j = mid+1; k = l;
    while(i<=mid && j<=high){
        if(arr[i] < arr[j]){
            c[k] = arr[i];
            i++; k++;
        }
        else{
            c[k] = arr[j];
            j++;k++;
        }
    }
    for(i; i<=mid; i++){
        c[k] = arr[i];
        k++;
    }
    for(j; j<=h; j++){
        c[k] = arr[j];
        k++;
    }
    for(int i =l; i<=h; i++){
        arr[i] = c[i];
    }
}
void mergeSort(int *arr, int l, int h){
    if(l<h){
        mid = (l+h)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, h);
        merge(arr,l,mid,h);
    }
}

int min(int x, int y) {
    return (x < y) ? x : y;
}
/* Iterative mergesort function to sort arr[0...n-1] */
void mergeSort(int arr[], int n)
{
   int curr_size;  // For current size of subarrays to be merged
                   // curr_size varies from 1 to n/2
   int left_start; // For picking starting index of left subarray
                   // to be merged
 
   // Merge subarrays in bottom up manner.  First merge subarrays of
   // size 1 to create sorted subarrays of size 2, then merge subarrays
   // of size 2 to create sorted subarrays of size 4, and so on.
   for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
   {
       // Pick starting point of different subarrays of current size
       for (left_start=0; left_start<n-1; left_start += 2*curr_size)
       {
           // Find ending point of left subarray. mid+1 is starting
           // point of right
           int mid = min(left_start + curr_size - 1, n-1);
 
           int right_end = min(left_start + 2*curr_size - 1, n-1);
 
           // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
           merge(arr, left_start, mid, right_end);
       }
   }
}