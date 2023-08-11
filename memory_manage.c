#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// malloc
int* arr[5];

void heap(int stop){
    for(int i=1; i<stop+1; i++){
        arr[i-1] = (int*)malloc(sizeof(int));
        printf("heap\ti = %d\tis at %p\n", i, arr[i]);
    }

    for(int i=1; i<stop+1; i++){
        free(arr[i-1]);
    }
}

// stack
void stack(int start, int stop){
    printf("stack\ti = %d\tis at %p\n", start, &start);
    if(start >= stop){
        return;
    }
    else{
        stack(start+1, stop);
    }
}

// global var
int G1;
int G2;
int G3 = 10;

//overflows
void overflow(long long N){
    long long arr[1024];
    printf("stack\ti = %lld\tis at %p\n",N,arr);
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
        printf("Global variables 1 is at %p\n", &G1);
        printf("Global variables 2 is at %p\n", &G2);
        printf("Global variables 3 is at %p\n\n", &G3);
        heap(5);
        printf("\n");
        stack(1,5);
    }
}