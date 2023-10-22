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
vector<int> LoadHouseCounts(const Words& houses, Matrix2D_b& bfsCheck, const Pii& limit);
int BFS(const Words& houses, Matrix2D_b& bfsCheck, const Pii& start, const Pii& limit);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words houses;
    Matrix2D_b bfsCheck;
    vector<int> houseCounts;
    Pii limit;
    int N;

    cin >> N;

    limit = { N, N };
    houses = LoadVector<string>(N);
    bfsCheck = Init2DVector<bool>(N, N, false);
    houseCounts = LoadHouseCounts(houses, bfsCheck, limit);
    Sort(houseCounts);

    cout << houseCounts.size() << "\n";

    PrintVector(houseCounts, "\n");

    return 0;
}

vector<int> LoadHouseCounts(const Words& houses, Matrix2D_b& bfsCheck, const Pii& limit) {
    vector<int> counts;
    Pii start;
    const int R = limit.first;
    const int C = limit.second;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if ((houses[r][c] == '1') && !bfsCheck[r][c]) {
                start = { r, c };
                int count = BFS(houses, bfsCheck, start, limit);
                counts.push_back(count);
            }
        }
    }

    return counts;
}

int BFS(const Words& houses, Matrix2D_b& bfsCheck, const Pii& start, const Pii& limit) {
    queue<Pii> q;
    const int R = limit.first;
    const int C = limit.second;
    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };
    int r = start.first;
    int c = start.second;
    int count = 1;
    bool isValidCoord;

    bfsCheck[r][c] = true;

    q.push(start);

    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            isValidCoord = nr >= 0 && nr < R && nc >= 0 && nc < C;
            if (!isValidCoord || bfsCheck[nr][nc] || houses[nr][nc] == '0') {
                continue;
            }
            count++;
            bfsCheck[nr][nc] = true;
            q.push({ nr, nc });
        }
    }

    return count;
}