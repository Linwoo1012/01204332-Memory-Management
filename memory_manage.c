#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// malloc
int* arr[5];

void heap(int stop){
    for(int i=1; i<stop+1; i++){
        arr[i-1] = (int*)malloc(sizeof(int));
        printf("heap\ti = %d\tis at %p\n", i, arr[i-1]);
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
int uG1;
int uG2;
int G1 = 10;
int G2 = 10;

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
        printf("\nUninitialized data\n");
        printf("uG1 is at %p\n", &uG1);
        printf("uG2 is at %p\n", &uG2);
        printf("\nInitialized data\n");
        printf("G1 is at %p\n", &G1);
        printf("G2 is at %p\n\n", &G2);
        heap(5);
        printf("\n");
        stack(1,5);
    }
}