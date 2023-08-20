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
typedef pair<int, string> Pis;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<string, char> MapSc;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;

LL FindMinBase(LL p, LL q, LL r);
LL ConvertBase(LL N, LL base);
LL FindPossibleMinBase(LL p, LL q, LL r);


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    LL p, q, r;
    LL base, minBase;
    int TC;

    cin >> TC;

    while (TC--) {
        cin >> p >> q >> r;

        minBase = FindMinBase(p, q, r);
        base = FindPossibleMinBase(p, q, r);

        cout << base << "\n";
    }

    return 0;
}

LL FindMinBase(LL p, LL q, LL r) {
    vector<LL> digits;
    LL pp = p, qq = q, rr = r;
    LL minBase;

    do {
        digits.push_back(pp % 10);
        digits.push_back(qq % 10);
        digits.push_back(rr % 10);
        pp /= 10;
        qq /= 10;
        rr /= 10;
    } while (!((pp == 0) && (qq == 0) && (rr == 0)));

    minBase = *max_element(digits.begin(), digits.end());
    minBase = max(2LL, minBase + 1);

    return minBase;
};

LL ConvertBase(LL N, LL base) {
    string digits = to_string(N);
    LL num;
    LL weight = 1;
    LL sum = 0;

    reverse(digits.begin(), digits.end());

    for (char digit : digits) {
        num = (digit - '0');
        sum += num * weight;
        weight *= base;
    }

    return sum;
};

LL FindPossibleMinBase(LL p, LL q, LL r) {
    LL minBase = FindMinBase(p, q, r);
    LL pp, qq, rr;
    LL base = 0;

    for (LL b = minBase; b < 17; b++) {
        pp = ConvertBase(p, b);
        qq = ConvertBase(q, b);
        rr = ConvertBase(r, b);

        if (pp * qq == rr) {
            base = b;
            break;
        }
    }

    return base;
};