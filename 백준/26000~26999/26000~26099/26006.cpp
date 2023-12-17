#include<bits/stdc++.h>

// ---------- 사용자 정의 상수 ----------
#define PI 3.141592653589793
#define THOUSAND 1E+3
#define MILLION 1E+6
#define BILLION 1E+9
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

// ---------- 열거형 상수 ----------

// ---------- 사용자 정의 함수 및 연산자 ----------
string FindStatus(const Pii& king, const vector<Pii>& queens, const int N);
Pii operator+ (const Pii& p1, const Pii& p2);
bool operator< (const Pii& p1, const Pii& p2);

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<Pii> queens;
    Pii king;
    string status;
    int N, Q;

    cin >> N >> Q;

    king = LoadPair<int, int>();
    queens = LoadVector<int, int>(Q);
    status = FindStatus(king, queens, N);

    cout << status << "\n";

    return 0;
}

string FindStatus(const Pii& king, const vector<Pii>& queens, const int N) {
    string status = "NONE";
    vector<Pii> moves = { {0, 1}, {0, -1}, {1, 0}, {-1, 0},
                         {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
    Pii movedKing;
    Pii edge1 = { 0,0 };
    Pii edge2 = { N + 1, N + 1 };
    int dr, dc;
    int maxCheck = 8;
    int check = 0;
    bool canMove = true;
    bool canStay = true;

    for (const Pii& move : moves) {
        movedKing = (king + move);
        canMove = true;

        if (!(edge1 < movedKing && movedKing < edge2)) {
            maxCheck--;
            continue;
        }

        for (const Pii& queen : queens) {
            dr = queen.first - movedKing.first;
            dc = queen.second - movedKing.second;
            if (!dr || !dc || (abs(dc) == abs(dr))) {
                canMove = false;
                break;
            }
        }

        !canMove && check++;
    }

    for (const Pii& queen : queens) {
        dr = queen.first - king.first;
        dc = queen.second - king.second;
        if (!dr || !dc || (abs(dc) == abs(dr))) {
            canStay = false;
            break;
        }
    }
  
    status = canStay ?
        ((check < maxCheck) ? "NONE" : "STALEMATE") :
        ((check < maxCheck) ? "CHECK" : "CHECKMATE");

    return status;
};


Pii operator+ (const Pii& p1, const Pii& p2) {
    return Pii(p1.first + p2.first, p1.second + p2.second);
};

bool operator< (const Pii& p1, const Pii& p2) {
    return (p1.first < p2.first && p1.second < p2.second);
};