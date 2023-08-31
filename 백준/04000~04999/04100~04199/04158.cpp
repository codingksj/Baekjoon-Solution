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

vector<int> GetCDs(int N);
int FindCommonCDs(vector<int>& CDs1, vector<int>& CDs2);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> CDs1, CDs2;
    int N, M, ans;

    while (cin >> N >> M) {
        if (N == 0 && M == 0) {
            break;
        }
        CDs1 = GetCDs(N);
        CDs2 = GetCDs(M);

        ans = FindCommonCDs(CDs1, CDs2);

        cout << ans << "\n";
    }

    return 0;
}

vector<int> GetCDs(int N) {
    vector<int> CDs(N);

    for (int& cd : CDs) {
        cin >> cd;
    }

    return CDs;
};

int FindCommonCDs(vector<int>& CDs1, vector<int>& CDs2) {
    int N = CDs1.size();
    int M = CDs2.size();
    int ptr1 = 0, ptr2 = 0;
    int count = 0;

    while (ptr1 < N && ptr2 < M) {
        if (CDs1[ptr1] < CDs2[ptr2]) {
            ptr1++;
        }
        else if (CDs1[ptr1] > CDs2[ptr2]) {
            ptr2++;
        }
        else {
            count++;
            ptr1++;
            ptr2++;
        }
    }

    return count;
};