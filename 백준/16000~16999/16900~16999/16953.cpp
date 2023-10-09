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

LL BFS(const LL start, const LL target);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    LL A, B;
    LL opCount;

    cin >> A >> B;

    opCount = BFS(A,B);
    
    cout << opCount << "\n";

    return 0;
}

LL BFS(const LL start, const LL target) {
    queue<PLL> q;
    LL val, opCount;
    LL ans = -1;
    LL path1, path2;

    q.push({ start,1});

    while (!q.empty()) {
        val = q.front().first;
        opCount = q.front().second;

        q.pop();

        if (val == target) {
            ans = opCount;
            break;
        }

        path1 = 2LL * val;
        path2 = 10LL * val + 1LL;

        if (path1 <= target) {
            q.push({ path1, opCount + 1 });
        }
        if (path2 <= target) {
            q.push({ path2, opCount + 1 });
        }
    }

    return ans;
};
