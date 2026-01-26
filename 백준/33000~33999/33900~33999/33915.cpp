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

using Ti3 = tuple<int, int, int>;
using TLL3 = tuple<LL, LL, LL>;
using Tdii = tuple<double, int, int>;
using Ti4 = tuple<int, int, int, int>;

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
enum DIRECTIONS : int { UP, LEFT, DOWN, RIGHT };
const VPii DT4 = { Pii(-1,0), Pii(0,-1), Pii(1,0), Pii(0,1) };
const int MAX = 2000;

// ---------- 사용자 정의 클래스 ----------

// ---------- 사용자 정의 함수 및 연산자 ----------
void FastIO();
void SetUp();
bool Input();
void Solve();
int DFS(int prv, int v, int depth);
void Output();

// ---------- 전역 변수 ----------
VVi graph;
Vi visChk;
int V, E, v1, v2, cycle, mnColor;

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
	cin >> V;

	graph = Init2DVec<int>(V, 0);
	visChk = Vi(V);

	for (int i = 0; i < V; i++) {
		cin >> v1 >> v2;
		--v1, --v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	return true;
};

void Solve() {
	cycle = DFS(-1, 0, 1);
	mnColor = 2 + (cycle & 1);
};

int DFS(int prv, int v, int depth) {
	visChk[v] = depth;

	for (int nv : graph[v]) {
		if (nv == prv) {
			continue;
		}
		if (visChk[nv]) {
			return depth - visChk[nv] + 1;
		}
		int res = DFS(v, nv, depth + 1);
		if (res != -1) {
			return res;
		}
	}
	return -1;
};

void Output() {
	println("{}", mnColor);
	return;
};
