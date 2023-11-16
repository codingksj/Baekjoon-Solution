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

//---------- 사용자 정의 상수 ----------
#define PI 3.141592653589793
#define THOUSAND 1E+3
#define MILLION 1E+6
#define BILLION 1E+9
#define WALL 1
#define EMPTY 0

//---------- 사용자 정의 자료형 ----------
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

typedef struct Info {
    int r;
    int c;
    int object;
    int distance;
}Info;

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
template<typename T1, typename T2> void PrintVector(const vector<pair<T1, T2>>& V, const string sepsC, const string sepsPair) {
    for (const pair<T1, T2>& p : V) {
        PrintPair<T1, T2>(p, sepsPair);
        cout << sepsC;
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

template<typename T, typename Compare = less<T>> void Sort(vector<T>& V, Compare cmp = Compare()) { 
    sort(V.begin(), V.end(), cmp); 
}
template<typename T, typename Compare = less<T>> void Sort2D(vector<vector<T>>& V, Compare cmp = Compare()) { 
    for (vector<T>& row : V) { 
        Sort(row, cmp); 
    } 
}
template<typename T, typename Compare = less<T>> void StableSort(vector<T>& V, Compare cmp = Compare()) { 
    stable_sort(V.begin(), V.end(), cmp); 
}
template<typename T, typename Compare = less<T>> void StableSort2D(vector<vector<T>>& V, Compare cmp = Compare()) { 
    for (vector<T>& row : V) { 
        StableSort(row, cmp); 
    } 
}

template<typename T> size_t LowerBoundIndex(const vector<T>& V, const T target) { 
    const size_t index = lower_bound(V.begin(), V.end(), target) - V.begin(); 
    return index; 
}
template<typename T> size_t UpperBoundIndex(const vector<T>& V, const T target) { 
    const size_t index = upper_bound(V.begin(), V.end(), target) - V.begin(); return index; 
}

// ---------- 사용자 정의 함수 ----------
void InsertEdge(Matrix2D<int>& graph, const int v1, const int v2, const int weight);
void Dijkstra(const Matrix2D<int>& graph, vector<int>& dists, const int V, const int vStart);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Matrix2D<int> graph;
    vector<int> dists;
    int minDist;
    int V, E;
    int vStart, vEnd, weight;
    int v1, v2;

    cin >> V >> E;

    dists = InitVector<int>(V, BILLION);
    graph.m2 = Init2DVector<int>(V, V, BILLION);

    for (int v = 0; v < V; v++) {
        graph.m2[v][v] = 0;
    }

    for (int e = 0; e < E; e++) {
        cin >> v1 >> v2 >> weight;
        InsertEdge(graph, v1 - 1, v2 - 1, weight);
    }

    cin >> vStart >> vEnd;
    Dijkstra(graph, dists, V, vStart - 1);

    minDist = dists[vEnd - 1];

    cout << minDist << "\n";

    return 0;
}

void InsertEdge(Matrix2D<int>& graph, const int v1, const int v2, const int weight) {
    graph.m2[v1][v2] = min(graph.m2[v1][v2], weight);
};

void Dijkstra(const Matrix2D<int>& graph, vector<int>& dists, const int V, const int vStart) {
    priority_queue<Pii, vector<Pii>, greater<Pii>> pq;
    int v, nV, cost, w;

    pq.push({ 0, vStart });
    dists[vStart] = 0;

    while (!pq.empty()) {
        v = pq.top().second;
        cost = pq.top().first;
        pq.pop();

        for (int i = 0; i < V; i++) {
            nV = i;
            w = graph.m2[v][nV];

            if (w == BILLION) {
                continue;
            }

            if (dists[nV] > cost + w) {
                dists[nV] = cost + w;
                pq.push({ cost + w, nV });
            }
        }
    }
};