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
void BFS(int v);
void Output();

constexpr auto Rng = views::iota;
constexpr auto Step = views::stride;

const string SEPS = " \n";
enum CONSTS : int { MOD = (int)1E+9 + 7, INF = 0x3f3f3f3f, DIGITS = 10, MAX = 100'000, MAX_N = 50 };

V2<int> graph;
int depths[MAX];
int N, M, rt, v1, v2;

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
	cin >> N >> M >> rt;

	graph = V2<int>(N);

	for (int i : Rng(0, M)) {
		cin >> v1 >> v2;
		--v1, --v2;
		graph[v1].emplace_back(v2);
		graph[v2].emplace_back(v1);
	}

	return true;
};

void Solve() {
	memset(depths, -1, sizeof(depths));
	BFS(--rt);
	return;
}

void BFS(int v) {
	queue<int> q;

	depths[v] = 0;

	q.emplace(v);

	while (!q.empty()) {
		auto v = q.front(); q.pop();

		for (int nv : graph[v]) {
			int& nd = depths[nv];
			int d = depths[v];
			if (nd == -1) {
				nd = d + 1;
				q.emplace(nv);
			}
		}
	}
};

void Output() {
	for (int v : Rng(0, N)) {
		println("{}", depths[v]);
	}
	return;
}
