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
int f1(int a, int b){
    return (a>b?a:b);

}
int main(){
    f1(10,9);
}