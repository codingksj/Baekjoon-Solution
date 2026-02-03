#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using Pii = pair<int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

constexpr auto Rng = views::iota;
constexpr auto Step = views::stride;

const string SEPS = " \n";
const string RELATION = "-+";
enum CONSTS : int { MOD = (int)1E+9 + 7, INF = 0x3f3f3f3f, DIGITS = 10, MAX = 5000, MAX_N = 50 };

string r, s;
int N, M, v1, v2;

int main() {
	FastIO();
	SetUp();

	Input();
	Solve();
	Output();

	return 0;
}

void FastIO() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
};

void SetUp() {
	return;
};

bool Input() {
	cin >> N;
	cin.ignore();

	getline(cin, r);

	for (int i : Rng(1, N)) {
		getline(cin, s);
	}
	cin >> M;

	return true;
};

void Solve() {
	s.clear();
	for (int i : Rng(0, M)) {
		cin >> v1 >> v2;
		if (v1 > v2) {
			swap(v1, v2);
		}
		v1 <<= 1;
		v2 <<= 1;
		s += !v1 ? r[v2] : RELATION[r[v1] == r[v2]];
	}
	return;
}

void Output() {
	for (const char ch : s) {
		println("{}", ch);
	}
	return;
}
