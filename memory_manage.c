#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// malloc
int* arr[5];

void heap(){
    for(int i=0; i<3; i++){
        arr[i] = (int*)malloc(sizeof(int));
        printf("heap\ti = %d\tis at %p\n", i, arr[i]);
    }

    for(int i=0; i<3; i++){
        free(arr[i]);
    }
}

// stack
void stack(int n){
    printf("stack\ti = %d\tis at %p\n",n,n);
    if(n >= 2){
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
long long* arr2[10000000];

void overflow(long long N){
    arr2[N] = (long long*)malloc(sizeof(long long)*100);
    printf("N = %lld\t%p\t%p\n", N, &N, arr2[N]);
    overflow(N+1);
}

int main(){
    char inp;
    printf("Overflow? (y/n) : ");
    scanf("%c", &inp);
    // printf("inp : %c\n", inp);
    if(inp == 'y'){
        overflow(0);
    }
    else{
        printf("G1 is at %p\n", &G1);
        printf("G2 is at %p\n", &G2);
        printf("G3 is at %p\n", &G3);
        heap();
        stack(0);
    }
}