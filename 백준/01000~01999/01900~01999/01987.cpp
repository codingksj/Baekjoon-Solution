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

Words MakeGraph(const int R);
void DFS(const Words& graph, vector<bool>& dfsCheck, const Pii& coord, int count, int& ans);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words graph;
    Pii coord;
    vector<bool> dfsCheck(26, false);
    int R, C;
    int ans = 0;

    cin >> R >> C;

    graph = MakeGraph(R);
    coord = { 0,0 };

    DFS(graph, dfsCheck, coord, 1, ans);

    cout << ans << "\n";

    return 0;
}

Words MakeGraph(const int R) {
    Words graph(R);

    for (string& line : graph) {
        cin >> line;
    }

    return graph;
};

void DFS(const Words& graph, vector<bool>& dfsCheck, const Pii& coord, int count, int& ans) {
    Pii newCoord;
    int dr[] = { -1,0,1,0 };
    int dc[] = { 0,1,0,-1 };
    int nr, nc;
    int r = coord.first, c = coord.second;
    int R = graph.size(), C = graph[0].length();

    ans = max(ans, count);
    dfsCheck[graph[r][c] - 'A'] = true;

    for (int i = 0; i < 4; i++) {
        nr = r + dr[i];
        nc = c + dc[i];

        if (nr >= 0 && nr < R && nc >= 0 && nc < C && !dfsCheck[graph[nr][nc] - 'A']) {
            newCoord = { nr,nc };
            DFS(graph, dfsCheck, newCoord, count + 1, ans);
            dfsCheck[graph[nr][nc] - 'A'] = false;
        }
    }

    return;
};