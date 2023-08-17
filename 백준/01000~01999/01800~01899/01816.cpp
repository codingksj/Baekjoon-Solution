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

#define LIMIT 1000000

vector<ULL> FindPrimeNumbers();
bool CheckAppropriateKey(vector<ULL>& primes, ULL key);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<ULL> primes = FindPrimeNumbers();
    ULL key;
    bool isAppropriate;
    int TC;

    cin >> TC;

    while (TC--) {
        cin >> key;
        isAppropriate = CheckAppropriateKey(primes, key);
        cout << (isAppropriate ? "YES" : "NO") << "\n";   
    }
    
    return 0;
}

vector<ULL> FindPrimeNumbers() {
    bitset<LIMIT + 1> isPrime;
    vector<ULL> primes;

    isPrime.set();
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i * i <= LIMIT; i++) {
        for (int j = i * i; j <= LIMIT; j += i) {
            isPrime[j] = false;
        }
    }

    for (ULL i = 2; i <= LIMIT; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
};

bool CheckAppropriateKey(vector<ULL>& primes, ULL key) {
    for (auto it = primes.rbegin(); it != primes.rend(); it++) {
        if (key % *(it)) {
            continue;
        }
        return false;
    }
    return true;
};
