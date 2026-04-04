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
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 1E+3;
	constexpr auto Rng = views::iota;
	constexpr auto Rev = views::reverse;
	constexpr auto Split = views::split;
}
using namespace CONSTS;

class Trie {
private:
	map<string, Trie*> childs;
	int depth;
public:
	Trie() : depth(-1) {}

	void Insert(span<string> view) {
		Trie* curr = this;
		for (const auto& w : view) {
			if (!curr->childs[w]) {
				curr->childs[w] = new Trie();
				curr->childs[w]->depth = curr->depth + 1;
			}
			curr = curr->childs[w];
		}
	}

	void PrintAll(Trie* curr) {
		static const string S = string(30, '-');
		static const string_view BAR = S;
		for (const auto& [word, child] : curr->childs) {
			println("{}{}", BAR.substr(0, child->depth * 2), word);
			PrintAll(child);
		}
	}
};

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

string words[MAX];
Trie* trie = new Trie();
int N, K;

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
	cin >> N;

	return true;
};

void Solve() {
	for (int i : Rng(0, N)) {
		cin >> K;
		for (int j = 0; j < K; j++) {
			cin >> words[j];
		}
		trie->Insert(words | views::take(K));
	}
	return;
};

void Output() {
	trie->PrintAll(trie);
	return;
};
