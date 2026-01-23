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
const int MAX = 5'000;

// ---------- 사용자 정의 클래스 ----------

// ---------- 사용자 정의 함수 및 연산자 ----------
void FastIO();
void SetUp();
void CountFullSq(int a, int b);
void CountCross(int a, int b);
void CalcPrefixSum(int arr[DIGITS][DIGITS]);
bool Input();
void Solve();
void Output();

// ---------- 전역 변수 ----------
VPii DTArea10;
VLL res;
int A[DIGITS][DIGITS][DIGITS][DIGITS];
int rect[DIGITS][DIGITS][DIGITS][DIGITS];
int crossL[DIGITS][DIGITS][DIGITS][DIGITS];
int crossU[DIGITS][DIGITS][DIGITS][DIGITS];
int crossUL[DIGITS][DIGITS][DIGITS][DIGITS];
LL rN, rM, qN, qM, X;
int TC, N, M, a, b, tc;
bool isRemainN, isRemainM;

int main() {
	FastIO();
	SetUp();

	cin >> TC;

	for (tc = 0; tc < TC; tc++) {
		Input();
		Solve();
	}
	Output();

	return 0;
}

void FastIO() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
};

void SetUp() {
	for (int dr = 0; dr < DIGITS; dr++) {
		for (int dc = 0; dc < DIGITS; dc++) {
			if ((dr + 1) * (dc + 1) <= DIGITS) {
				DTArea10.push_back(Pii(dr, dc));
			}
		}
	}
	for (int a = 0; a < DIGITS; a++) {
		for (int b = 0; b < DIGITS; b++) {
			for (int r = 0; r < DIGITS; r++) {
				for (int c = 0; c < DIGITS; c++) {
					A[a][b][r][c] = (a * (r + 1) + b * (c + 1)) % DIGITS;
				}
			}
		}
	}
	for (int a = 0; a < DIGITS; a++) {
		for (int b = 0; b < DIGITS; b++) {
			CountFullSq(a, b);
			CountCross(a, b);
		}
	}
	return;
};

void CountFullSq(int a, int b) {
	for (int r = 0; r < DIGITS; r++) {
		for (int c = 0; c < DIGITS; c++) {
			for (const auto& [dr, dc] : DTArea10) {
				int nr = r + dr;
				int nc = c + dc;
				int chk = 0;
				bool isUnq = true;
				bool isExceedR = nr >= DIGITS;
				bool isExceedC = nc >= DIGITS;
				if (isExceedR || isExceedC) {
					continue;
				}
				for (int i = r; i <= nr; i++) {
					for (int j = c; j <= nc; j++) {
						int bit = (1 << A[a][b][i][j]);
						if (chk & bit) {
							isUnq = false;
							i = j = DIGITS;
							break;
						}
						chk |= bit;
					}
				}
				if (!isUnq) {
					continue;
				}
				rect[a][b][nr][nc]++;
			}
		}
	}
	CalcPrefixSum(rect[a][b]);
};

void CountCross(int a, int b) {
	for (int r = 0; r < DIGITS; r++) {
		for (int c = 0; c < DIGITS; c++) {
			for (const auto& [dr, dc] : DTArea10) {
				int nr = r - dr;
				int nc = c - dc;
				int chk = 0;
				bool isUnq = true;
				if (nr >= 0 && nc >= 0) {
					continue;
				}
				for (int i = r; i >= nr; i--) {
					for (int j = c; j >= nc; j--) {
						int bit = (1 << A[a][b][i < 0 ? i + DIGITS : i][j < 0 ? j + DIGITS : j]);
						if (chk & bit) {
							isUnq = false;
							break;
						}
						chk |= bit;
					}
					if (!isUnq) {
						break;
					}
				}
				if (!isUnq) {
					continue;
				}
				if (nr < 0 && nc < 0) {
					crossUL[a][b][r][c]++;
				}
				else {
					(nr < 0 ? crossU : crossL)[a][b][r][c]++;
				}
			}
		}
	}
	CalcPrefixSum(crossL[a][b]);
	CalcPrefixSum(crossU[a][b]);
	CalcPrefixSum(crossUL[a][b]);
};

void CalcPrefixSum(int arr[DIGITS][DIGITS]) {
	for (int r = 0; r < DIGITS; r++) {
		for (int c = 0; c < DIGITS; c++) {
			if (r > 0) {
				arr[r][c] += arr[r - 1][c];
			}
			if (c > 0) {
				arr[r][c] += arr[r][c - 1];
			}
			if (r > 0 && c > 0) {
				arr[r][c] -= arr[r - 1][c - 1];
			}
		}
	}
}

bool Input() {
	cin >> N >> M >> a >> b;

	return true;
};

void Solve() {
	LL x1, x2, x3, x4;
	a %= DIGITS;
	b %= DIGITS;
	rM = (M - 1) % DIGITS;
	rN = (N - 1) % DIGITS;
	qM = M / DIGITS;
	qN = N / DIGITS;
	isRemainN = rN != DIGITS - 1;
	isRemainM = rM != DIGITS - 1;
	if (N <= DIGITS) {
		if (M <= DIGITS) {
			x1 = 0;
			x2 = 0;
			x3 = 0;
			x4 = rect[a][b][rN][rM];
		}
		else {
			x1 = 0;
			x2 = 0;
			x3 = (qM - 1) * crossL[a][b][rN][DIGITS - 1]
				+ qM * rect[a][b][rN][DIGITS - 1];
			if (isRemainM) {
				x4 = rect[a][b][rN][rM]
					+ crossL[a][b][rN][rM];
			}
		}
	}
	else {
		if (M <= DIGITS) {
			x1 = 0;
			x2 = (qN - 1) * crossU[a][b][DIGITS - 1][rM]
				+ qN * rect[a][b][DIGITS - 1][rM];
			x3 = 0;
			if (isRemainN) {
				x4 = rect[a][b][rN][rM]
					+ crossU[a][b][rN][rM];
			}
		}
		else {
			x1 = qN * qM * rect[a][b][DIGITS - 1][DIGITS - 1]
				+ (qN - 1) * qM * crossU[a][b][DIGITS - 1][DIGITS - 1]
				+ (qM - 1) * qN * crossL[a][b][DIGITS - 1][DIGITS - 1]
				+ (qN - 1) * (qM - 1) * crossUL[a][b][DIGITS - 1][DIGITS - 1];
			if (isRemainN) {
				x2 = qM * rect[a][b][rN][DIGITS - 1]
					+ qM * crossU[a][b][rN][DIGITS - 1]
					+ (qM - 1) * crossUL[a][b][rN][DIGITS - 1]
					+ (qM - 1) * crossL[a][b][rN][DIGITS - 1];
			}
			if (isRemainM) {
				x3 = qN * rect[a][b][DIGITS - 1][rM]
					+ qN * crossL[a][b][DIGITS - 1][rM]
					+ (qN - 1) * crossUL[a][b][DIGITS - 1][rM]
					+ (qN - 1) * crossU[a][b][DIGITS - 1][rM];
			}
			if (isRemainN && isRemainM) {
				x4 = rect[a][b][rN][rM]
					+ crossU[a][b][rN][rM]
					+ crossL[a][b][rN][rM]
					+ crossUL[a][b][rN][rM];
			}
		}
	}
	X = x1 + x2 + x3 + x4;
	res.push_back(X);
	return;
};

void Output() {
	for (const auto& x : res) {
		print("{}{}", x, --TC == 0 ? '\n' : ' ');
	}
	return;
};
