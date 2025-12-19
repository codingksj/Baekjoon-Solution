#include<bits/stdc++.h>
#include<unordered_set>

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
using Vb = vector<bool>;		using VVb = vector<Vb>;
using Vc = vector<char>;
using Words = vector<string>;
using VPii = vector<Pii>;		using VVPii = vector<VPii>;

// ---------- 사용자 정의 클래스 ----------


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

template<typename T, typename Compare = less<T>> void SortAll(vector<T>& V, Compare cmp = Compare()) {
	sort(V.begin(), V.end(), cmp);
}
template<typename T, typename Compare = less<T>> void SortAll2D(vector<vector<T>>& V, Compare cmp = Compare()) {
	for (auto& row : V) { SortAll(row, cmp); }
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
enum TIMES : int { YEAR = 365, MONTH = 30, WEEK = 7, HOUR = 24, MINUTE = 60, SECOND = 60 };
enum GRAPH_CONSTS : int { MAX_VERTEX = 200, MAX_EDGES = 40000, MAX_DEPTH = 10 };
enum DIRECTIONS : int { UP, RIGHT, DOWN, LEFT };
const VPii DT4 = { Pii(-1,0), Pii(0,1), Pii(1,0), Pii(0,-1) };
const int MAX = 20;
const int MAX_LENGTH = 10;
const int BASE = 11;

// ---------- 사용자 정의 함수 및 연산자 ----------
void FastIO();
void SetUp();
bool Input();
void Solve();
char CalcExp(int n);
void Move(int dir, char b[MAX + 1][MAX + 1]);
void DFS(int depth);
char CalcMxExp(char b[MAX + 1][MAX + 1]);
void Output();

// ---------- 전역 변수 ----------
char boards[MAX_DEPTH + 1][MAX + 1][MAX + 1];
int N, tmp;
char mxExp;

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

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> tmp;
			boards[0][r][c] = tmp ? CalcExp(tmp) : 0;
			mxExp = max(mxExp, boards[0][r][c]);
		}
	}
	return true;
};

void Solve() {
	DFS(0);
	return;
};

char CalcExp(int n) {
	if (!n) {
		return 0;
	}
	char exp = 0;
	while (!(n & 1)) {
		n >>= 1;
		exp++;
	}
	return exp;
};

void DFS(int depth) {
	char curExp = CalcMxExp(boards[depth]);
	if (curExp > mxExp) {
		mxExp = curExp;
	}
	if (depth == MAX_DEPTH) {
		return;
	}
	if ((curExp + MAX_DEPTH - depth) <= mxExp) {
		return;
	}
	for (int dir = 0; dir < 4; dir++) {
		memcpy(boards[depth + 1], boards[depth], sizeof(boards[depth]));
		Move(dir, boards[depth + 1]);
		if (memcmp(boards[depth], boards[depth + 1], sizeof(boards[depth])) != 0) {
			DFS(depth + 1);
		}
	}
};

char CalcMxExp(char b[MAX + 1][MAX + 1]) {
	char mxExp = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			mxExp = max(mxExp, b[r][c]);
		}
	}
	return mxExp;
}

void Move(int dir, char b[MAX + 1][MAX + 1]) {
	int d = (dir & 1) ? -1 : 1;
	int st = (dir & 1) ? N - 1 : 0;
	int ed = (dir & 1) ? -1 : N;
	if (dir < 2) { 
		for (int c = 0; c < N; c++) {
			int t = st;
			for (int r = st + d; r != ed; r += d) {
				if (!b[r][c]) {
					continue;
				}
				char val = b[r][c];
				b[r][c] = 0;
				if (!b[t][c]) {
					b[t][c] = val;
				}
				else if (b[t][c] == val) {
					b[t][c]++; 
					if (b[t][c] > mxExp) {
						mxExp = b[t][c];
					}
					t += d;
				}
				else {
					t += d;
					b[t][c] = val;
				}
			}
		}
	}
	else { 
		for (int r = 0; r < N; r++) {
			int t = st;
			for (int c = st + d; c != ed; c += d) {
				if (!b[r][c]) {
					continue;
				}
				char val = b[r][c];
				b[r][c] = 0;
				if (!b[r][t]) {
					b[r][t] = val;
				}
				else if (b[r][t] == val) {
					b[r][t]++;
					if (b[r][t] > mxExp) {
						mxExp = b[r][t];
					}
					t += d;
				}
				else {
					t += d;
					b[r][t] = val;
				}
			}
		}
	}
}

void Output() {
	cout << (1 << mxExp) << "\n";
	return;
};
