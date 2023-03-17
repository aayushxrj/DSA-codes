// solve this on leetcode too
#include<stdio.h>

void spiral(int r, int c, int arr[r][c]){
    int left = 0, top = 0,right = c-1,bottom = r-1;
    while(left<=right && top<=bottom){
        //print first row
        for(int i = 0; i<=right;i++){
            printf("%d\t",arr[top][i]);
        }
        top++;
        //printf last column
        for(int i = top; i<=bottom;i++){
            printf("%d\t",arr[i][right]);
        }
        right--;
        // print last row
        if(top<=bottom){
            for(int i = right;i>=left;i--){
                printf("%d\t",arr[bottom][i]);
            }
        }
        //print first column
        if (left <= right) { 
            for (int i = bottom; i >= top; i--) {
                printf("%d ", arr[i][left]);
        }
        left++;
        }
    }  
}
int main(){
    int m, n;
    scanf("%d%d",&m,&n);
    int arr[m][n];
    for(int i =0;i<m;i++){
        for(int j =0; j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    spiral(m,n,arr);        
    return 0;
}