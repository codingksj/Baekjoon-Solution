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

typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

HashSL LoadMarathoners(const int N);
string FindLoser(const HashSL& marathoners);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    HashSL marathoners;
    string loser;
    int N;

    cin >> N;

    marathoners = LoadMarathoners(N);
    loser = FindLoser(marathoners);

    cout << loser << "\n";

    return 0;
}

HashSL LoadMarathoners(const int N) {
    HashSL marathoners;
    string name;

    for (int i = 0; i < 2 * N - 1; i++) {
        cin >> name;
        marathoners[name]++;
    }

    return marathoners;
};

string FindLoser(const HashSL& marathoners) {
    string loser;

    for (const PSL& marathoner : marathoners) {
        if (marathoner.second & 1) {
            loser = marathoner.first;
            break;
        }
    }

    return loser;
};