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
    EMPTY = 0,
    SHARK = 9
};


// ---------- 사용자 정의 함수 및 연산자 ----------
void FastIO();
bool Input();
void Solve();
void Find();
void Output();

// ---------- 전역 변수 ----------
priority_queue<Fish> fishes;
VVi ocean, dists;
Fish shark;
int N, eatTime, eatCnt;

int main() {
    FastIO();

    Input();
    Solve();
    Output();

    return 0;
}

void FastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
};

bool Input() {
    cin >> N;

    ocean = VVi(N, Vi(N));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> ocean[r][c];
            if (ocean[r][c] == EMPTY) {
                continue;
            }
            if (ocean[r][c] == SHARK) {
                shark = Fish(r, c, 0, 2);
            }
        }
    }

    return true;
};

void Solve() {
    for (eatTime = 0;; eatTime += fishes.top().dist) {
        int sr = shark.r;
        int sc = shark.c;

        dists = Init2DVector<int>(N, N, -1);
        dists[sr][sc] = 0;
        ocean[sr][sc] = EMPTY;
        fishes = priority_queue<Fish>();

        Find();

        if (fishes.empty()) {
            return;
        }

        auto& [nr, nc, dist, __] = fishes.top();

        if (++eatCnt >= shark.sz) {
            shark.sz++;
            eatCnt = 0;
        }

        ocean[nr][nc] = EMPTY;
        shark = Fish(nr, nc, 0, shark.sz);
    }
}

void Find() {
    queue<Pii> q;

    q.push(Pii(shark.r, shark.c));

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (const auto& [dr, dc] : DT4) {
            int nr = r + dr;
            int nc = c + dc;
            if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                continue;
            }
            if (dists[nr][nc] != -1 || ocean[nr][nc] > shark.sz) {
                continue;
            }
            dists[nr][nc] = dists[r][c] + 1;
            q.push({ nr, nc });
            if (ocean[nr][nc] != EMPTY && ocean[nr][nc] < shark.sz) {
                fishes.push(Fish(nr, nc, dists[nr][nc], ocean[nr][nc]));
            }
        }
    }
}

void Output() {
    cout << eatTime << "\n";
};