#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    set<int> A, B;
    set<int> diffAB, diffBA;
    
    int num;
    long result;

    int N, M;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        A.insert(num);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d", &num);
        B.insert(num);
    }
    set_difference(A.begin(), A.end(), B.begin(), B.end(),inserter(diffAB, diffAB.begin()));
    set_difference(B.begin(), B.end(), A.begin(), A.end(),inserter(diffBA, diffBA.begin()));

    result = diffAB.size() + diffBA.size();
    printf("%ld\n", result);
}
