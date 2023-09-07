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

typedef map<int, string> MapiS;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;

typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    deque<Pii> DQ;
    int N, move;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> move;
        DQ.push_back({ i, move });
    }

    while (true) {
        move = DQ.front().second;

        cout << DQ.front().first << " ";

        DQ.pop_front();

        if (DQ.empty()) {
            break;
        }

        if (move > 0) {
            for (int i = 0; i < move - 1; i++) {
                DQ.push_back(DQ.front());
                DQ.pop_front();
            }
        }
        else {
            for (int i = 0; i < abs(move); i++) {
                DQ.push_front(DQ.back());
                DQ.pop_back();
            }
        }
    }

    return 0;
}
