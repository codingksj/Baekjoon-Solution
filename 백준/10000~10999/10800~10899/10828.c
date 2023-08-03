#include<stdio.h>
#include<string.h>

void Push(int* size);
void Pop(int* size);
void Size(int* size);
void Empty(int* size);
void Top(int* size);

int stack[10001];

int main() {
    int N;
    int size = 0;
    char command[6];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", command);
        if (strcmp(command, "push") == 0) {
            Push(&size);
        }
        else if (strcmp(command, "pop") == 0) {
            Pop(&size);
        }
        else if (strcmp(command, "size") == 0) {
            Size(&size);
        }
        else if (strcmp(command, "empty") == 0) {
            Empty(&size);
        }
        else if (strcmp(command, "top") == 0) {
            Top(&size);
        }
    }
    return 0;
}

void Push(int* size) {
    int n;
    scanf("%d", &n);
    stack[*size] = n;
    *size = *size + 1;
}

void Pop(int* size) {
    if (*size == 0) {
        printf("-1\n");
    }
    else {
        printf("%d\n",stack[*size-1]);
        *size = *size - 1;
    }
}

void Size(int* size) {
    printf("%d\n", *size);
}

void Empty(int* size) {
    if (*size == 0) {
        printf("1\n");
    }
    else {
        printf("0\n");
    }
}

void Top(int* size) {
    if (*size == 0) {
        printf("-1\n");
    }
    else {
        printf("%d\n", stack[*size - 1]);
    }
}