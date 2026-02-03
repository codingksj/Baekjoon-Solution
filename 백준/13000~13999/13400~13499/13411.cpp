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

struct Rocket {
    LL x, y, v, idx;
};

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

constexpr auto Rng = views::iota;
constexpr auto Step = views::stride;

const string SEPS = " \n";
enum CONSTS : int { MOD = (int)1E+9 + 7, INF = 0x3f3f3f3f, DIGITS = 10, MAX = 1 << 6, MAX_N = 50 };

vector<Rocket> rockets;
int N, cnt;

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

	rockets = V1<Rocket>(N);

	for (auto& [x, y, v, i] : rockets) {
		cin >> x >> y >> v;
		i = ++cnt;
	}

	return true;
};

void Solve() {
	auto Comp = [](const Rocket& a, const Rocket& b) {
		LL d1 = a.x * a.x + a.y * a.y, spd1 = a.v * a.v;
		LL d2 = b.x * b.x + b.y * b.y, spd2 = b.v * b.v;
		return d1 * spd2 != d2 * spd1 ? d1 * spd2 < d2 * spd1 : a.idx < b.idx;
	};
	ranges::sort(rockets, Comp);
	return;
}

void Output() {
	for (auto& [x, y, v, i] : rockets) {
		println("{}", i);
	}
	return;
}
