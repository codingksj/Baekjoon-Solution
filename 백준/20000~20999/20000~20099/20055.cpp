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
int FindLevel(const int N, const int K);
void RotateBelt(deque<int>& belt, deque<bool>& robots, const int N);
void MoveRobot(deque<int>& belt, deque<bool>& robots, const int N, int& cnt);
void DisposeRobot(deque<int>& belt, deque<bool>& robots, int& cnt);

// ---------- 열거형 상수 ----------

// ---------- 전역 변수 ----------

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, K;
    int level;

    cin >> N >> K;

    level = FindLevel(N, K);

    cout << level;

    return 0;
}

int FindLevel(const int N, const int K) {
    deque<int> belt;
    deque<bool> robots;
    int durability;
    int cnt = 0;
    int level = 0;

    for (int i = 0; i < 2 * N; i++) {
        cin >> durability;

        belt.push_back(durability);
        robots.push_back(false);
    }

    while (cnt < K) {
        level++;

        RotateBelt(belt, robots, N);
        MoveRobot(belt, robots, N, cnt);
        DisposeRobot(belt, robots, cnt);
    }

    return level;
};

void RotateBelt(deque<int>& belt, deque<bool>& robots, const int N) {
    belt.push_front(belt.back());
    belt.pop_back();
    robots.push_front(robots.back());
    robots.pop_back();
    robots[N - 1] = false;
};

void MoveRobot(deque<int>& belt, deque<bool>& robots, const int N, int& cnt) {
    for (int next = N - 1, cur = N - 2; next >= 1 && cur >= 0; next--, cur--) {
        if (robots[cur] && !robots[next] && belt[next]) {
            robots[cur] = false;
            robots[next] = true;
            belt[next]--;
            !belt[next] && cnt++;
        }
    }
    robots[N - 1] = false;
};

void DisposeRobot(deque<int>& belt, deque<bool>& robots, int& cnt) {
    int start = 0;

    if (!robots[start] && belt[start]) {
        robots[start] = true;
        belt[start]--;
        !belt[start] && cnt++;
    }
};