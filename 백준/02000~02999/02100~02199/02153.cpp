#include<iostream>
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
typedef pair<LL, LL> Pll;

#define LIMIT 10000

set<int> GetPrimes(int limit);
int GetValue(string word);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	set<int> primes = GetPrimes(LIMIT);
	string word;
	int value;

	cin >> word;

	value = GetValue(word);

	cout << "It is " 
		<< (primes.count(value) ? "" : "not ") 
		<< "a prime word.";

	return 0;
}

set<int> GetPrimes(int limit) {
	vector<bool> is_prime(limit + 1, true);
	set<int> primes;

	is_prime[0] = false;

	for (int i = 2; i * i <= limit; ++i) {
		if (is_prime[i]) {
			for (int j = i * i; j <= limit; j += i) {
				is_prime[j] = false;
			}
		}
	}

	for (int i = 1; i <= limit; ++i) {
		if (is_prime[i]) {
			primes.insert(i);
		}
	}

	return primes;
};

int GetValue(string word) {
	int sum = 0;
	int val;
	for (auto letter : word) {
		if (letter >= 'a' && letter <= 'z') {
			val = (letter - 'a' + 1);
		}
		else if (letter >= 'A' && letter <= 'Z') {
			val = (letter - 'A' + 27);
		}
		sum += val;
	}
	return sum;
};