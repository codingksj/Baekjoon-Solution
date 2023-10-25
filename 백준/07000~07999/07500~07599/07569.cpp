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
typedef vector<Matrix2D_b> Matrix3D_b;
typedef vector<Matrix2D_i> Matrix3D_i;

typedef struct Coord3D {
    int r;
    int c;
    int h;
}Coord3D;

//사용자 정의 함수
Matrix3D_i MakeTomatoes(const Coord3D& limit);
Matrix3D_b MakeBFSCheck(const Matrix3D_i& tomatoes, const Coord3D& limit);
int BFS(const Matrix3D_i& tomatoes, Matrix3D_b& bfsCheck, const Coord3D& limit);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Matrix3D_i tomatoes;
    Matrix3D_b bfsCheck;
    Coord3D limit;
    int R, C, H, day;

    cin >> C >> R >> H;

    limit = { R,C,H };
    tomatoes = MakeTomatoes(limit);
    bfsCheck = MakeBFSCheck(tomatoes, limit);
    day = BFS(tomatoes, bfsCheck, limit);

    cout << day << "\n";

    return 0;
}

Matrix3D_i MakeTomatoes(const Coord3D& limit) {
    Matrix3D_i tomatoes;
    const int R = limit.r;
    const int C = limit.c;
    const int H = limit.h;

    tomatoes.resize(H);

    for (int i = 0; i < H; i++) {
        tomatoes[i] = Load2DVector<int>(R, C);
    }

    return tomatoes;
};

Matrix3D_b MakeBFSCheck(const Matrix3D_i& tomatoes, const Coord3D& limit) {
    Matrix3D_b bfsCheck;
    const int R = limit.r;
    const int C = limit.c;
    const int H = limit.h;

    bfsCheck.resize(H, Matrix2D_b(R, vector<bool>(C, false)));

    for (int h = 0; h < H; h++) {
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                bfsCheck[h][r][c] = tomatoes[h][r][c];
            }
        }
    }

    return bfsCheck;
};

int BFS(const Matrix3D_i& tomatoes, Matrix3D_b& bfsCheck, const Coord3D& limit) {
    queue<pair<Coord3D, int>> q;
    Coord3D cur;
    int dr[] = { -1,0,1,0,0,0 };
    int dc[] = { 0,1,0,-1,0,0 };
    int dh[] = { 0,0,0,0,-1,1 };
    const int R = limit.r;
    const int C = limit.c;
    const int H = limit.h;
    const int MAX = R * C * H;
    int r, c, h;
    int nr, nc, nh;
    int day = 0;
    int count = 0;
    bool isValidCoord;

    for (h = 0; h < H; h++) {
        for (r = 0; r < R; r++) {
            for (c = 0; c < C; c++) {
                if (tomatoes[h][r][c] == 1) {
                    q.push({ { r,c,h }, 0 });
                }
                abs(tomatoes[h][r][c]) && count++;
            }
        }
    }

    while (!q.empty()) {
        cur = q.front().first;
        day = q.front().second;
        r = cur.r;
        c = cur.c;
        h = cur.h;
        q.pop();
        for (int i = 0; i < 6; i++) {
            nr = r + dr[i];
            nc = c + dc[i];
            nh = h + dh[i];
            isValidCoord = (nr >= 0 && nr < R) && (nc >= 0 && nc < C) && (nh >= 0 && nh < H);
            if (isValidCoord && !bfsCheck[nh][nr][nc]) {
                bfsCheck[nh][nr][nc] = true;
                q.push({ { nr,nc,nh }, day + 1 });
                count++;
            }
        }
    }

    day = (count < MAX) ? -1 : day;

    return day;
};