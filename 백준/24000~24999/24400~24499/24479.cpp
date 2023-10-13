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

void InsertEdge(Matrix2D_i& graph, const int v1, const int v2);
void DFS(Matrix2D_i& graph, vector<int>& isVisited, const int start, int& cnt);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Matrix2D_i graph;
    vector<int> dfsCheck;
    int vertex, edge, start;;
    int v1, v2;
    int count = 0;

    cin >> vertex >> edge >> start;

    graph.resize(vertex + 1);
    dfsCheck.resize(vertex + 1, 0);

    for (int i = 0; i < edge; i++) {
        cin >> v1 >> v2;

        InsertEdge(graph, v1, v2);
    }

    for (int i = 1; i <= vertex; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(graph, dfsCheck, start, count);
    
    for (int i = 1; i <= vertex; i++) {
        cout << dfsCheck[i] << "\n";
    }

    return 0;
}

void InsertEdge(Matrix2D_i& graph, const int v1, const int v2) {
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
};

void DFS(Matrix2D_i& graph, vector<int>& isVisited, const int start, int& cnt) {
    int next;

    if (isVisited[start]) {
        return;
    }

    isVisited[start] = ++cnt;

    for (int i = 0; i < graph[start].size(); i++) {
        next = graph[start][i];

        if (!isVisited[next]) {
            DFS(graph, isVisited, next, cnt);
        }
    }
};