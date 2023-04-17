#include<stdio.h>

int main(){
    int *p;
    char *q;
    float *r;
    double *s;
    printf("%d\n", sizeof(p));
    printf("%lu\n", sizeof(q));
    printf("%d\n", sizeof(r));
    printf("%d\n", sizeof(s));
    return 0;
    
}