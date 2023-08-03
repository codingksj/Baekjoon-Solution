#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    queue<int> Q;
    char command[10];
    int TC;
    int N;
    bool empty;

    scanf("%d", &TC);

    while (TC--) {
        scanf("%s", command);
        empty = Q.empty();
        if (strcmp(command, "push") == 0) {
            scanf("%d", &N);
            Q.push(N);
        }
        else if (strcmp(command, "pop") == 0) {
            if (empty) {
                printf("-1\n");
            }
            else {
                printf("%d\n", Q.front());
                Q.pop();
            }
        }
        else if (strcmp(command, "size") == 0) {
            printf("%lu\n", Q.size());
        }
        else if (strcmp(command, "empty") == 0) {
            printf("%d\n", empty ? 1 : 0);
        }
        else if (strcmp(command, "front") == 0) {
            printf("%d\n", empty ? -1 : Q.front());
        }
        else if (strcmp(command, "back") == 0) {
            printf("%d\n", empty ? -1 : Q.back());
        }
    }
    return 0;
}