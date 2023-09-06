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

#define MAX 1000000

bitset<MAX + 1> GetPrimes(int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    bitset<MAX + 1> primes = GetPrimes(MAX);
    int N;

    while (cin >> N) {
        if (N == 0) {
            break;
        }

        for (int i = N; i >= N / 2; i--) {
            if (primes[i] && primes[N - i]) {
                cout << N << " = " << N - i << " + " << i << "\n";
                break;
            }
        }
    }

    return 0;
}
bitset<MAX + 1> GetPrimes(int N) {
    bitset<MAX + 1> primes;
    primes.set();

    primes[0] = primes[1] = false;

    for (int p = 2; p * p <= N; ++p) {
        if (primes[p]) {
            for (int i = p * p; i <= N; i += p) {
                primes[i] = false;
            }
        }
    }

    return primes;
}
