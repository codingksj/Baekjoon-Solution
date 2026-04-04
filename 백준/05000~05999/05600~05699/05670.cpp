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
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX_NODE = 1E+6, MAX_WORDS = 1E+5;
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

string words[MAX_WORDS + 1];
int childs[MAX_NODE + 1][ALPHABETS];
int childCnt[MAX_NODE + 1];
bool isEnd[MAX_NODE + 1];
double avg;
int N, K, nodeCnt;

int main() {
	FastIO();
	SetUp();

	while (Input()) {
		Solve();
		Output();
	}
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
	return (bool)(cin >> N);
};

void Solve() {
	auto CreateNode = []() {
		memset(childs[nodeCnt], 0, sizeof(int) * ALPHABETS);
		childCnt[nodeCnt] = 0;
		isEnd[nodeCnt] = false;
		return nodeCnt++;
	};
	auto Insert = [&](string_view sv) {
		int cur = 0;
		for (char c : sv) {
			int idx = c - 'a';
			int& child = childs[cur][idx];
			if (!child) {
				child = CreateNode();
				childCnt[cur]++;
			}
			cur = child;
		}
		isEnd[cur] = true;
	};
	auto Find = [&](string_view sv) {
		int cur = 0;
		int cnt = 0;
		for (const char c : sv) {
			if (cur == 0 || childCnt[cur] > 1 || isEnd[cur]) {
				cnt++;
			} 
			cur = childs[cur][c - 'a'];
		}
		return cnt;
	};
	nodeCnt = 0;
	CreateNode();
	avg = 0;
	for (int i = 0; i < N; i++) {
		cin >> words[i];
		Insert(words[i]);
	}
	for (int i = 0; i < N; i++) {
		avg += Find(words[i]);
	}
	avg /= N;
	return;
};

void Output() {
	println("{:.2f}", avg);
	return;
};
