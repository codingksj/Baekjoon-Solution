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

    bitset<50> lotto;
    int TC, N;

    while (true) {
        lotto.reset();

        cin >> TC;

        if (TC == 0) {
            break;
        }

        while (TC--) {
            for (int i = 0; i < 6; i++) {
                cin >> N;
                lotto[N] = 1;
            }
        }

        cout << (lotto.count() == 49 ? "Yes" : "No") << "\n";
    }
    return 0;
}

