#include <stdio.h>

int main() {
    int input[5] = { 0, };
    int count;
    char result[5] = { 'D', 'C', 'B', 'A', 'E' };
    for (int i = 0; i < 3; i++) {
        count = 0;
        scanf("%d %d %d %d", &input[0], &input[1], &input[2], &input[3]);
        for (int j = 0; j < 4; j++) {
            if (input[j] == 1) {
                count++;
            }
        }
        printf("%c\n", result[count]);
    }
    return 0;
}
