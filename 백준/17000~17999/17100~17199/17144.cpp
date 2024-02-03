#include<bits/stdc++.h>

// ---------- 사용자 정의 상수 ----------
#define PI 3.141592653589793
#define THOUSAND 1E+3
#define MILLION 1E+6
#define BILLION 1E+9
#define TRILLION 1E+12
#define INF 1E+8
#define EPSILON 1E-9

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
typedef vector<bool> Vb;
typedef vector<Vb> VVb;
typedef vector<string> Words;

// ---------- 템플릿 자료형 ----------
template<typename T> struct Matrix2D {
    vector<vector<T>> m2;

    Matrix2D() {};
    Matrix2D(const size_t R, const size_t C, const T INIT) {
        m2 = vector<vector<T>>(R, vector<T>(C, INIT));
    }
};
template<typename T> struct Matrix3D {
    vector<vector<vector<T>>> m3;

    Matrix3D() {};
    Matrix3D(const size_t H, const size_t R, const size_t C, const T INIT) {
        m3 = vector<vector<vector<T>>>(H, vector<vector<T>>(R, vector<T>(C, INIT)));
    }
};

template<typename Number> struct Point2D {
    Number x;
    Number y;

    Point2D() {};
    Point2D(const Number x, const Number y) : x(x), y(y) {};
    Point2D(const pair<Number, Number> p) {
        x = p.first;
        y = p.second;
    }
};


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
template<typename T, typename Compare = less<T>> void StableSortAll(vector<T>& V, Compare cmp = Compare()) {
    stable_sort(V.begin(), V.end(), cmp);
}
template<typename T, typename Compare = less<T>> void StableSortAll2D(vector<vector<T>>& V, Compare cmp = Compare()) {
    for (vector<T>& row : V) {
        StableSort(row, cmp);
    }
}

template<typename T> size_t LowerBoundIndex(const vector<T>& V, const T target) {
    return lower_bound(V.begin(), V.end(), target) - V.begin();
}
template<typename T> size_t UpperBoundIndex(const vector<T>& V, const T target) {
    return upper_bound(V.begin(), V.end(), target) - V.begin();
}

template<typename Number> vector<Number> InitArithmeticSeq(const size_t N, const Number firstTerm = 1, const Number commonDiff = 1) {
    vector<Number> seq(N);

    for (size_t i = 0; i < N; i++) {
        seq[i] = firstTerm + i * commonDiff;
    }

    return seq;
}
template<typename Number> Number CCW(const Point2D<Number>& p1, const Point2D<Number>& p2, const Point2D<Number>& p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
}

// ---------- 사용자 정의 함수 및 연산자 ----------
void Input();
void Solve();
void SpreadDust();
void CleanDust();
void CalcDust();
void Output();

// ---------- 열거형 상수 ----------
enum OBJECTS {
    AC = -1,
    EMPTY = 0
};

// ---------- 전역 변수 ----------
VVi room, diff;
Vi cleaners;
vector<Pii> deltas = {
    Pii(-1,0), Pii(0,1), Pii(1,0), Pii(0,-1)
};
int R, C, T;
int totalDust, obj;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    Input();
    Solve();
    Output();

    return 0;
}

void Input() {
    cin >> R >> C >> T;

    room = Init2DVector<int>(R, C, 0);

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> room[r][c];
            if (room[r][c] == AC) {
                cleaners.push_back(r);
            }
        }
    }
};

void Solve() {
    for (int t = 0; t < T; t++) {
        SpreadDust();
        CleanDust();
    }
    CalcDust();
};

void SpreadDust() {
    int side, dust;
    int nr, nc;

    diff = Init2DVector<int>(R, C, 0);

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            obj = room[r][c];
            dust = obj / 5;
            side = 0;
            if (obj == AC || obj == EMPTY) {
                continue;
            }
            for (const auto& [dr, dc] : deltas) {
                nr = r + dr;
                nc = c + dc;
                if (nr < 0 || nr >= R || nc < 0 || nc >= C || room[nr][nc] == AC) {
                    continue;
                }
                diff[nr][nc] += dust;
                side++;
            }
            diff[r][c] -= side * dust;
        }
    }
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            room[r][c] += diff[r][c];
        }
    }
};

void CleanDust() {
    int up = cleaners[0];
    int down = cleaners[1];
    int nr, nc;
    int npos;

    for (int r = up, c = 1, pos = 1, prev = 0; !(r == up && c == 0); ) {
        swap(prev, room[r][c]);
        for (int i = 0; i < 4; i++) {
            npos = (pos + 3 * i) % 4;
            const auto& [dr, dc] = deltas[npos];
            nr = r + dr;
            nc = c + dc;
            if (nr >= 0 && nr <= up && nc >= 0 && nc < C) {
                pos = npos;
                r = nr, c = nc;
                break;
            }
        }
    }
    for (int r = down, c = 1, pos = 1, prev = 0; !(r == down && c == 0); ) {
        swap(prev, room[r][c]);
        for (int i = 0; i < 4; i++) {
            npos = (pos + i) % 4;
            const auto& [dr, dc] = deltas[npos];
            nr = r + dr;
            nc = c + dc;
            if (nr < R && nr >= down && nc >= 0 && nc < C) {
                pos = npos;
                r = nr, c = nc;
                break;
            }
        }
    }
};


void CalcDust() {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            totalDust += (room[r][c] > 0 ? room[r][c] : 0);
        }
    }
};

void Output() {
    cout << totalDust;
};