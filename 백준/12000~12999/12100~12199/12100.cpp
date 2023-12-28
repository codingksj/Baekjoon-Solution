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
typedef pair<int, string> PiS;
typedef pair<double, double> Pdd;
typedef pair<double, int> Pdi;
typedef pair<LL, LL> PLL;
typedef pair<string, int> PSi;
typedef pair<string, LL> PSL;
typedef pair<string, string> PSS;

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
    const size_t index = lower_bound(V.begin(), V.end(), target) - V.begin();
    return index;
}
template<typename T> size_t UpperBoundIndex(const vector<T>& V, const T target) {
    const size_t index = upper_bound(V.begin(), V.end(), target) - V.begin();
    return index;
}

template<typename Number> vector<Number> InitArithmeticSeq(const size_t N, const Number firstTerm = 1, const Number commonDiff = 1) {
    vector<Number> seq;

    for (size_t i = 0; i < N; i++) {
        seq.push_back(firstTerm + i * commonDiff);
    }

    return seq;
}
template<typename Number> Number CCW(const Point2D<Number>& a, const Point2D<Number>& b, const Point2D<Number>& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// ---------- 사용자 정의 함수 및 연산자 ----------
Matrix2D<int> MoveBoard(Matrix2D<int> board, const int dir);
void Move(Matrix2D<int>& board, const int dir);
void Merge(Matrix2D<int>& board, const int dir);
void DFS(Matrix2D<int> board, const int depth);
void CalcMaxCell(const Matrix2D<int>& board);

// ---------- 열거형 상수 ----------
enum DIRECTIONS {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

// ---------- 전역 변수 ----------
vector<int> dirs = { UP, RIGHT, DOWN, LEFT };
const int MAX_DEPTH = 5;
int N;
int maxCell = 2;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    Matrix2D<int> board;

    cin >> N;

    board.m2 = Load2DVector<int>(N, N);

    DFS(board, 0);

    cout << maxCell << "\n";

    return 0;
}

Matrix2D<int> MoveBoard(Matrix2D<int> board, const int dir) {
    Move(board, dir);
    Merge(board, dir);
    Move(board, dir);

    return board;
};

void Move(Matrix2D<int>& board, const int dir) {
    int nr, nc;
    int startIdx = (dir == UP || dir == LEFT) ? 1 : N - 2;
    int increment = (dir == UP || dir == LEFT) ? 1 : -1;

    switch (dir) {
    case UP:
    case DOWN:
        for (int c = 0; c < N; c++) {
            for (int r = startIdx; r >= 0 && r < N; r += increment) {
                for (nr = r - increment; nr >= 0 && nr < N && !board.m2[nr][c]; nr -= increment) {}
                nr += increment;
                if (nr == r) {
                    continue;
                }
                board.m2[nr][c] = board.m2[r][c];
                board.m2[r][c] = 0;
            }
        }
        break;

    case LEFT:
    case RIGHT:
        for (int r = 0; r < N; r++) {
            for (int c = startIdx; c >= 0 && c < N; c += increment) {
                for (nc = c - increment; nc >= 0 && nc < N && !board.m2[r][nc]; nc -= increment) {}
                nc += increment;
                if (nc == c) {
                    continue;
                }
                board.m2[r][nc] = board.m2[r][c];
                board.m2[r][c] = 0;
            }
        }
        break;
    default:
        break;
    }
}

void Merge(Matrix2D<int>& board, const int dir) {
    int startIdx = (dir == UP || dir == LEFT) ? 1 : N - 2;
    int increment = (dir == UP || dir == LEFT) ? 1 : -1;

    switch (dir) {
    case UP:
    case DOWN:
        for (int c = 0; c < N; c++) {
            for (int r = startIdx; r >= 0 && r < N; r += increment) {
                if (board.m2[r - increment][c] == board.m2[r][c]) {
                    board.m2[r - increment][c] <<= 1;
                    board.m2[r][c] = 0;
                }
            }
        }
        break;
    case LEFT:
    case RIGHT:
        for (int r = 0; r < N; r++) {
            for (int c = startIdx; c >= 0 && c < N; c += increment) {
                if (board.m2[r][c - increment] == board.m2[r][c]) {
                    board.m2[r][c - increment] <<= 1;
                    board.m2[r][c] = 0;
                }
            }
        }
        break;
    default:
        break;
    }
};

void DFS(Matrix2D<int> board, const int depth) {
    if (depth == MAX_DEPTH) {
        CalcMaxCell(board);
        return;
    }
    for (const int& dir : dirs) {
        DFS(MoveBoard(board, dir), depth + 1);
    }
};

void CalcMaxCell(const Matrix2D<int>& board) {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            maxCell = max(maxCell, board.m2[r][c]);
        }
    }
};