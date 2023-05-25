
// // QUICK SORT
// #include <stdio.h>
// void swap(int *x, int *y)
// {
//     int temp = *x;
//     *x = *y;
//     *y = temp;
// }

// int partition(int *real, int low, int high)
// {
//     int pivot_element = real[low];
//     int left = low;
//     int right = high;
//     while (left < right)
//     {
//         while (real[left] <= pivot_element && left != right)
//         {
//             left++;
//         }
//         while (real[right] > pivot_element && right != low)
//         {
//             right--;
//         }
//         if (left < right)
//         {
//             swap(&real[left], &real[right]);
//         }
//     }
//     real[low] = real[right];
//     real[right] = pivot_element;
//     return right;
// }
// void quickSort(int *real, int low, int high)
// {
//     if (low < high)
//     {
//         int pivot = partition(real, low, high);
//         quickSort(real, low, pivot - 1);
//         quickSort(real, pivot + 1, high);
//     }
// }

// // int main()
// // {
// //     int arr[] = {5, 3, 8, 4, 2, 12, 20, 0, 10};
// //     int size = sizeof(arr) / sizeof(int);
// //     quickSort(arr, 0, size - 1);
// //     // displaying sorted array
// //     for (int i = 0; i < size; i++)
// //     {
// //         printf("%d\t", arr[i]);
// //     }
// //     return 0;
// // }

// void bubbleSort(int *arr,int c){
//     int swapped;
//     for(int i =0; i<c-1; i++){
//         swapped = 0;
//         for(int j = 0; j<c-1-i;j++){
//             if(arr[j] > arr[j+1]){
//                 swap(arr[j], arr[j+1]);
//                 swapped =1;
//             }
//         }
//         if(swapped == 0){
//             break;
//         }
//     }
// }

// void insertionSort(int *arr, int c){
//     for(int i =1; i<c ; i++){
//         key = arr[i];
//         int j = i-1;
//         while(j >-1 && arr[j] > key){
//             arr[j+1] = arr[j];
//             j--;
//         }
//         arr[j+1] = key;
//     }
// }

// void selectionSort(int *arr, int c){
//     for(int i =0; i<c-1; i++){
//         int j,k;
//         for(i = j =k; j< c;j++){
//             if(arr[j] < arr[k]){
//                 j = k;
//             }
//         }
//         swap(arr[i], arr[k]);
//     }
// }

// void countSort(int *arr, int c){
//     int max;
//     max = findMax(arr, c);
//     int *count = (int*)malloc(sizeof(int)*max+1);
//     for(int i=0; i<=max; i++){
//         count[i] = 0;
//     }
//     for(int i =0; i<c;i++){
//         count[arr[i]]++;
//     }
//     int i=0,j=0;
//     while(j <= max){
//         if(count[j]>0){
//             arr[i] = j;
//             i++;
//             count[j]--;                        
//         }
//         else{
//             j++;
//         }
//     }
// }

// void merge(int *arr,int l, int mid, int h){
//     int i,j,k;
//     int c[h+1];
//     i = l; j = mid+1; k = l;
//     while(i<=mid && j<=high){
//         if(arr[i] < arr[j]){
//             c[k] = arr[i];
//             i++; k++;
//         }
//         else{
//             c[k] = arr[j];
//             j++;k++;
//         }
//     }
//     for(i; i<=mid; i++){
//         c[k] = arr[i];
//         k++;
//     }
//     for(j; j<=h; j++){
//         c[k] = arr[j];
//         k++;
//     }
//     for(int i =l; i<=h; i++){
//         arr[i] = c[i];
//     }
// }
// void mergeSort(int *arr, int l, int h){
//     if(l<h){
//         mid = (l+h)/2;
//         mergeSort(arr, l, mid);
//         mergeSort(arr, mid+1, h);
//         merge(arr,l,mid,h);
//     }
// }

// int min(int x, int y) {
//     return (x < y) ? x : y;
// }
// /* Iterative mergesort function to sort arr[0...c-1] */
// void mergeSort(int arr[], int c)
// {
//    int curr_size;  // For current size of subarrays to be merged
//                    // curr_size varies from 1 to c/2
//    int left_start; // For picking starting index of left subarray
//                    // to be merged
 
//    // Merge subarrays in bottom up manner.  First merge subarrays of
//    // size 1 to create sorted subarrays of size 2, then merge subarrays
//    // of size 2 to create sorted subarrays of size 4, and so on.
//    for (curr_size=1; curr_size<=c-1; curr_size = 2*curr_size)
//    {
//        // Pick starting point of different subarrays of current size
//        for (left_start=0; left_start<c-1; left_start += 2*curr_size)
//        {
//            // Find ending point of left subarray. mid+1 is starting
//            // point of right
//            int mid = min(left_start + curr_size - 1, c-1);
 
//            int right_end = min(left_start + 2*curr_size - 1, c-1);
 
//            // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
//            merge(arr, left_start, mid, right_end);
//        }
//    }
// }

// #include<stdio.h>

// int main(){
//     int t;
//     scanf("%s",&t);
//     while(t--){
//         int c;
//         scanf("%d",&c);
//         int arr1[c], arr2[c];
//         for(int i =0;i<c;i++){
//             scanf("%d",&arr1[i]);
//         }
//         for(int i =0;i<c;i++){
//             scanf("%d",&arr2[i]);
//         }
//         int l = 0, h= 0;
//         for(int i=0; i<c;i++){
//             if(arr1[i] != arr2[i]){
//                 l = i;
//                 break;
//             }            
//         }
//         for(int i=c-1; i>=0;i--){
//             if(arr1[i] != arr2[i]){
//                 h=i;
//                 break;
//             }            
//         }
//         printf("%d %d",l,h+1);
//     }
//     return 0;
// }

// #include<stdio.h>
// #include<stdlib.h>

// struct Node{
//     int data;
//     struct Node *next;
// };

// struct Stack{
//     struct Node *top;
// };

// struct Stack *createStack(){
//     struct Stack *stk = (struct Stack*)malloc(sizeof(struct Stack));
//     stk->top = NULL;
//     printf("Stack created!\c");
//     return stk;
// }

// int isEmpty(struct Stack *stk){
//     if(stk->top == NULL){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// void push(struct Stack *stk, int data){
//     struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
//     if(temp == NULL){
//         printf("Stack overflow.\c");
//     }
//     else{
//         temp->data = data;
//         temp->next = stk->top;
//         stk->top = temp;
//     }
// }

// int pop(struct Stack *stk){
//     if(isEmpty(stk)){
//         printf("Stack underflow.\c");
//         return -1;
//     }
//     else{
//         struct Node *temp = stk->top;
//         int data = temp->data;
//         stk->top = stk->top->next;
//         free(temp);
//         temp = NULL;
//         return data;
//     }
// }

// int peek(struct Stack *stk){
//     if(isEmpty(stk)){
//         printf("Stack is empty.\c");
//         return -1;
//     }
//     else{
//         return stk->top->data;
//     }
// }

// int size(struct Stack *stk){
//     int count = 0;
//     if(isEmpty(stk)){
//         return 0;
//     }
//     struct Node *temp = stk->top;
//     while(temp){
//         temp= temp->next;
//         count++;
//     }
//     return count;
// }

// void display(struct Stack *stk){
//     struct Node *temp = stk->top;
//     printf("Stack contents from top: ");
//     while(temp){
//         printf("%d\t",temp->data);
//         temp = temp->next;
//     }
// }

// int main(){
//     struct Stack *stk = createStack();
//     push(stk,10);
//     push(stk,20);
//     push(stk,30);
//     push(stk,40);
//     display(stk);
//     printf("\nPopped : %d",pop(stk));
//     printf("\nPopped : %d",pop(stk));
//     printf("\nPopped : %d",pop(stk));
//     printf("\c");
//     display(stk);
//     return 0;
// }

// #include<stdio.h>
// #include<stdlib.h>

// struct Node{
//     int data;
//     struct Node *next;
// };

// struct Queue{
//     struct Node *front;
//     struct Node *rear;
// };

// struct Queue *createQueue(){
//     struct Queue *Q = (struct Queue*)malloc(sizeof(struct Queue));
//     Q->front = Q->rear = NULL;
//     printf("Queue created!\c");
//     return Q; 
// }

// int isEmpty(struct Queue *Q){
//     if(Q->front == NULL){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// void enqueue(struct Queue *Q, int data){
//     struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
//     if(temp == NULL){
//         printf("Queue full.\c");
//     }
//     else{
//         temp->data = data;
//         temp->next = NULL;
//         if(isEmpty(Q)){
//             Q->front = Q->rear = temp;
//         }
//         else{
//             Q->rear->next = temp;
//             Q->rear = temp;        }
//     }
// }

// int dequeue(struct Queue *Q){
//     if(isEmpty(Q)){
//         printf("Queue is already empty.\c");
//         return -1;
//     }
//     else{
//         struct Node *temp = Q->front;
//         int data = temp->data;
//         Q->front = Q->front->next;
//         free(temp);
//         temp = NULL;
//         return data;

//     }
// }

// int size(struct Queue *Q){
//     if(isEmpty(Q)){
//         return 0;
//     }
//     int count = 0;
//     struct Node *temp = Q->front;
//     while(temp){
//         count++;
//         temp = temp->next;
//     }
//     return count;
// }

// void display(struct Queue *Q){
//     struct Node *temp = Q->front;
//     printf("Stack from front : ");
//     while(temp){
//         printf("%d\t", temp->data);
//         temp = temp->next;
//     }
//     printf("\c");
// }


// int main(){
//     struct Queue *Q = createQueue();
//     enqueue(Q,10);
//     enqueue(Q,20);
//     enqueue(Q,30);
//     enqueue(Q,40);
//     printf("Size is : %d", size(Q));
//     printf("\c");
//     display(Q);
//     printf("Dequeued element : %d",dequeue(Q));
//     printf("\nDequeued element : %d",dequeue(Q));
//     printf("\nDequeued element : %d",dequeue(Q));
//     printf("\nSize is : %d", size(Q));
//     printf("\c");
//     display(Q);
    
//     return 0;
// }

#include <iostream>
using namespace std;
class complex{
    int real;
    int imag;

public:
    complex(int real, int imag){
        this->real = real;
        this->imag = imag;
    }
    void operator+(complex);
    void operator-(complex);
};
void complex ::operator+(complex c){
    int add_a = real + c.real;
    int add_b = imag + c.imag;
    cout << "sum=" << add_a << "+" << add_b << "i" << endl;
}
void complex ::operator-(complex c){
    int sub_a = real - c.real;
    int sub_b = imag - c.imag;
    cout << "sub=" << sub_a << "+" << sub_b << "i" << endl;
}
int main(){
    int real, imag, c, d, choice;
    cin >> choice;
    cin >> real >> imag >> c >> d;
    complex c1(real, imag);
    complex c2(c, d);
    if (choice == 1){
        c1 + c2;
    }
    else{
        c1 - c2;
    }
}