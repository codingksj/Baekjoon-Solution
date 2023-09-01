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

typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, string> PiS;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> PSi;
typedef pair<string, LL> PSL;

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

vector<int> GetNumbers(int N);
bool CheckJollyJumper(vector<int>& seq, int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> seq;
    int N;
    bool isJolly;

    while (cin >> N) {
        seq = GetNumbers(N);
        isJolly = CheckJollyJumper(seq, N);

        cout << (isJolly ? "Jolly" : "Not jolly") << "\n";
    }

    return 0;
}

vector<int> GetNumbers(int N) {
    vector<int> seq(N);

    for (int& n : seq) {
        cin >> n;
    }

    return seq;
};

bool CheckJollyJumper(vector<int>& seq, int N) {
    bitset<3001> chk;
    int size = seq.size();
    int delta;
    bool isJolly;

    if (N == 1) {
        return true;
    }

    for (int i = 1; i < size; i++) {
        delta = abs(seq[i] - seq[i - 1]);

        if (delta < 1 || delta > N - 1) {
            isJolly = false;
            break;
        }

        if (chk[delta]) {
            isJolly = false;
            break;
        }

        chk[delta] = 1;
    }
    
    isJolly = chk.count() == N - 1;

    return isJolly;
};