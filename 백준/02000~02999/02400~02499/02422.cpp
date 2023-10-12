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
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<bool>> Matrix2D_b;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

Matrix2D_b MakeGraph(const int R, const int C);
void InsertEdge(Matrix2D_b& graph, const int v1, const int v2);
int CountPossibleIceCreamCombination(Matrix2D_b& graph, const int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Matrix2D_b graph;
    int N, M;
    int v1, v2;
    int possibleIceCreamCount = 0;

    cin >> N >> M;

    graph = MakeGraph(N, N);

    for (int i = 0; i < M; i++) {
        cin >> v1 >> v2;

        InsertEdge(graph, v1, v2);
    }

    possibleIceCreamCount = CountPossibleIceCreamCombination(graph, N);

    cout << possibleIceCreamCount << "\n";

    return 0;
};

Matrix2D_b MakeGraph(const int R, const int C) {
    Matrix2D_b graph(R + 1, vector<bool>(C + 1, false));

    return graph;
};

void InsertEdge(Matrix2D_b& graph, const int v1, const int v2) {
    graph[v1][v2] = true;
    graph[v2][v1] = true;
};

int CountPossibleIceCreamCombination(Matrix2D_b& graph, const int N) {
    int count = 0;

    for (int c1 = 1; c1 <= N; c1++) {
        for (int c2 = c1 + 1; c2 <= N; c2++) {
            if (graph[c1][c2]) {
                continue;
            }
            for (int c3 = c2 + 1; c3 <= N; c3++) {
                if (graph[c1][c3] || graph[c2][c3]) {
                    continue;
                }
                count++;
            }
        }
    }

    return count;
};