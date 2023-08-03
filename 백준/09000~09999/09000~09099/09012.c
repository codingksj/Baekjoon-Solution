#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, i, count;
    char input[51];

    scanf("%d", &N);
    while (N--) {
        count = 0;
        scanf("%s", input);

        for (i = 0; i < strlen(input); i++) {
            if (input[i] == '(') {
                count++;
            }
            else if (input[i] == ')') {
                if (count == 0) {
                    break;
                }
                else {
                    count--;
                }
            }
        }
        if (i != strlen(input) || count != 0) {
            printf("NO\n");
        }
        else {
            printf("YES\n");
        }
    }
    return 0;
}