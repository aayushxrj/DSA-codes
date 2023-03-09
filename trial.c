#include<stdio.h>


char display(char arr[]){
    for (int i =0; arr[i]!= '\0'; i++) {
        if(arr[i] != '/' && arr[i] != '*'&& arr[i] != '+' && arr[i] != '-'){
            printf("%c",arr[i]);
        }           
    }
}
int main(){
    char arr[] = "A*(B+C)";
    display(arr);

}