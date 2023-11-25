#include<iostream>
#include<sstream>
#include<bitset>
#include<set>
#include<unordered_map>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<tuple>
#include<algorithm>
#include<string>
#include<numeric>
#include<functional>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iomanip>
#include<chrono>

// ---------- 사용자 정의 상수 ----------
#define PI 3.141592653589793
#define THOUSAND 1E+3
#define MILLION 1E+6
#define BILLION 1E+9
#define INF 1E+8
#define VERTEX 8

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

// ---------- 사용자 정의 함수 및 연산자 ----------
Matrix2D<LL> MakeGraph(const Matrix2D<LL>& adj);
Matrix2D<LL> Multiplication(const Matrix2D<LL> A, const Matrix2D<LL> B, const LL MOD);
Matrix2D<LL> Power(Matrix2D<LL> A, const LL exp, const LL MOD);

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    Matrix2D<LL> adj, graph, res;
    const LL MOD = BILLION + 7;
    LL pathLength, wayCount;

    cin >> pathLength;

    adj.m2 = {
        {1,4},
        {0,2,5},
        {1,3,5,6},
        {2,6,7},
        {0,5},
        {1,2,4,6},
        {2,3,5,7},
        {3,6}
    };

    graph = MakeGraph(adj);
    res = Power(graph, pathLength, MOD);
    wayCount = res.m2[VERTEX - 1][VERTEX - 1];

    cout << wayCount << "\n";

    return 0;
}

Matrix2D<LL> MakeGraph(const Matrix2D<LL>& adj) {
    Matrix2D<LL> graph = Matrix2D<LL>(VERTEX, VERTEX, 0);

    for (int i = 0; i < VERTEX; i++) {
        for (const int& v : adj.m2[i]) {
            graph.m2[v][i] = graph.m2[i][v] = 1;
        }
    }

    return graph;
};

Matrix2D<LL> Multiplication(const Matrix2D<LL> A, const Matrix2D<LL> B, const LL MOD) {
    Matrix2D<LL> res;

    res = Matrix2D<LL>(VERTEX, VERTEX, 0);

    for (int i = 0; i < VERTEX; i++) {
        for (int j = 0; j < VERTEX; j++) {
            for (int k = 0; k < VERTEX; k++) {
                res.m2[i][j] += (A.m2[i][k] * B.m2[k][j]) % MOD;
                res.m2[i][j] %= MOD;
            }
        }
    }

    return res;
};

Matrix2D<LL> Power(Matrix2D<LL> A, const LL exp, const LL MOD) {
    vector<Matrix2D<LL>> powers;
    Matrix2D<LL> res;
    LL d = exp;
    size_t size;

    res = Matrix2D<LL>(VERTEX, VERTEX, 0);

    for (int i = 0; i < VERTEX; i++) {
        res.m2[i][i] = 1;
    }

    powers.push_back(A);
    
    while (d > 0) {
        A = Multiplication(A, A, MOD);
        powers.push_back(A);
        d >>= 1;
    }

    size = powers.size();

    for (size_t i = 0; i < size; i++) {
        if (exp & (1LL << i)) {
            res = Multiplication(res, powers[i], MOD);
        }
    }
  
    return res;
};
