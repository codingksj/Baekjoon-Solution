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
typedef map<string, char> MapSc;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, string> UMapSS;
typedef vector<string> Words;

bool Cmp(int& e1, int& e2);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int A[10];
    int TC;

    cin >> TC;

    while (TC--) {
        for (int i = 0; i < 10; i++) {
            cin >> A[i];
        }
        sort(begin(A), end(A), Cmp);
        cout << A[2] << "\n";
    }

    return 0;
}

bool Cmp(int& e1, int& e2) {
    return e1 > e2;
};