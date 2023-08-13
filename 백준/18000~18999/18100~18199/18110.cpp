#include<iostream>
#include<sstream>
#include<bitset>
#include<set>
#include<unordered_map>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<algorithm>
#include<string>
#include<numeric>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iomanip>
#include<chrono>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> Pii;
typedef pair<LL, LL> PLL;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

    int N, answer;

    cin >> N;

    if (N == 0) {
        cout << "0\n";
        return 0;
    }

    vector<int> Diff(N);
    for (int i = 0; i < N; i++) {
        cin >> Diff[i];
    }

    int X = round(0.15 * N);
    sort(Diff.begin(), Diff.end());

    double res = 0;
    for (int i = X; i < N - X; i++) {
        res += Diff[i];
    }
    res /= (N - X * 2);
    answer = round(res);

    cout << answer;

    return 0;
}
