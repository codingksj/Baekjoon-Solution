#include<iostream>
#include<set>
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

using namespace std;

typedef long long LL;
typedef pair<int, int> Pii;

vector<bool> isPrime;
vector<int> primes;

void GetPrimes(int M) {
	for (int i = 2; i * i <= M; i++) {
		for (int j = i * i; j <= M; j += i) {
			isPrime[j] = false;
		}
	}
	for (int i = 2; i <= M; i++) {
		if (isPrime[i]) { 
			primes.push_back(i);
		}
	}

}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	int start = 0, end = 0;
	int sum = 0, count = 0;
	cin >> N;
	if (N == 1) {
		cout << 0;
		return 0;
	}
	isPrime.resize(N + 1, true);
	GetPrimes(N);
	while (true) {
		if (sum > N) {
			sum -= primes[start++];
		}
		else if (end == primes.size()) {
			break;
		}
		else {
			sum += primes[end++];
		}

		if (sum == N) {
			count++;
		}
	}
	cout << count;
	return 0;
}