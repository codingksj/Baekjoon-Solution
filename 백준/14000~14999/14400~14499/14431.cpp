#include<bits/stdc++.h>
#include<unordered_set>
#include<string_view>
#include<format>
#include<ranges>
#include<print>
#include<bit>

// ---------- 사용자 정의 자료형 ----------
using namespace std;

using LL = long long;			using ULL = unsigned long long;
using LD = long double;

using Pcc = pair<char, char>;	using Pci = pair<char, int>;	using PcS = pair<char, string>;
using Pib = pair<int, bool>;	using Pic = pair<int, char>;	using Pii = pair<int, int>;		using Pid = pair<int, double>;	using PiS = pair<int, string>;
using Pdi = pair<double, int>;	using Pdd = pair<double, double>;
using PLL = pair<LL, LL>;
using PSi = pair<string, int>;	using PSL = pair<string, LL>;	using PSS = pair<string, string>;

using Tiii = tuple<int, int, int>;
using TLL3 = tuple<LL, LL, LL>;
using Tdii = tuple<double, int, int>;

using Vi = vector<int>;			using VVi = vector<Vi>;			using VVVi = vector<VVi>;
using VLL = vector<LL>;			using VVLL = vector<VLL>;		using VVVLL = vector<VVLL>;
using VULL = vector<ULL>;		using VVULL = vector<VULL>;
using Vb = vector<bool>;		using VVb = vector<Vb>;
using Vc = vector<char>;
using Words = vector<string>;
using VPii = vector<Pii>;		using VVPii = vector<VPii>;
using VPLL = vector<PLL>;		using VVPLL = vector<VPLL>;
using VPdd = vector<Pdd>;

// ---------- 템플릿 함수 ----------
template<typename T> vector<T> InitVec(const size_t SIZE, const T INIT = T()) {
	return vector<T>(SIZE, INIT);
}
template<typename T> vector<vector<T>> Init2DVec(const size_t R, const size_t C, const T INIT = T()) {
	return vector<vector<T>>(R, InitVec(C, INIT));
}
template<typename T> vector<vector<vector<T>>> Init3DVec(const size_t H, const size_t R, const size_t C, const T INIT = T()) {
	return vector<vector<vector<T>>>(H, Init2DVec(R, C, INIT));
}

template<typename T1, typename T2> pair<T1, T2> LoadPair() {
	pair<T1, T2> p;	cin >> p.first >> p.second;	return p;
};
template<typename T> vector<T> LoadVec(const size_t SIZE) {
	vector<T> V(SIZE); for (T& e : V) { cin >> e; }	return V;
}
template<typename T1, typename T2> vector<pair<T1, T2>> LoadVec(const size_t SIZE) {
	vector<pair<T1, T2>> V(SIZE); for (auto& p : V) { p = LoadPair<T1, T2>(); }	return V;
}
template<typename T> vector<vector<T>> Load2DVec(const size_t R, const size_t C) {
	vector<vector<T>> V(R, vector<T>(C)); for (auto& row : V) { row = LoadVec<T>(C); }	return V;
}
template<typename T1, typename T2> vector<vector<pair<T1, T2>>> Load2DVec(const size_t R, const size_t C) {
	vector<vector<pair<T1, T2>>> V(R, vector<pair<T1, T2>>(C));
	for (auto& row : V) { row = LoadVec<T1, T2>(C); }	return V;
}

template<typename T1, typename T2> void PrintPair(const pair<T1, T2>& p, const string sepsPair = " ", const string suffix = "\n") {
	cout << p.first << sepsPair << p.second << suffix;
}
template<typename T> void PrintVec(const vector<T>& V, const string sepsC = " ", const string suffix = "\n") {
	for (auto it = V.begin(); it != V.end(); it++) { cout << *it; cout << (it + 1 != V.end() ? sepsC : suffix); }
}
template<typename T1, typename T2> void PrintVec(const vector<pair<T1, T2>>& V, const string sepsPair = " ", const string suffix = "\n") {
	for (const auto& p : V) { PrintPair<T1, T2>(p, sepsPair, suffix); }
}
template<typename T> void Print2DVec(const vector<vector<T>>& V, const string sepsC = " ", const string suffix = "\n") {
	for (const auto& row : V) { PrintVec(row, sepsC, suffix); }
}
template<typename T1, typename T2> void Print2DVec(const vector<vector<pair<T1, T2>>>& V, const string sepsPair = " ", const string suffix = "\n") {
	for (const auto& row : V) { PrintVec<T1, T2>(row, sepsPair, suffix); }
}

template<typename T> size_t MxIndex(const vector<T>& V, const size_t ds = 0, const size_t de = 0) {
	return max_element(V.begin() + ds, V.end() - de) - V.begin();
}
template<typename T> size_t MnIndex(const vector<T>& V, const size_t ds = 0, const size_t de = 0) {
	return min_element(V.begin() + ds, V.end() - de) - V.begin();
}
template<typename T> size_t LBIndex(const vector<T>& V, const T target, const size_t ds = 0, const size_t de = 0) {
	return lower_bound(V.begin() + ds, V.end() - de, target) - V.begin();
}
template<typename T> size_t UBIndex(const vector<T>& V, const T target, const size_t ds = 0, const size_t de = 0) {
	return upper_bound(V.begin() + ds, V.end() - de, target) - V.begin();
}
template<typename T> size_t CountByBound(const vector<T>& V, const T leftVal, const T rightVal) {
	return upper_bound(V.begin(), V.end(), rightVal) - lower_bound(V.begin(), V.end(), leftVal);
};

template<typename Number> vector<Number> InitArithmeticSeq(const size_t N, const Number firstTerm = 1, const Number commonDiff = 1) {
	vector<Number> seq(N); for (size_t i = 0; i < N; i++) { seq[i] = firstTerm + i * commonDiff; }	return seq;
}

// ---------- 상수 (열거형 등) ----------
const LD PI = acos(-1);
const LD EPS = 1E-9;
enum BASE_10S : LL { MILLION = (LL)1E+6, BILLION = (LL)(1E+9), TRILLION = (LL)(1E+12) };
enum USUALLY_LL : LL { INF = BILLION + 1, MOD = BILLION + 7 };
enum USUALLY_INT : int { DIGITS = 10, ALPHABETS = 26, ROOT = 1 };
enum TIMES : int { YEAR = 365, MONTH = 12, WEEK = 7, HOUR = 24, MINUTE = 60, SECOND = 60 };
enum GRAPH_CONSTS : int { MAX_VERTEX = 4002, MAX_EDGES = 40000, MAX_DEPTH = 10 };
enum DIRECTIONS : int { UP, RIGHT, DOWN, LEFT };
const VPii DT4 = { Pii(-1,0), Pii(0,1), Pii(1,0), Pii(0,-1) };
const int MAX = 8'500;

// ---------- 사용자 정의 클래스 ----------

// ---------- 사용자 정의 함수 및 연산자 ----------
void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

// ---------- 전역 변수 ----------
VVPii graph(MAX_VERTEX);
priority_queue<Pii, VPii, greater<Pii>> pq;
VPii V;
int dists[MAX_VERTEX + 1];
bool isPrimes[MAX + 1];
bool visChk[MAX_VERTEX + 1];
Pii st, ed;
int N;

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
	memset(isPrimes, true, sizeof(isPrimes));
	isPrimes[0] = isPrimes[1] = false;
	for (int i = 2; i * i <= MAX; i++) {
		if (!isPrimes[i]) {
			continue;
		}
		for (int j = i * i; j <= MAX; j += i) {
			isPrimes[j] = false;
		}
	}
	return;
};

bool Input() {
	st = LoadPair<int, int>();
	ed = LoadPair<int, int>();

	cin >> N;

	V.resize(N + 2);

	V[0] = st;
	V[N + 1] = ed;

	for (int i = 1; i < N + 1; i++) {
		cin >> V[i].first >> V[i].second;
		dists[i] = INF;
	}
	return true;
};

void Solve() {
	auto Calc = [&](const Pii& p1, const Pii& p2) { 
		int dr = p1.first - p2.first; 
		int dc = p1.second - p2.second; 
		return sqrt(dr * dr + dc * dc); 
	};
	dists[N + 1] = INF;
	for (int i = 0; i < N + 2; i++) {
		for (int j = i + 1; j < N + 2; j++) {
			int dist = Calc(V[i], V[j]);
			if (isPrimes[dist]) {
				graph[i].push_back(Pii(dist, j));
				graph[j].push_back(Pii(dist, i));
			}
		}
	}
	pq.push(Pii(0, 0));
	while (!pq.empty()) {
		auto [w, v] = pq.top(); pq.pop();
		if (dists[v] < w) {
			continue;
		}
		for (const auto& [viaW, nv] : graph[v]) {
			if (dists[v] + viaW < dists[nv]) {
				dists[nv] = dists[v] + viaW;
				pq.push(Pii(dists[nv], nv));
			}
		}
	}
	return;
};

void Output() {
	println("{}", dists[N + 1] == INF ? -1 : dists[N + 1]);
	return;
};
