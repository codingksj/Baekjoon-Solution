#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_ {
    char stack[101];
    int size;
}Stack;

void Push(Stack* stk, char input) {
    stk->stack[stk->size] = input;
    stk->size++;
}

int Pop(Stack* stk) {
    if (stk->size == 0) {
        return -1;
    }
    stk->size--;
    return 1;
}

int Top(Stack* stk) {
    if (stk->size > 0) {
        return stk->stack[stk->size - 1];
    }
    else {
        return -1;
    }
}
int main() {
    int i;
    char input[101];
    Stack stk;

    while (1) {
        stk.size = 0;
        scanf("%[^\n]s", input);
        getchar();
        if (strcmp(input, ".") == 0) {
            break;
        }
        for (i = 0; i < strlen(input); i++) {
            if (input[i] == '(' || input[i] == '[') {
                Push(&stk, input[i]);
            } 
            else if (input[i] == ')') {
                if (Top(&stk) != '(') {
                    break;
                }
                else {
                    Pop(&stk);
                }
            }
            else if (input[i] == ']') {
                if (Top(&stk) != '[') {
                    break;
                }
                else {
                    Pop(&stk);
                }
            }
        }
        if (i != strlen(input) || stk.size != 0) {
            printf("no\n");
        }
        else {
            printf("yes\n");
        }

    }
    return 0;
}