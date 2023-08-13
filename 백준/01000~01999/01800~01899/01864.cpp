#include<iostream>
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

LL DecodeOct(string& octo, map<char, LL>& tb);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string octopus_num;
	LL answer;
	map<char, LL> oct_table = {
		{'-',0},
		{'\\',1},
		{'(',2},
		{'@',3},
		{'?',4},
		{'>',5},
		{'&',6},
		{'%',7},
		{'/',-1}
	};

	while (true) {
		answer = 0;
		cin >> octopus_num;
		if (octopus_num == "#") {
			break;
		}
		cout << DecodeOct(octopus_num, oct_table) << "\n";
	}

	return 0;
}

LL DecodeOct(string& octo, map<char, LL>& tb) {
	LL decoded_octo = 0;
	LL weight = 1;
	reverse(octo.begin(), octo.end());
	for (auto digit : octo) {
		decoded_octo += tb[digit] * weight;
		weight *= 8LL;
	}
	return decoded_octo;
};

