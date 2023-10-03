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

typedef map<int, int> Mapii;
typedef map<int, string> MapiS;
typedef map<LL, LL> MapLL;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;

typedef unordered_map<LL, LL> HashLL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

#define MAX 1E+7

vector<LL> LoadPrimes(const LL N);
LL CountAlmostPrime(const vector<LL>& primes, const LL left, const LL right);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<LL> primes = LoadPrimes(MAX);
    LL left, right;
    LL cnt;

    cin >> left >> right;

    cnt = CountAlmostPrime(primes, left, right);

    cout << cnt << "\n";

    return 0;
}

vector<LL> LoadPrimes(const LL N) {
    vector<bool> isPrime(N + 1, true);
    vector<LL> primes = { 2LL };

    for (LL i = 2LL; i * i <= N; i++) {
        if (!isPrime[i]) {
            continue;
        }
        for (LL j = i * i; j <= N; j += i) {
            isPrime[j] = false;
        }
    }

    for (LL i = 3LL; i <= N; i += 2LL) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
};

LL CountAlmostPrime(const vector<LL>& primes, const LL left, const LL right) {
    LL lb, ub;
    LL cnt = 0;

    for (const LL& prime : primes) {
        if (prime * prime > right) {
            break;
        }
        lb = max(2.0, ceil(log(left) / log(prime)));
        ub = floor(log(right) / log(prime));
        cnt += (ub - lb + 1);
    }

    return cnt;
};