#include <stdio.h>
#include <stdlib.h>

int main() {
    int command;
    int curPos;
    char position[4] = {'N','E','S','W'};
    for (int t = 1; t <= 10; t++) {
        scanf("%d", &command);
        switch (command) {
        case 1: 
            curPos += 1;
            break;
        case 2:
            curPos += 2;
            break;
        case 3:
            curPos -= 1;
            break;
        }
        if (curPos < 0) {
            curPos += 4;
        }
    }
    curPos %= 4;
    printf("%c\n", position[curPos]);
    return 0;
}