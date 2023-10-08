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

typedef map<int, int> Mapii;
typedef map<int, string> MapiS;
typedef map<LL, LL> MapLL;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;

typedef unordered_map<LL, LL> HashLL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<bool>> Matrix2D_b;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

typedef struct TomatoInfo {
    int r;
    int c;
    int day;
}TomatoInfo;

Matrix2D_i MakeTomatoes(const int N, const int M);
Matrix2D_i MakeTomatoesCheck(const Matrix2D_i& tomatoes, const int N, const int M);
int BFS(const Matrix2D_i& tomatoes, Matrix2D_i& tomatoesCheck, const int N, const int M);
bool CheckAllTomatoesRipen(const Matrix2D_i& tomatoesCheck);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Matrix2D_i tomatoes, tomatoesCheck;
    int N, M;
    int day;

    cin >> M >> N;

    tomatoes = MakeTomatoes(N, M);
    tomatoesCheck = MakeTomatoesCheck(tomatoes, N, M);
    day = BFS(tomatoes, tomatoesCheck, N, M);

    cout << day << "\n";

    return 0;
}

Matrix2D_i MakeTomatoes(const int N, const int M) {
    Matrix2D_i tomatoes(N, vector<int>(M, 0));

    for (vector<int>& row : tomatoes) {
        for (int& col : row) {
            cin >> col;
        }
    }

    return tomatoes;
};

Matrix2D_i MakeTomatoesCheck(const Matrix2D_i& tomatoes, const int N, const int M) {
    Matrix2D_i tomatoesCheck(N, vector<int>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (abs(tomatoes[i][j])) {
                tomatoesCheck[i][j] = true;
            }
        }
    }

    return tomatoesCheck;
};

int BFS(const Matrix2D_i& tomatoes, Matrix2D_i& tomatoesCheck, const int N, const int M) {
    queue<TomatoInfo> q;
    int dx[] = { 0,1,0,-1 };
    int dy[] = { -1,0,1,0 };
    int x, y, nx, ny;
    int day = 0;
    
    if (CheckAllTomatoesRipen(tomatoesCheck)) {
        return day;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tomatoes[i][j] == 1) {
                q.push({ i,j,0 });
            }
        }
    }

    while (!q.empty()) {
        x = q.front().c;
        y = q.front().r;
        day = q.front().day;

        q.pop();

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < M && ny < N && !tomatoesCheck[ny][nx] && !tomatoes[ny][nx]) {
                tomatoesCheck[ny][nx] = true;
                q.push({ ny, nx, day + 1 });
            }
        }
    }

    day = CheckAllTomatoesRipen(tomatoesCheck) ? day : -1;

    return day;
};

bool CheckAllTomatoesRipen(const Matrix2D_i& tomatoesCheck) {
    for (const vector<int>& row : tomatoesCheck) {
        for (const int& col : row) {
            if (!col) {
                return false;
            }
        }
    }

    return true;
};