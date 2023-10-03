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

#define MAX 123456*2+1

vector<int> LoadPrimes(const int N);
int CountPrimeInRange(const vector<int>& primes, const int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> primes = LoadPrimes(MAX);
    int N, cnt;

    while (cin >> N && N) {
        cnt = CountPrimeInRange(primes, N);

        cout << cnt << "\n";
    }

    return 0;
}

vector<int> LoadPrimes(const int N) {
    vector<bool> isPrime(N + 1, true);
    vector<int> primes = { 2 };

    for (int i = 2; i * i <= N; i++) {
        if (!isPrime[i]) {
            continue;
        }
        for (int j = i * i; j <= N; j += i) {
            isPrime[j] = false;
        }
    }

    for (int i = 3; i <= N; i += 2) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
};

int CountPrimeInRange(const vector<int>& primes, const int N) {
    int lb = upper_bound(primes.begin(), primes.end(), N) - primes.begin();
    int ub = lower_bound(primes.begin(), primes.end(), 2 * N) - primes.begin();

    int cnt = (ub == lb) ? 1 : ub - lb;

    return cnt;
};
