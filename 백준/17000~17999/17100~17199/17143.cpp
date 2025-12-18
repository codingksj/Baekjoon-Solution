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

struct Shark {
	int r, c, speed, dir, sz;
};
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
enum DIRECTION : int { UP, RIGHT, DOWN, LEFT };
const VPii DT4 = { Pii(-1,0), Pii(0,1), Pii(1,0), Pii(0,-1) };
const int MAX = 200;
const int MAX_LENGTH = 10;
const int BASE = 11;

// ---------- 사용자 정의 함수 및 연산자 ----------
void FastIO();
void SetUp();
bool Input();
void Solve();
void Fishing(int c);
int ConvertDir(int dir);
void MoveAllShark();
void UpdatePos(int& pos, int& spd, int& dir, int limit, int dirDec, int dirInc);
void MoveShark(Shark& shark);
void Output();

// ---------- 전역 변수 ----------
VVi board;
vector<Shark> sharks;
Vb isDead;
int R, C, M;
int r, c, s, dir, sz, prv, totShark;

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
	cin >> R >> C >> M;

	board = Init2DVec<int>(R, C, -1);
	isDead = Vb(M);
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> dir >> sz;
		--r, --c;
		sharks.push_back({ r,c,s,ConvertDir(dir), sz });
		board[r][c] = i;
	}

	return true;
};

void Solve() {
	for (int c = 0; c < C; c++) {
		Fishing(c);
		MoveAllShark();
	}
	return;
};

int ConvertDir(int dir) {
	return (dir == 1 || dir == 4) ? dir - 1 : (dir == 2) ? dir : dir - 2;
};

void Fishing(int c) {
	int idx = -1;
	int mnR = INF;
	for (int i = sharks.size() - 1; i >= 0; i--) {
		auto& shark = sharks[i];
		if (shark.c == c && shark.r < mnR) {
			mnR = shark.r;
			idx = i;
		}
	}
	if (idx == -1) {
		return;
	}
	totShark += sharks[idx].sz;
	if (idx != sharks.size() - 1) {
		iter_swap(sharks.begin() + idx, prev(sharks.end()));
	}
	sharks.pop_back();
};

void MoveAllShark() {
	board = Init2DVec<int>(R, C, -1);
	sz = sharks.size();
	isDead = Vb(sz);
	for (int i = 0; i < sz; i++) {
		MoveShark(sharks[i]);
		r = sharks[i].r;
		c = sharks[i].c;
		if (board[r][c] == -1) {
			board[r][c] = i;
		}
		else {
			prv = board[r][c];
			if (sharks[prv].sz < sharks[i].sz) {
				board[r][c] = i;
				isDead[prv] = true;
			}
			else {
				isDead[i] = true;
			}
		}
	}
	for (int i = sharks.size() - 1; i >= 0; i--) {
		if (!isDead[i]) {
			continue;
		}
		if (i != sharks.size() - 1) {
			iter_swap(sharks.begin() + i, prev(sharks.end()));
		}
		sharks.pop_back();
	}
};

void MoveShark(Shark& shark) {
	if (shark.dir == UP || shark.dir == DOWN) {
		UpdatePos(shark.r, shark.speed, shark.dir, R, UP, DOWN);
	}
	else {
		UpdatePos(shark.c, shark.speed, shark.dir, C, LEFT, RIGHT);
	}
};

void UpdatePos(int& pos, int& spd, int& dir, int limit, int dirDec, int dirInc) {
	int range = limit - 1;
	int distToWall = (dir == dirDec) ? pos : (range - pos);
	if (spd <= distToWall) {
		pos += (dir == dirDec) ? -spd : spd;
	}
	else {
		int exceed = spd - distToWall;
		int bounce = 1 + (exceed - 1) / range;
		int remain = (exceed - 1) % range + 1;
		if (bounce & 1) {
			dir = (dir == dirDec) ? dirInc : dirDec;
		}
		pos = dir == dirDec ? range - remain : remain;
	}
	if (pos == 0) {
		dir == dirInc;
	}
	if (pos == range) {
		dir == dirDec;
	}
}

void Output() {
	cout << totShark << "\n";
	return;
};
