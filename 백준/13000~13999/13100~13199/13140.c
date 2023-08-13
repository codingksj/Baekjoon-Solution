#include <stdio.h>
#include <stdbool.h>
#include <memory.h>

int main(){
    bool flag;
    int h, e, l, o, w, r, d;
    int hello, world;
    int answer;
    int checkdigit[10] = { 0, };
    scanf("%d", &answer);
    for (h = 1; h < 10; h++) {
        for (e = 0; e < 10; e++) {
            for (l = 0; l < 10; l++) {
                for (o = 0; o < 10; o++) {
                    for (w = 1; w < 10; w++) {
                        for (r = 0; r < 10; r++) {
                            for (d = 0; d < 10; d++) {
                                memset(checkdigit, 0, sizeof(int)*10);
                                hello = 10000 * h + 1000 * e + 100 * l + 10 * l + o;
                                world = 10000 * w + 1000 * o + 100 * r + 10 * l + d;
                                if (answer == hello + world) {
                                    flag = true;
                                    checkdigit[h]++;
                                    checkdigit[e]++;
                                    checkdigit[l]++;
                                    checkdigit[o]++;
                                    checkdigit[w]++;
                                    checkdigit[r]++;
                                    checkdigit[d]++;
                                    for (int i = 0; i < 10; i++) {
                                        if (checkdigit[i] > 1) {
                                            flag = false;
                                        }
                                    }
                                    if (!flag) {
                                        break;
                                    }
                                    printf("  %d\n", hello);
                                    printf("+ %d\n", world);
                                    printf("-------\n");
                                    if (answer >= 100000) {
                                        printf(" %d\n", answer);
                                    }
                                    else {
                                        printf("  %d\n", answer);
                                    }
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    printf("No Answer\n");
    return 0;
}