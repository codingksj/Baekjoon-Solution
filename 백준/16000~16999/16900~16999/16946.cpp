#include<bits/stdc++.h>
#include<unordered_set>

// ---------- 사용자 정의 자료형 ----------
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

typedef pair<char, char> Pcc;
typedef pair<char, int> Pci;
typedef pair<char, string> PcS;
typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, char> Pic;
typedef pair<int, double> Pid;
typedef pair<int, string> PiS;
typedef pair<double, double> Pdd;
typedef pair<double, int> Pdi;
typedef pair<LL, LL> PLL;
typedef pair<string, int> PSi;
typedef pair<string, LL> PSL;
typedef pair<string, string> PSS;

typedef tuple<int, int, int> Tiii;
typedef tuple<double, int, int> Tdii;

typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<bool> Vb;
typedef vector<Vb> VVb;
typedef vector<string> Words;
typedef vector<Pii> VPii;
typedef vector<VPii> VVPii;

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

template<typename T1, typename T2> void PrintPair(const pair<T1, T2>& p, const string sepsPair) {
    cout << p.first << sepsPair << p.second;
}
template<typename T> void PrintVector(const vector<T>& V, const string sepsC) {
    for (const T& e : V) {
        cout << e << sepsC;
    }
}
template<typename T1, typename T2> void PrintVector(const vector<pair<T1, T2>>& V, const string sepsR, const string sepsPair) {
    for (const pair<T1, T2>& p : V) {
        PrintPair<T1, T2>(p, sepsPair);
        cout << sepsR;
    }
}
template<typename T> void Print2DVector(const vector<vector<T>>& V, const string sepsR, const string sepsC) {
    for (const vector<T>& row : V) {
        PrintVector(row, sepsC);
        cout << sepsR;
    }
}
template<typename T1, typename T2> void Print2DVector(const vector<vector<pair<T1, T2>>>& V, const string sepsR, const string sepsC, const string sepsPair) {
    for (const vector<pair<T1, T2>>& row : V) {
        PrintVector<T1, T2>(row, sepsC, sepsPair);
        cout << sepsR;
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
const VPii DT4 = { Pii(-1,0), Pii(0,1), Pii(1,0), Pii(0,-1) };
enum OBJ {
    EMPTY = '0',
    WALL = '1'
};

// ---------- 사용자 정의 함수 및 연산자 ----------
void FastIO();
void SetUp();
bool Input();
void Solve();
void BFS(const int sr, const int sc);
bool Ok(int r, int c);
bool Union(int u, int v);
int Find(int v);
void Output();

// ---------- 전역 변수 ----------
VVb visChk;
Words walls;
Vi par, sz;
int N, M;

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

    visChk = VVb(N, Vb(M, false));
    walls = LoadVector<string>(N);
    par = InitArithmeticSeq<int>(N * M, 0);
    sz = Vi(N * M, 1);

    return true;
};

void Solve() {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (visChk[r][c]) {
                continue;
            }
            if (walls[r][c] == EMPTY) {
                BFS(r, c);
            }
        }
    }
};

void BFS(const int sr, const int sc) {
    queue<Pii> q;

    q.push(Pii(sr, sc));

    visChk[sr][sc] = true;

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();

        for (const auto& [dr, dc] : DT4) {
            int nr = r + dr;
            int nc = c + dc;
            if (!Ok(nr, nc) || visChk[nr][nc]) {
                continue;
            }
            visChk[nr][nc] = true;
            q.push(Pii(nr, nc));

            int v = r * M + c;
            int nV = nr * M + nc;

            Union(v, nV);
        }
    }
};

bool Ok(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M && !(walls[r][c] == WALL);
}

bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v) {
        return false;
    }
    if (sz[u] < sz[v]) {
        swap(u, v);
    }
    par[v] = u;
    sz[u] += sz[v];

    return true;
};

int Find(int v) {
    return v == par[v] ? v : par[v] = Find(par[v]);
};

void Output() {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (walls[r][c] == EMPTY) {
                cout << 0;
            }
            else {
                unordered_set<int> unq;
                int cnt = 1;

                for (const auto& [dr, dc] : DT4) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (!Ok(nr, nc)) {
                        continue;
                    }
                    unq.insert(Find(nr * M + nc));
                }
                for (auto& p : unq) {
                    cnt += sz[p];
                }
                cout << cnt % 10;
            }
        }
        cout << "\n";
    }
};
