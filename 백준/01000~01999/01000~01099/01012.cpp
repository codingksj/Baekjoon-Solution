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

Matrix2D_i MakeGraph(const int N, const int M);
Matrix2D_b MakeDFSCheck(const int N, const int M);
void InsertEdge(Matrix2D_i& graph, const int x, const int y);
void DFS(Matrix2D_i& graph, Matrix2D_b& isVisited,  const int x, const int y);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Matrix2D_i graph;
    Matrix2D_b dfsCheck;
    int TC, N, M, edge;
    int X, Y;
    int count;

    cin >> TC;

    while (TC--) {
        cin >> M >> N >> edge;

        count = 0;
        graph = MakeGraph(N, M);
        dfsCheck = MakeDFSCheck(N, M);

        while (edge--) {
            cin >> X >> Y;
            InsertEdge(graph, X, Y);
        }

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (graph[y][x] && !dfsCheck[y][x]) {
                    count++;
                    DFS(graph, dfsCheck, x, y);
                }
            }
        }
        cout << count << "\n";
    }

    return 0;
}

Matrix2D_i MakeGraph(const int N, const int M) {
    Matrix2D_i graph(N, vector<int>(M, 0));

    return graph;
};
Matrix2D_b MakeDFSCheck(const int N, const int M) {
    Matrix2D_b dfsCheck(N, vector<bool>(M, 0));

    return dfsCheck;
};

void InsertEdge(Matrix2D_i& graph, const int x, const int y) {
    graph[y][x] = 1;
};

void DFS(Matrix2D_i& graph, Matrix2D_b& isVisited, const int x, const int y) {
    int dx[] = { 0,1,0,-1 };
    int dy[] = { -1,0,1,0 };
    int nx, ny;
    int N = graph.size();
    int M = graph[0].size();

    isVisited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= M || ny >= N || isVisited[ny][nx] || !graph[ny][nx]) {
            continue;
        }
        DFS(graph, isVisited, nx, ny);
    }
    return;
};