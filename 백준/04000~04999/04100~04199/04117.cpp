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

    int N, T1, T2, T3;
    int step1, step2, step3;
    int rotate;
    int maxRotate;

    while (true) {
        cin >> N >> T1 >> T2 >> T3;

        if (N == 0 && T1 == 0 && T2 == 0 && T3 == 0) {
            break;
        }

        rotate = 3 * N;

        step1 = N - T1;
        step2 = T2 - T1;
        step3 = T2 - T3;

        (step2 < 0) && (step2 += N);
        (step3 < 0) && (step3 += N);

        maxRotate = rotate + T1 - 1 + step1 + step2 + step3;

        cout << maxRotate << "\n";
    }
    return 0;
}

