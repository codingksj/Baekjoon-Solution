#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

auto rng = [](int st, int ed) { return views::iota(st, ed); };

unordered_set<string> stolen;
string ps;
int N, M, cnt;

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

	for (int i : rng(0, N)) {
		cin >> ps;
		stolen.insert(ps);
	}

	cin >> M;

	return true;
};

void Solve() {
	for (int i : rng(0, M)) {
		cin >> ps;
		if (stolen.count(ps)) {
			cnt++;
		}
	}
};

void Output() {
	println("{}", cnt);
	return;
}
