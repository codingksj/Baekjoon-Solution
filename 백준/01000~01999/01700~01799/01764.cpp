#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    vector<string> heard(N);
    vector<string> seen(M);
    vector<string> intersection;

    char tmp[21];

    for (int i = 0; i < N; i++) {
        scanf("%s", tmp);
        heard[i] = string(tmp);
    }
    for (int i = 0; i < M; i++) {
        scanf("%s", tmp);
        seen[i] = string(tmp);
    }

    sort(heard.begin(), heard.end());
    sort(seen.begin(), seen.end());

    set_intersection(heard.begin(), heard.end(), seen.begin(), seen.end(), back_inserter(intersection));
    
    printf("%ld\n", intersection.size());
    for (int i = 0; i < intersection.size(); i++) {
        cout << intersection[i] << "\n";
    }

    return 0;
}
