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
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

void InsertEdge(Matrix2D_i& graph, const int v1, const int v2);
void DFS(Matrix2D_i& graph, vector<bool>& isVisited, vector<int>& course, const int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Matrix2D_i graph;
    vector<int> dfsCourse;
    vector<bool> dfsCheck;
    int vertex, edge;
    int v1, v2;
    int infectedCount;

    cin >> vertex >> edge;

    graph.resize(vertex + 1);
    dfsCheck.resize(vertex + 1, false);

    for (int i = 0; i < edge; i++) {
        cin >> v1 >> v2;

        InsertEdge(graph, v1, v2);
    }

    DFS(graph, dfsCheck, dfsCourse, 1);

    infectedCount = dfsCourse.size() - 1;

    cout << infectedCount << "\n";

    return 0;
}

void InsertEdge(Matrix2D_i& graph, const int v1, const int v2) {
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
};

void DFS(Matrix2D_i& graph, vector<bool>& isVisited, vector<int>& course, const int N) {
    int next;

    if (isVisited[N]) {
        return;
    }

    course.push_back(N);
    isVisited[N] = true;

    for (int i = 0; i < graph[N].size(); i++) {
        next = graph[N][i];

        if (!isVisited[next]) {
            DFS(graph, isVisited, course, next);
        }
    }
};
