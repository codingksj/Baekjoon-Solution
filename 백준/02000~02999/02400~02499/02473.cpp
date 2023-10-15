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
template<typename T> vector<T> InitVector(const int SIZE, const T INIT) { return vector<T>(SIZE, INIT);}
template<typename T> vector<vector<T>> Init2DVector(const int R, const int C, const T INIT) { return vector<vector<T>>(R, vector<T>(C,INIT)); }

template<typename T> vector<T> LoadVector(const int SIZE) { vector<T> V(SIZE); for (T& e : V) { cin >> e; } return V; }
template<typename T> vector<vector<T>> Load2DVector(const int R, const int C) { vector<vector<T>> V(R, vector<T>(C)); for (vector<T>& row : V) { for (T& e : row) { cin >> e; } } return V; }
template<typename T1, typename T2> vector<pair<T1, T2>> LoadPairVector(const int SIZE) { vector<pair<T1, T2>> V(SIZE); for (pair<T1, T2>& p : V) { cin >> p.first >> p.second; } return V; }

template<typename T, typename Compare = less<T>> void Sort(vector<T>& V, Compare cmp = Compare()) { sort(V.begin(), V.end(), cmp); }

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

typedef struct Triple {
    LL a;
    LL b;
    LL c;
}Triple;

//사용자 정의 함수
Triple FindMostNeutralTriple(vector<LL>& V, const int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<LL> V;
    Triple triple;
    int N;

    cin >> N;

    V = LoadVector<LL>(N);
    Sort(V);
    triple = FindMostNeutralTriple(V, N);

    cout << triple.a << " " << triple.b << " " << triple.c << "\n";

    return 0;
}

Triple FindMostNeutralTriple(vector<LL>& V, const int N) {
    Triple ans = { V[0], V[1], V[2] };
    LL minSum = abs(V[0] + V[1] + V[2]), sum;
    int L, R;

    for (int k = 0; k < N - 2; k++) {
        L = k + 1;
        R = N - 1;
        while (L < R) {
            sum = V[k] + V[L] + V[R];
            if (abs(sum) < minSum) {
                minSum = abs(sum);
                ans = { V[k], V[L], V[R] };
            }
            (sum < 0) ? L++ : R--;
        }
    }

    return ans;
};