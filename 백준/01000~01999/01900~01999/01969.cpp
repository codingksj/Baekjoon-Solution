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

Words LoadDNA(const int N);
PSi FindLeastHammingDistanceDNA(Words& DNA, const int count, const int length);
Pci CalcHammingDistance(const Words& DNA, const int col, const int count);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words DNA;
    PSi ans;
    int N, M;

    cin >> N >> M;

    DNA = LoadDNA(N);
    ans = FindLeastHammingDistanceDNA(DNA, N, M);

    cout << ans.first << "\n"
        << ans.second << "\n";

    return 0;
}

Words LoadDNA(const int N) {
    Words DNA(N);

    for (string& dna : DNA) {
        cin >> dna;
    }

    return DNA;
};

PSi FindLeastHammingDistanceDNA(Words& DNA, const int count, const int length) {
    PSi ans = { "",0 };
    Pci info;
    int totalHammingDistance = 0;

    sort(DNA.begin(), DNA.end());

    for (int i = 0; i < length; i++) {
        info = CalcHammingDistance(DNA, i, count);
        ans.first += info.first;
        ans.second += info.second;
    }

    return ans;
};

Pci CalcHammingDistance(const Words& DNA, const int col, const int count) {
    map<char, int> alphaCount;
    Pci info;
    char rna;
    int maxCount = -1;

    for (const string& dna : DNA) {
        rna = dna[col];
        alphaCount[rna]++;
    }

    for (const Pci& p : alphaCount) {
        if (p.second > maxCount) {
            maxCount = p.second;
            info = { p.first, count - maxCount };
        }
    }

    return info;
};