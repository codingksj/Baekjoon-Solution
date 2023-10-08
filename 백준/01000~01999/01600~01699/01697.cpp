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

#define MAX 100000

int BFS(vector<bool>& isVisited, const int N, const int K);
bool CheckPathValidness(vector<bool>& isVisited, const int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<bool> bfsCheck;
    int N, K, time;

    cin >> N >> K;

    bfsCheck.resize(MAX + 1, false);

    time = BFS(bfsCheck, N, K);

    cout << time << "\n";

    return 0;
}

int BFS(vector<bool>& isVisited, const int N, const int K) {
    vector<int> paths(3);
    queue<Pii> q;
    int pos, time;

    q.push({ N,0 });
    isVisited[N] = true;

    while (!q.empty()) {
        pos = q.front().first;
        time = q.front().second;
        q.pop();

        if (pos == K) {
            break;
        }

        paths[0] = pos - 1;
        paths[1] = pos + 1;
        paths[2] = 2 * pos;

        for (const int& path : paths) {
            if (CheckPathValidness(isVisited, path)) {
                isVisited[path] = true;
                q.push({ path, time + 1 });
            }
        }
    }

    return time;
};

bool CheckPathValidness(vector<bool>& isVisited, const int N) {
    bool isValid = (N >= 0 && N <= MAX && !isVisited[N]);

    return isValid;
};