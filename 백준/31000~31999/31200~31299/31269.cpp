#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using Pii = pair<int, int>;
using Vi = vector<int>;
using VPii = vector<Pii>;
using Tiii = tuple<int, int, int>;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

auto Rng = [](auto st, auto ed) { return views::iota(st, ed); };

const int MAX = 50;

struct Team {
	int idx;
	int rank;
	int score;
};

vector<Team> teams;
Vi R;
VPii V;
int N, n;

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

	for (int i : Rng(0, N)) {
		cin >> n;
		R.push_back(--n);
	}
	for (int i : Rng(0, N)) {
		cin >> n;
		V.push_back(Pii(n, i));
	}
	return true;
};

void Solve() {
	ranges::sort(V, greater<Pii>());

	teams = vector<Team>(N);

	for (int i : Rng(0, N)) {
		teams[i].idx = i + 1;
		teams[R[i]].rank = i;
	}
	for (int i : Rng(0, N)) {
		teams[i].score += N - teams[i].rank;
		teams[R[i]].rank = i;
		teams[V[i].second].score += N - i;
	}
	auto Compare = [&](const Team& t1, const Team& t2) {
		return t1.score != t2.score ? t1.score > t2.score : t1.rank > t2.rank;
	};
	ranges::sort(teams, Compare);
};

void Output() {
	for (int i : Rng(0, N)) {
		println("{}. Kod{:02} ({})", i + 1, teams[i].idx, teams[i].score);
	}
}
