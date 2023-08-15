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

    vector<int> dwarfs(10, 0);
    int dwarf;
    int sum = 0;
    int fake;

    for (int i = 0; i < 9; i++) {
        cin >> dwarf;
        sum += dwarf;
        dwarfs[i] = dwarf;
    }

    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            fake = dwarfs[i] + dwarfs[j];
            if (sum - 100 == fake) {
                dwarfs[i] = 0;
                dwarfs[j] = 0;
                j = 10;
                i = 10;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        dwarfs[i] && (cout << dwarfs[i] << "\n");
    }
    return 0;
}
