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

typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<bool> Vb;
typedef vector<Vb> VVb;
typedef vector<string> Words;
typedef vector<Pii> VPii;
typedef vector<VPii> VVPii;

typedef struct Fish {
    int r, c, dist, sz;

    Fish() {
        r = c = dist = sz = 0;
    };
    Fish(const int r, const int c, const int dist, const int sz) {
        this->r = r;
        this->c = c;
        this->dist = dist;
        this->sz = sz;
    }
    bool operator< (const Fish& other) const {
        if (dist != other.dist) {
            return dist > other.dist;
        }
        if (r != other.r) {
            return r > other.r;
        }
        if (c != other.c) {
            return c > other.c;
        }
        return sz < other.sz;
    }
}Fish;
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
const VPii DT4 = { Pii(-1,0), Pii(0,1), Pii(1,0), Pii(0,-1) };
enum OBJ {
    EMPTY = '.',
    WALL = '*',
    DOC = '$'
};

// ---------- 사용자 정의 함수 및 연산자 ----------
void FastIO();
bool Input();
void Solve();
void Steal(const int sr, const int sc);
bool CheckOpen(const int r, const int c);
bool CheckKey(const int r, const int c);
bool CheckDoc(const int r, const int c);
void Output();

// ---------- 전역 변수 ----------
Words B;
set<int> G;
Vb keys;
string k;
int TC, R, C;
int totalDoc, stealDoc;
bool hasChange, isEdge;

int main() {
    FastIO();

    cin >> TC;
    
    while(TC--) {
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

bool Input() {
    cin >> R >> C;

    B = Words(R, string(C, '*'));
    G = set<int>();
    stealDoc = 0;
    totalDoc = 0;
    hasChange = true;
    keys = Vb(26, false);

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> B[r][c];
            isEdge = r == 0 || r == R - 1 || c == 0 || c == C - 1;
            if (isEdge && B[r][c] != WALL) {
                G.insert(r * C + c);
            }
            if (B[r][c] == DOC) {
                totalDoc++;
            }
        }
    }

    cin >> k;

    if (k != "0") {
        for (const auto& key : k) {
            keys[key - 'a'] = true;
        }
    }

    return true;
};

void Solve() {
    while (totalDoc && hasChange) {
        hasChange = false;
        for (const auto& coord : G) {
            int sr = coord / C;
            int sc = coord % C;
            if (CheckOpen(sr, sc) || CheckKey(sr, sc) || CheckDoc(sr, sc)) {
                B[sr][sc] = EMPTY;
            }
            if (B[sr][sc] == EMPTY) {
                Steal(sr, sc);
            }
        }
    }
}

void Steal(const int sr, const int sc) {
    queue<Pii> q;
    VVb bfsChk = Init2DVector<bool>(R, C, false);

    bfsChk[sr][sc] = true;

    q.push(Pii(sr, sc));

    while (!q.empty()) {
        const auto [r, c] = q.front(); q.pop();

        for (const auto& [dr, dc] : DT4) {
            int nr = r + dr;
            int nc = c + dc;
            if (nr < 0 || nr >= R || nc < 0 || nc >= C || bfsChk[nr][nc]) {
                continue;
            }
            switch (B[nr][nc]) {
            case WALL:
                break;
            case EMPTY:
                q.push(Pii(nr, nc));
                bfsChk[nr][nc] = true;
                break;
            default:
                if (CheckOpen(nr, nc) || CheckKey(nr, nc) || CheckDoc(nr, nc)) {
                    q.push(Pii(nr, nc));
                    bfsChk[nr][nc] = true;
                    hasChange = true;
                    B[nr][nc] = EMPTY;
                }
            }
            isEdge = r == 0 || r == R - 1 || c == 0 || c == C - 1;
            if (isEdge && B[r][c] != WALL) {
                G.insert(r * C + c);
            }
        }
    }
};

bool CheckOpen(const int r, const int c) {
    return isupper(B[r][c]) && keys[B[r][c] - 'A'];
};

bool CheckKey(const int r, const int c) {
    if (islower(B[r][c])) {
        return keys[B[r][c] - 'a'] = true;
    }
    return false;
}

bool CheckDoc(const int r, const int c) {
    if (B[r][c] == DOC) {
        totalDoc--;
        stealDoc++;
        return true;
    }
    return false;
}

void Output() {
    cout << stealDoc << "\n";
};