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
typedef pair<string, int> Psi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, string> UMapSS;
typedef vector<string> Words;

int FindCycle(int N, int P);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int cycle;
    int N, P;

    cin >> N >> P;

    cycle = FindCycle(N, P);

    cout << cycle;
    
    return 0;
}

int FindCycle(int N, int P) {
    int remainders[1001] = { 0, };
    int count = 1;
    int cycleN = N;
    int ans;

    remainders[cycleN] = count;

    while (true) {
        cycleN = (cycleN * N) % P;
        count++;
        if (remainders[cycleN]) {
            ans = count - remainders[cycleN];
            break;
        }
        remainders[cycleN] = count;
    }
    return ans;
};