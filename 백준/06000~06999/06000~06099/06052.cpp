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
#include<tuple>
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

typedef pair<char, char> Pcc;
typedef pair<char, int> Pci;
typedef pair<char, string> PcS;
typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, string> PiS;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> PSi;
typedef pair<string, LL> PSL;
typedef pair<string, string> PSS;

typedef map<int, string> MapiS;
typedef map<LL, LL> MapLL;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;

typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;

Pii FindFriendsNum(const int N);
int CalcSumOfDivisors(const int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Pii ans;
    int N;

    cin >> N;
    
    ans = FindFriendsNum(N);

    cout << ans.first << " " << ans.second << "\n";

    return 0;
}

Pii FindFriendsNum(const int N) {
    Pii ans = { -1,-1 };
    int s1, s2;

    for (int i = N;; i++) {
        s1 = CalcSumOfDivisors(i);

        if (s1 == i) {
            continue;
        }

        s2 = CalcSumOfDivisors(s1);

        if (s2 == i) {
            ans = { s2,s1 };
            break;
        }
    }

    return ans;
};

int CalcSumOfDivisors(const int N) {
    int sum = -N;

    for (int i = 1; i*i <= N; i++) {
        if (N % i == 0) {
            sum += (i * i == N) ? i : (i + N / i);
        }
    }

    return sum;
};