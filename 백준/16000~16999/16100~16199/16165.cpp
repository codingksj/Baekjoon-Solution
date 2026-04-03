#include<bits/stdc++.h>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
using Ti3 = tuple<int, int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 100;
	constexpr auto Rng = views::iota;
	constexpr auto Rev = views::reverse;
	constexpr auto Split = views::split;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

unordered_map<string, shared_ptr<string>> mp;
unordered_map<string, int> toIdx;
V1<string> teams[MAX];
string s, t;
int N, M, K, q;

int main() {
	FastIO();
	SetUp();

	Input();
	Solve();
	Output();

	return 0;
}

void FastIO() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	return;
};

void SetUp() {
	return;
};

bool Input() {
	cin >> N >> M;

	for (int i : Rng(0, N)) {
		cin >> s >> K;
		toIdx[s] = i;
		auto ss = make_shared<string>(s);
		for (int j : Rng(0, K)) {
			cin >> t;
			teams[i].push_back(t);
			mp[t] = ss;
		}
		ranges::sort(teams[i]);
	}

	return true;
};

void Solve() {
	while(M--){
		cin >> s >> q;
		if (q == 0) {
			for (const auto& t : teams[toIdx[s]]) {
				println("{}", t);
			}
		}
		else {
			println("{}", *mp[s]);
		}
	}
	return;
};

void Output() {
	return;
};
