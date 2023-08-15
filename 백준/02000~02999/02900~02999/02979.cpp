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

    bitset<101> trucks[3];
    int A, B, C;
    int sum;
    int totalFee = 0;
    int start, end;

    cin >> A >> B >> C;

    for (int i = 0; i < 3; i++) {
        cin >> start >> end;
        for (; start < end; start++) {
            trucks[i].set(start);
        }
    }
    for (int i = 0; i < 101; i++) {
        sum = trucks[0][i] + trucks[1][i] + trucks[2][i];
        (sum == 3) && (totalFee += 3*C);
        (sum == 2) && (totalFee += 2*B);
        (sum == 1) && (totalFee += A);
    }
    cout << totalFee;

    return 0;
}
