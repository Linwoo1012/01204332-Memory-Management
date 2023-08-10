#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// malloc
int* arr[5];

void heap(){
    for(int i=0; i<3; i++){
        arr[i] = (int*)malloc(sizeof(int));
        printf("i = %d is at %p\n", i, arr[i]);
    }

    for(int i=0; i<3; i++){
        free(arr[i]);
    }
}

// stack
void stack(int n){
    printf("stack : %p\n",n);
    if(n >= 3){
        return;
    }
    else{
        stack(n+1);
    }
}

// global var
int G1;
int G2;
int G3 = 10;

//overflows
long long* arr2[5];

void overflow(long long N){
    printf("stack N = %lld is at %p\n", N, &N);
    arr2[N] = (long long*)malloc(sizeof(long long));
    printf("heap N = %lld is at %p\n", N, arr2[N]);
    overflow(N+1);
}

int main(){
    char inp;
    scanf("Overflow? (y/n) : %c", &inp);
    if(inp == 'y'){
        overflow(0);
    }
    else{
        heap();
        stack(0);
    }
}