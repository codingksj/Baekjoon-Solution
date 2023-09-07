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

deque<int> FIllDeque(bool checks[], int N);
void PrintDeque(deque<int>& dq, int M);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    deque<int> dq;
    bool checks[100001] = { 0, };
    int N, M;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> checks[i];
    }
    
    dq = FIllDeque(checks, N);

    cin >> M;

    PrintDeque(dq, M);

    return 0;
}

deque<int> FIllDeque(bool checks[], int N) {
    deque<int> dq;
    int X;

    for (int i = 0; i < N; i++) {
        cin >> X;
        if (!checks[i]) {
            dq.push_back(X);
        }
    }

    return dq;
};

void PrintDeque(deque<int>& dq, int M) {
    int X;

    for (int i = 0; i < M; i++) {
        cin >> X;
        dq.push_front(X);
        cout << dq.back() << " ";
        dq.pop_back();
    }
};