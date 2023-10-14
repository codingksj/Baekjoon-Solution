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

Matrix2D_i MakeGraph(const int N);
Matrix2D_b MakeBFSCheck(const int N);
bool BFS(const Matrix2D_i& graph, Matrix2D_b& bfsCheck, const int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Matrix2D_i graph;
    Matrix2D_b bfsCheck;
    int N;
    bool canReach;

    cin >> N;

    graph = MakeGraph(N);
    bfsCheck = MakeBFSCheck(N);
    canReach = BFS(graph, bfsCheck, N);

    cout << (canReach ? "HaruHaru" : "Hing") << "\n";

    return 0;
}

Matrix2D_i MakeGraph(const int N) {
    Matrix2D_i graph(N, vector<int>(N, 0));

    for (vector<int>& row : graph) {
        for (int& col : row) {
            cin >> col;
        }
    }

    return graph;
};

Matrix2D_b MakeBFSCheck(const int N) {
    Matrix2D_b bfsCheck(N, vector<bool>(N, false));

    return bfsCheck;
};

bool BFS(const Matrix2D_i& graph, Matrix2D_b& bfsCheck, const int N) {
    queue<Pii> q;
    vector<Pii> deltas = { {0,1},{1,0} };
    Pii start = { 0, 0 }, end = { N - 1, N - 1 };
    int r, c;
    int nr, nc;

    q.push(start);
    bfsCheck[start.first][start.second] = true;

    while (!q.empty()) {
        if (q.front() == end) {
            return true;
        }
        r = q.front().first;
        c = q.front().second;
        q.pop();

        for (const Pii& delta : deltas) {
            nr = r + delta.first * graph[r][c];
            nc = c + delta.second * graph[r][c];
            if (nr < 0 || nr >= N || nc < 0 || nc >= N || bfsCheck[nr][nc]) {
                continue;
            }
            q.push({ nr, nc });
            bfsCheck[nr][nc] = true;
        }
    }

    return false;
};