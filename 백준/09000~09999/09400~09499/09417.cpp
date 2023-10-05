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

vector<LL> LoadNumbers(const string& line);
LL FindMaxGCD(const vector<LL>& V);
LL GCD(const LL a, const LL b);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<LL> V;
    string line;
    LL maxGCD;
    int TC;

    cin >> TC;
    cin.ignore();

    while (TC--) {
        getline(cin, line);

        V = LoadNumbers(line);
        maxGCD = FindMaxGCD(V);

        cout << maxGCD << "\n";
    }

    return 0;
}

vector<LL> LoadNumbers(const string& line) {
    vector<LL> V;
    istringstream iss(line);
    string word;

    while (iss >> word) {
        V.push_back(stol(word));
    }

    return V;
};

LL FindMaxGCD(const vector<LL>& V) {
    LL gcd, maxGCD = GCD(V[0], V[1]);
    int N = V.size();

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            gcd = GCD(V[i], V[j]);
            maxGCD = max(gcd, maxGCD);
        }
    }

    return maxGCD;
};

LL GCD(const LL a, const LL b) {
    return ((b == 0) ? a : GCD(b, a % b));
};