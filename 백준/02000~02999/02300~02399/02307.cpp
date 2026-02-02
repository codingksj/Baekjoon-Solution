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
int Dijk(int ban1, int ban2, bool save = false);
void Output();

constexpr auto Rng = views::iota;
constexpr auto Step = views::stride;

const string SEPS = " \n";
enum CONSTS : int {MOD = (int)1E+9 + 7, INF = 0x3f3f3f3f, DIGITS = 10, MAX = (int)1E+3};

V2<Pii> graph;
V1<Pii> edges;
int par[MAX + 1];
int dists[MAX + 1];
int N, M, v1, v2, w, baseT, mxT, mxDelay;

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
	cin >> N >> M;

	graph = V2<Pii>(N);

	for (int i : Rng(0, M)) {
		cin >> v1 >> v2 >> w;
		--v1, --v2;
		graph[v1].push_back(Pii(w, v2));
		graph[v2].push_back(Pii(w, v1));
	}

	return true;
};

void Solve() {
	memset(par, -1, sizeof(par));
	baseT = Dijk(-1, -1, true);
	mxT = baseT;

	for (const auto& [v1, v2] : edges) {
		int t = Dijk(v1, v2);
		if (t == INF) {
			mxDelay = -1;
			return;
		}
		if (t > mxT) {
			mxT = t;
			mxDelay = mxT - baseT;
		}
	}
	return;
}

int Dijk(int ban1, int ban2, bool save) {
	priority_queue<Pii, V1<Pii>, greater<Pii>> pq;
	memset(dists, 0x3f, sizeof(dists));
	dists[0] = 0;
	pq.emplace(0, 0);

	while (!pq.empty()) {
		auto [w, v] = pq.top(); pq.pop();
		if (v == N - 1) {
			break;
		}
		if (dists[v] < w) {
			continue;
		}
		for (const auto& [nw, nv] : graph[v]) {
			if (w + nw >= dists[nv] || v == ban1 && nv == ban2 || v == ban2 && nv == ban1) {
				continue;
			}
			dists[nv] = w + nw;
			if (save) {
				par[nv] = v;
			}
			pq.emplace(dists[nv], nv);
		}
	}
	if (save) {
		for (int v = N - 1; par[v] != -1; v = par[v]) {
			edges.emplace_back(v, par[v]);
		}
	}
	return dists[N - 1];
};

void Output() {
	println("{}", mxDelay);
}
