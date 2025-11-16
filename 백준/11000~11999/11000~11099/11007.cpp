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
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using Vb = vector<bool>;
using VVb = vector<Vb>;
using Words = vector<string>;
using VPii = vector<Pii>;
using VVPii = vector<VPii>;

// ---------- 템플릿 자료형 ----------

// ---------- 템플릿 함수 ----------
template<typename T> vector<T> InitVector(const size_t SIZE, const T INIT) {
    return vector<T>(SIZE, INIT);
}
template<typename T> vector<vector<T>> Init2DVector(const size_t R, const size_t C, const T INIT) {
    return vector<vector<T>>(R, InitVector(C, INIT));
}
template<typename T> vector<vector<vector<T>>> Init3DVector(const size_t H, const size_t R, const size_t C, const T INIT) {
    return vector<vector<vector<T>>>(H, Init2DVector(R, C, INIT));
}

template<typename T1, typename T2> pair<T1, T2> LoadPair() {
    pair<T1, T2> p;
    cin >> p.first >> p.second;
    return p;
};
template<typename T> vector<T> LoadVector(const size_t SIZE) {
    vector<T> V(SIZE);
    for (T& e : V) {
        cin >> e;
    }
    return V;
}
template<typename T1, typename T2> vector<pair<T1, T2>> LoadVector(const size_t SIZE) {
    vector<pair<T1, T2>> V(SIZE);
    for (pair<T1, T2>& p : V) {
        p = LoadPair<T1, T2>();
    }
    return V;
}
template<typename T> vector<vector<T>> Load2DVector(const size_t R, const size_t C) {
    vector<vector<T>> V(R, vector<T>(C));
    for (vector<T>& row : V) {
        row = LoadVector<T>(C);
    }
    return V;
}
template<typename T1, typename T2> vector<vector<pair<T1, T2>>> Load2DVector(const size_t R, const size_t C) {
    vector<vector<pair<T1, T2>>> V(R, vector<pair<T1, T2>>(C));
    for (vector<pair<T1, T2>>& row : V) {
        row = LoadVector<T1, T2>(C);
    }
    return V;
}

template<typename T1, typename T2> void PrintPair(const pair<T1, T2>& p, const string sepsPair = " ", const string suffix = "\n") {
    cout << p.first << sepsPair << p.second << suffix;
}
template<typename T> void PrintVector(const vector<T>& V, const string sepsC = " ", const string suffix = "\n") {
    for (auto it = V.begin(); it != V.end(); it++) {
        cout << *it;
		cout << (it + 1 != V.end() ? sepsC : suffix);
    }
}
template<typename T1, typename T2> void PrintVector(const vector<pair<T1, T2>>& V, const string sepsPair = " ", const string suffix = "\n") {
    for (const pair<T1, T2>& p : V) {
        PrintPair<T1, T2>(p, sepsPair, suffix);
    }
}
template<typename T> void Print2DVector(const vector<vector<T>>& V, const string sepsC = " ", const string suffix = "\n") {
    for (const vector<T>& row : V) {
        PrintVector(row, sepsC, suffix);
    }
}
template<typename T1, typename T2> void Print2DVector(const vector<vector<pair<T1, T2>>>& V, const string sepsPair = " ", const string suffix = "\n") {
    for (const vector<pair<T1, T2>>& row : V) {
        PrintVector<T1, T2>(row, sepsPair, suffix);
    }
}

template<typename T, typename Compare = less<T>> void SortAll(vector<T>& V, Compare cmp = Compare()) {
    sort(V.begin(), V.end(), cmp);
}
template<typename T, typename Compare = less<T>> void SortAll2D(vector<vector<T>>& V, Compare cmp = Compare()) {
    for (vector<T>& row : V) {
        Sort(row, cmp);
    }
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
const LL MILLION = 1E+6;
const LL BILLION = 1E+9;
const LL TRILLION = 1E+12;
const LL INF = BILLION;
const LL MOD = BILLION + 9;
const int MAX = 1E+5;
const VPii DT4 = { Pii(-1,0), Pii(0,1), Pii(1,0), Pii(0,-1) };

// ---------- 사용자 정의 함수 및 연산자 ----------
void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

// ---------- 전역 변수 ----------
string alphabet, res;
int TC, N, a;

int main() {
    FastIO();
    SetUp();

    cin >> TC;

    while (TC--) {
        Input();
        Solve();
        Output();
    }
    
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

    return true;
};

void Solve() {
	alphabet = "abcdefghijklmnopqrstuvwxyz";
    res = "";
    for(int i = 0; i < N; i++) {
        cin >> a;
		res += alphabet[a];
        alphabet = alphabet[a] + alphabet.substr(0, a) + alphabet.substr(a + 1);
	}
    return;
}

void Output() {
	cout << res << '\n';
    return;
};
