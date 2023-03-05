#include<stdio.h>
//logic1 - n^2 runtime complexity
// void rotate(int* nums, int numsSize, int k){
//     while(k--){
//         int temp = nums[numsSize-1];
//         for(int i = numsSize-2;i>=0;i--) {
//             nums[i+1] = nums[i];
//         }
//         nums[0] = temp;
//     }
// }

//logic2 - n time complexity

void rotate(int* nums, int numsSize, int k){
    int nums2[numsSize+k];
   //nums2 is ready 
    for(int i=numsSize+k-1;i>=k;i--){
        nums2[i] = nums[i-2];
    }
    //print
    // for(int i =0;i<numsSize+k;i++){
    //     printf("%d\t",nums2[i]);
    // }
    // printf("\n");

    //now update nums with new values ?? 
    for(int i= 0;i<k;i++){
        nums[i] = nums2[numsSize+i];
    }
    //error is here
    for(int i = k;i<numsSize;i++){
        nums[i] = nums2[i];
    }
    //print
    for(int i =0;i<numsSize;i++){
        printf("%d\t",nums[i]);
    }
}

int main(){
    int nums[] ={1,2,3,4,5};
    int k = 4;
    int numsSize = 5;
    rotate(nums,5,2); 
    return 0;
}

