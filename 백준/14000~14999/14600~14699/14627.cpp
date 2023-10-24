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
#include<cmath>
#include<cctype>
#include<cstring>
#include<iomanip>
#include<chrono>

//사용자 정의 상수
#define PI 3.141592653589793
#define THOUSAND 1E+3
#define MILLION 1E+6
#define BILLION 1E+9

using namespace std;

//템플릿 함수
template<typename T> vector<T> InitVector(const int SIZE, const T INIT) { return vector<T>(SIZE, INIT); }
template<typename T> vector<vector<T>> Init2DVector(const int R, const int C, const T INIT) { return vector<vector<T>>(R, vector<T>(C, INIT)); }

template<typename T> vector<T> LoadVector(const int SIZE) { vector<T> V(SIZE); for (T& e : V) { cin >> e; } return V; }
template<typename T> vector<vector<T>> Load2DVector(const int R, const int C) { vector<vector<T>> V(R, vector<T>(C)); for (vector<T>& row : V) { for (T& e : row) { cin >> e; } } return V; }
template<typename T1, typename T2> vector<pair<T1, T2>> LoadPairVector(const int SIZE) { vector<pair<T1, T2>> V(SIZE); for (pair<T1, T2>& p : V) { cin >> p.first >> p.second; } return V; }

template<typename T> void PrintVector(const vector<T>& V, const string seps) { for (const T& e : V) { cout << e << seps; } }
template<typename T> void Print2DVector(const vector<vector<T>>& V, const string sepsR, const string sepsC) { for (const vector<T>& row : V) { for (const T& e : row) { cout << e << sepsC; } cout << sepsR; } }

template<typename T, typename Compare = less<T>> void Sort(vector<T>& V, Compare cmp = Compare()) { sort(V.begin(), V.end(), cmp); }
template<typename T, typename Compare = less<T>> void Sort2D(vector<vector<T>>& V, Compare cmp = Compare()) { for (vector<T>& row : V) { sort(row.begin(), row.end(), cmp); } }
template<typename T, typename Compare = less<T>> void StableSort(vector<T>& V, Compare cmp = Compare()) { stable_sort(V.begin(), V.end(), cmp); }
template<typename T, typename Compare = less<T>> void StableSort2D(vector<vector<T>>& V, Compare cmp = Compare()) { for (vector<T>& row : V) { stable_sort(row.begin(), row.end(), cmp); } }

//사용자 정의 자료형
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

typedef tuple<int, int, int> Tiii;

typedef map<int, int> Mapii;
typedef map<int, string> MapiS;
typedef map<LL, LL> MapLL;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;

typedef unordered_map<LL, LL> HashLL;
typedef unordered_map<string, bool> HashSb;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<bool>> Matrix2D_b;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

//사용자 정의 함수
LL FindProperLength(const vector<LL>& V, const LL M);
LL CountGreenOnionChicken(const vector<LL>& V, const LL length);
LL CalcGreenOnionLeft(const vector<LL>& V, const LL length, const LL M);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<LL> greenOnions;
    LL N, M;
    LL properLength;
    LL greenOnionLength;

    cin >> N >> M;

    greenOnions = LoadVector<LL>(N);
    properLength = FindProperLength(greenOnions, M);
    greenOnionLength = CalcGreenOnionLeft(greenOnions, properLength, M);

    cout << greenOnionLength << "\n";
    
    return 0;
}

LL FindProperLength(const vector<LL>& V, const LL M) {
    LL left = 1;
    LL right = BILLION;
    LL mid, count;
    LL properLength = 0;

    while (left <= right) {
        mid = (left + right) / 2;
        count = CountGreenOnionChicken(V, mid);
        count < M ? (right = mid - 1) : (left = mid + 1, properLength = mid);
    }

    return properLength;
};

LL CountGreenOnionChicken(const vector<LL>& V, const LL length) {
    LL count = 0;

    for (const LL& e : V) {
        count += e / length;
    }

    return count;
};

LL CalcGreenOnionLeft(const vector<LL>& V, const LL length, const LL M) {
    LL greenOnionLength = -M * length;

    for (const LL& e : V) {
        greenOnionLength += e;
    }

    return greenOnionLength;
};