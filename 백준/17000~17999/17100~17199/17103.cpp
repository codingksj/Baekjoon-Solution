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

#define LIMIT 1000000

bitset<LIMIT + 1> FindPrimeNumbers();

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

    bitset<LIMIT+1> primes = FindPrimeNumbers();
    int TC, N, count;
	
    cin >> TC;

    while (TC--) {
        cin >> N;

        count = 0;
        for (int a = 2; a <= N / 2; a++) {
            if (primes[a] && primes[N - a]) {
                count++;
            }
        }
        cout << count << "\n";
    }

    return 0;
}

bitset<LIMIT + 1> FindPrimeNumbers() {
    bitset<LIMIT + 1> is_prime;
    is_prime.set(); 

    is_prime[0] = is_prime[1] = false;
    for (int num = 2; num <= LIMIT; num++) {
        if (is_prime[num]) {
            for (int multiple = num * 2; multiple <= LIMIT; multiple += num) {
                is_prime[multiple] = false; 
            }
        }
    }

    return is_prime;
}