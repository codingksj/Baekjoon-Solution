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
typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, string> Pis;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<int, string> MapiS;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;
typedef vector<vector<int>> Matrix2Di;

ULL ContinuousRound(ULL N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    ULL N;
    int TC;

    cin >> TC;

    while (TC--) {
        cin >> N;

        N = ContinuousRound(N);

        cout << N << "\n";
    }

    return 0;
}

ULL ContinuousRound(ULL N) {
    vector<ULL> digits;
    ULL curN = N;
    ULL carry = 0;
    ULL w = 1;
    ULL answer = 0;
    ULL maxSize;

    int index = 0;

    do {
        digits.push_back(curN % 10);
        curN /= 10;
    } while (curN);

    maxSize = digits.size();

    if (maxSize == 1) {
        return digits[0];
    }

    for (int i = 0; i < maxSize; i++) {
        digits[i] += carry;
        if (i == maxSize - 1) {
            break;
        }
        carry = (digits[i] + 5) / 10;
        digits[i] = 0;
    }

    for (ULL digit : digits) {
        answer += digit * w;
        w *= 10;
    }

    return answer;
};