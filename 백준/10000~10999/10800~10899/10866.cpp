#include <iostream>
#include <cstring>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    deque<int> DQ;
    char command[12];
    int TC;
    int N;
    bool empty;

    scanf("%d", &TC);

    while (TC--) {
        scanf("%s", command);
        empty = DQ.empty();
        if (strcmp(command, "push_back") == 0) {
            scanf("%d", &N);
            DQ.push_back(N);
        }
        else if (strcmp(command, "push_front") == 0) {
            scanf("%d", &N);
            DQ.push_front(N);
        }
        else if (strcmp(command, "pop_back") == 0) {
            if (empty) {
                printf("-1\n");
            }
            else {
                printf("%d\n", DQ.back());
                DQ.pop_back();
            }
        }
        else if (strcmp(command, "pop_front") == 0) {
            if (empty) {
                printf("-1\n");
            }
            else {
                printf("%d\n", DQ.front());
                DQ.pop_front();
            }
        }
        else if (strcmp(command, "size") == 0) {
            printf("%lu\n", DQ.size());
        }
        else if (strcmp(command, "empty") == 0) {
            printf("%d\n", empty);
        }
        else if (strcmp(command, "front") == 0) {
            printf("%d\n", empty ? -1 : DQ.front());
        }
        else if (strcmp(command, "back") == 0) {
            printf("%d\n", empty ? -1 : DQ.back());
        }
    }
    return 0;
}
