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


vector<Pii> LoadSequence(int N);
vector<int> FindSequenceP(vector<Pii>& seq, int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Pii> seq;
    vector<int> ans;
    int N;
    
    cin >> N;

    seq = LoadSequence(N);
    ans = FindSequenceP(seq, N);

    for (const int& e : ans) {
        cout << e << " ";
    }

    return 0;
}

vector<Pii> LoadSequence(int N) {
    vector<Pii> seq(N);
    int value;

    for (int i = 0; i < N; i++) {
        cin >> value;
        seq[i] = { value,i };
    }

    return seq;
};

vector<int> FindSequenceP(vector<Pii>& seq, int N) {
    vector<int> P(N);

    sort(seq.begin(), seq.end());

    for (int i = 0; i < N; i++) {
        P[seq[i].second] = i;
    }

    return P;
};