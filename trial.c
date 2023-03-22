#include<stdio.h>

// char display(char arr[]){
//     for (int i =0; arr[i]!= '\0'; i++) {
//         if(arr[i] != '/' && arr[i] != '*'&& arr[i] != '+' && arr[i] != '-'){
//             printf("%c",arr[i]);
//         }           
//     }
// }
// int main(){
//     char arr[] = "A*(B+C)";
//     display(arr);

// }
// int f1(int a, int b){
//     return (a>b?a:b);

// }
int square(int *x){ // *(&x) = x
    *x = *x*(*x);
    return *x;

}
int main(){
    // int age = 20; // age = 2000
    // int *ptr; // * = value at address  // & = address of
    // ptr = &age;
    // printf("%d",*ptr);
    // printf("%d",age) ; 
    int x = 10;
    printf("%d\n",x);
    printf("%d\n",square(&x));
    printf("%d\n",x);
    }