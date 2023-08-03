#include<stdio.h>
#include<string.h>

int stack[100001];

void GetSum(int stack[], int* size, int* sum){
    for(int i=0;i<*size;i++){
        *sum += stack[i];
    }
}

int main() {
    int N;
    int input;
    
    int size = 0;
    int sum = 0;
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &input);
        if(input == 0){
            stack[size] = 0;
            size--;
        }
        else{
            stack[size] = input;
            size++;
        }
    }
    GetSum(stack, &size, &sum);
    printf("%d",sum);
    return 0;
}

