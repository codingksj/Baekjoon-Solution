#include<iostream>
#include<deque>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
    int N, M, X;
    int pos;
    int left, right;
    int count;
    deque<int> DQ;

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N;i++) {
        DQ.push_back(i);
    }

    while(M--){
        scanf("%d", &X);
        for (int i = 0; i < DQ.size(); i++) {
            if (DQ[i] == X) {
                pos = i;
                break;
            }
        }
        right = pos;
        left = DQ.size() - pos;

        if (right < left) {
            count += right;
            while (DQ.front() != X) {
                DQ.push_back(DQ.front());
                DQ.pop_front();
            }
        }
        else {
            count += left;
            while (DQ.front() != X) {
                DQ.push_front(DQ.back());
                DQ.pop_back();
            }
        }
        DQ.pop_front();
    }
    printf("%d\n", count);
    return 0;
}