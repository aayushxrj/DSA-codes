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
    k = k%numsSize;
    int* nums2 = (int*)malloc((numsSize+k) * sizeof(int));
    // int nums2[numsSize+k]; 
    //nums2 is ready 
    for(int i=numsSize+k-1;i>=k;i--){
        nums2[i] = nums[i-k];
    }
    //now update nums with new values ?? 
    for(int i= 0;i<k;i++){
        nums[i] = nums2[numsSize+i];
    }
    for(int i = numsSize-1;i>=k;i--){
        nums[i] = nums2[i];
    }
}

int main(){
    int nums[] ={1,2,3,4,5};
    rotate(nums,5,3); 
    return 0;
}

