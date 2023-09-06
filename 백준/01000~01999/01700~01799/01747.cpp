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

#define MAX 1500000

vector<int> GetPrime(int N);
int FindMinPalindromePrime(vector<int>& primes, int N);
bool CheckPalindrome(int N);


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    vector<int> primes = GetPrime(MAX);
    int N, ans;

    cin >> N;

    ans = FindMinPalindromePrime(primes, N);

    cout << ans;

    return 0;
}

vector<int> GetPrime(int N) {
    vector<int> primes;
    bitset<MAX + 1> isPrime;
    isPrime.set();

    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= N; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= N; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

int FindMinPalindromePrime(vector<int>& primes, int N) {
    auto it = lower_bound(primes.begin(), primes.end(), N);
    int index = distance(primes.begin(), it);
    int size = primes.size();

    for (int i = index; i < size; i++) {
        if (CheckPalindrome(primes[i])) {
            return primes[i];
        }
    }

    return -1;
};

bool CheckPalindrome(int N) {
    string number = to_string(N);
    int left = 0;
    int right = number.length() - 1;

    while (left < right) {
        if (number[left] != number[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
};