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

    int R, C;
    int A, B;

    cin >> R >> C;
    cin >> A >> B;

    for (int r = 0; r < R * A; r++) {
        for (int c = 0; c < C * B; c++) {
            cout << (((r / A + c / B) & 1) ? '.' : 'X');
        }
        cout << "\n";
    }
    return 0;
}
