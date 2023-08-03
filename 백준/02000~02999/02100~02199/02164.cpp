#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    queue<int> Q;
    int N, tmp, size;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        Q.push(i);
    }

    while(Q.size()>1) {
        Q.pop();
        Q.push(Q.front());
        Q.pop();
    }
    printf("%d\n", Q.front());
}