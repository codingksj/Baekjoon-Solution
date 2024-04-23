#include<bits/stdc++.h>

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
const LD EPS = 1E-8;
const LL MILLION = 1E+6;
const LL BILLION = 1E+9;
const LL TRILLION = 1E+12;
const LL INF = 1E+8;
const int MAX = 6;
const VPii DT4 = { Pii(-1,0), Pii(0,1), Pii(1,0), Pii(0,-1) };

// ---------- 사용자 정의 함수 및 연산자 ----------
void FastIO();
void SetUp();
bool Input();
void Solve();
void FindIsland();
void BFS(const int start);
bool Ok(const int r, const int c);
void BuildBridge();
void Kruskal();
bool Union(int u, int v);
int Find(int v);
void Output();

// ---------- 전역 변수 ----------
VVi nations, islands, bridges;
vector<Tiii> edges;
Vi par;
Vb visChk;
int iCnt, minBridge;
int R, C;

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
    cin >> R >> C;

    islands = VVi(MAX);
    nations = Load2DVector<int>(R, C);
    bridges = VVi(MAX, Vi(MAX, INF));
    par = Vi(MAX);
    visChk = Vb(R * C, false);

    for (int i = 0; i < MAX; i++) {
        bridges[i][i] = 0;
        par[i] = i;
    }

    return true;
};

void Solve() {
    FindIsland();
    BuildBridge();
    Kruskal();
};

void FindIsland() {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            int pos = r * C + c;
            if (!visChk[pos] && nations[r][c]) {
                BFS(pos);
            }
        }
    }
};

void BFS(const int start) {
    queue<int> q;

    q.push(start);
    islands[iCnt++].push_back(start);

    visChk[start] = true;

    while (!q.empty()) {
        int pos = q.front(); q.pop();
        int r = pos / C;
        int c = pos % C;
        islands[iCnt - 1].push_back(pos);
        nations[r][c] = iCnt;
        for (const auto& [dr, dc] : DT4) {
            int nr = r + dr;
            int nc = c + dc;
            int nPos = nr * C + nc;
            if (!Ok(nr, nc) || visChk[nPos] || !nations[nr][nc]) {
                continue;
            }
            q.push(nPos);
            visChk[nPos] = true;
        }
    }
};

bool Ok(const int r, const int c) {
    return (r >= 0 && r < R) && (c >= 0 && c < C);
};

void BuildBridge() {
    for (int i = 0; i < iCnt;i++) {
        for (const auto& [dr, dc] : DT4) {
            for (auto& pos : islands[i]) {
                int r = pos / C + dr;
                int c = pos % C + dc;
                int length = 1;
                int me = i;
                int other = me;
                while (Ok(r, c)) {
                    if ((other = nations[r][c] - 1) >= 0) {
                        --length;
                        if (other == me || length == 1) {
                            length = INF;
                        }
                        break;
                    }
                    r += dr;
                    c += dc;
                    length++;
                }
                if (other < 0) {
                    continue;
                }
                bridges[me][other] = bridges[other][me] = min(bridges[other][me], length);
            }
        }
    }
};

void Kruskal() {
    for (int i = 0; i < iCnt; i++) {
        for (int j = i + 1; j < iCnt; j++) {
            edges.push_back(Tiii(bridges[i][j], i, j));
        }
    }
    SortAll(edges);

    for (auto& [dist, srcV, destV] : edges) {
        Union(srcV, destV) && (minBridge += dist);
    }

    return;
};

bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v) {
        return false;
    }
    if (u < v) {
        swap(u, v);
    }
    par[u] = v;
    return true;
};

int Find(int v) {
    return v == par[v] ? v : par[v] = Find(par[v]);
};

void Output() {
    cout << (minBridge >= INF ? -1 : minBridge) << "\n";
};
