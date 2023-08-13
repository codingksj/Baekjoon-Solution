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

string MakeAlgorithmNameShort(string algorithm);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string algorithm;

	cin >> algorithm;
	cout << MakeAlgorithmNameShort(algorithm);

	return 0;
}

string MakeAlgorithmNameShort(string algorithm) {
	string shortend_algorithm = "";
	for (char letter : algorithm) {
		if (isupper(letter)) {
			shortend_algorithm += letter;
		}
	}
	return shortend_algorithm;
};