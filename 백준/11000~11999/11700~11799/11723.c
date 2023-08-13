#include <stdio.h>
#include <string.h>

int main() {
    char command[10];

    int TC, X;
    int S = 0;

    scanf("%d", &TC);
    while(TC--) {
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%d", &X);
            S |= (1 << X);
        }

        else if (strcmp(command, "remove") == 0) {
            scanf("%d", &X);
            S &= ~(1 << X);
        }
        else if (strcmp(command, "check") == 0) {
            scanf("%d", &X);
            printf("%d\n", (S & (1 << X)) ? 1 : 0); 
        }
        else if (strcmp(command, "toggle") == 0) {
            scanf("%d", &X);
            if (S & (1 << X)) { 
                S &= ~(1 << X); 
            }
            else {             
                S |= (1 << X);    
            }
        }
        else if (strcmp(command, "all") == 0) {
            S = (1 << 21) - 1;
        }
        else if (strcmp(command, "empty") == 0) {
            S = 0;
        }
    }

    return 0;
}