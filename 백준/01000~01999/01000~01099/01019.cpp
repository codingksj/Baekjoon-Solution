#include<bits/stdc++.h>
#include<unordered_set>

// ---------- 사용자 정의 자료형 ----------
using namespace std;

using LL = long long;
using ULL = unsigned long long;
using LD = long double;

using Pcc = pair<char, char>;
using Pci = pair<char, int>;
using PcS = pair<char, string>;
using Pib = pair<int, bool>;
using Pii = pair<int, int>;
using Pic = pair<int, char>;
using Pid = pair<int, double>;
using PiS = pair<int, string>;
using Pdd = pair<double, double>;
using Pdi = pair<double, int>;
using PLL = pair<LL, LL>;
using PSi = pair<string, int>;
using PSL = pair<string, LL>;
using PSS = pair<string, string>;

using Tiii = tuple<int, int, int>;
using Tdii = tuple<double, int, int>;

using Vi = vector<int>;
using VVi = vector<Vi>;
using VVVi = vector<VVi>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VVVLL = vector<VVLL>;
using Vb = vector<bool>;
using VVb = vector<Vb>;
using Vc = vector<char>;
using Words = vector<string>;
using VPii = vector<Pii>;
using VVPii = vector<VPii>;

// ---------- 템플릿 자료형 ----------

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
	pair<T1, T2> p;
	cin >> p.first >> p.second;
	return p;
};
template<typename T> vector<T> LoadVec(const size_t SIZE) {
	vector<T> V(SIZE);
	for (T& e : V) {
		cin >> e;
	}
	return V;
}
template<typename T1, typename T2> vector<pair<T1, T2>> LoadVec(const size_t SIZE) {
	vector<pair<T1, T2>> V(SIZE);
	for (auto& p : V) {
		p = LoadPair<T1, T2>();
	}
	return V;
}
template<typename T> vector<vector<T>> Load2DVec(const size_t R, const size_t C) {
	vector<vector<T>> V(R, vector<T>(C));
	for (auto& row : V) {
		row = LoadVec<T>(C);
	}
	return V;
}
template<typename T1, typename T2> vector<vector<pair<T1, T2>>> Load2DVec(const size_t R, const size_t C) {
	vector<vector<pair<T1, T2>>> V(R, vector<pair<T1, T2>>(C));
	for (auto& row : V) {
		row = LoadVec<T1, T2>(C);
	}
	return V;
}

template<typename T1, typename T2> void PrintPair(const pair<T1, T2>& p, const string sepsPair = " ", const string suffix = "\n") {
	cout << p.first << sepsPair << p.second << suffix;
}
template<typename T> void PrintVec(const vector<T>& V, const string sepsC = " ", const string suffix = "\n") {
	for (auto it = V.begin(); it != V.end(); it++) {
		cout << *it;
		cout << (it + 1 != V.end() ? sepsC : suffix);
	}
}
template<typename T1, typename T2> void PrintVec(const vector<pair<T1, T2>>& V, const string sepsPair = " ", const string suffix = "\n") {
	for (const auto& p : V) {
		PrintPair<T1, T2>(p, sepsPair, suffix);
	}
}
template<typename T> void Print2DVec(const vector<vector<T>>& V, const string sepsC = " ", const string suffix = "\n") {
	for (const auto& row : V) {
		PrintVec(row, sepsC, suffix);
	}
}
template<typename T1, typename T2> void Print2DVec(const vector<vector<pair<T1, T2>>>& V, const string sepsPair = " ", const string suffix = "\n") {
	for (const auto& row : V) {
		PrintVec<T1, T2>(row, sepsPair, suffix);
	}
}

template<typename T, typename Compare = less<T>> void SortAll(vector<T>& V, Compare cmp = Compare()) {
	sort(V.begin(), V.end(), cmp);
}
template<typename T, typename Compare = less<T>> void SortAll2D(vector<vector<T>>& V, Compare cmp = Compare()) {
	for (auto& row : V) {
		SortAll(row, cmp);
	}
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
	vector<Number> seq(N);
	for (size_t i = 0; i < N; i++) {
		seq[i] = firstTerm + i * commonDiff;
	}
	return seq;
}

// ---------- 상수 (열거형 등) ----------
const LD PI = acos(-1);
const LD EPS = 1E-9;
enum BASE_10S : LL { MILLION = (LL)1E+6, BILLION = (LL)(1E+9), TRILLION = (LL)(1E+12) };
enum USUALLY_LL : LL { INF = BILLION + 1, MOD = BILLION + 7 };
enum USUALLY_INT : int { DIGITS = 10, ALPHABETS = 26, ROOT = 1 };
const int MAX = 52;
const int MAX_LENGTH = 10;
const int BASE = 11;
const VPii DT4 = { Pii(-1,0), Pii(0,1), Pii(1,0), Pii(0,-1) };

// ---------- 사용자 정의 함수 및 연산자 ----------
void FastIO();
void SetUp();
bool Input();
void Solve();
VLL operator+(const VLL& v1, const VLL& v2);
void Output();

// ---------- 전역 변수 ----------
VVVLL dp = Init3DVec<LL>(MAX_LENGTH + 1, 10, 10);
VLL counts(10), digits, pow10s(MAX_LENGTH + 1, 1);
string s, ss;
int N, digit;

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
	for (int l = 1; l <= MAX_LENGTH; l++) {
		pow10s[l] = 10 * pow10s[l - 1];
	}
	for (int d = 0; d < DIGITS; d++) {
		dp[1][d][d]++;
	}
	for (int l = 2; l <= MAX_LENGTH; l++) {
		for (int d = 0; d < DIGITS; d++) {
			for (int i = 0; i < DIGITS; i++) {
				dp[l][d] = dp[l][d] + dp[l - 1][i];
			}
			dp[l][d][d] += pow10s[l - 1];
		}
	}
	return;
};

bool Input() {
	cin >> s;

	return true;
};

void Solve() {
	N = s.length();
	for (int i = 0; i < N; i++) {
		digit = s[i] - '0';
		for (int d = 0; d < digit; d++) {
			counts = counts + dp[N - i][d];
		}
		ss = (i < N - 1) ? s.substr(i + 1) : "0";
		counts[digit] += stoi(ss) + 1;
		counts[0] -= pow10s[i];
	}
	return;
};

VLL operator+(const VLL& v1, const VLL& v2) {
	if (v1.size() != v2.size()) {
		return VLL();
	}
	VLL res;
	for (int i = 0; i < v1.size(); i++) {
		res.push_back(v1[i] + v2[i]);
	}
	return res;
};

void Output() {
	PrintVec(counts);
	return;
};
