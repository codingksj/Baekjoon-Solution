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
typedef pair<int, int> Pii;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<string, LL> WordsMap;
typedef unordered_map<string, LL> WordsHash;
typedef vector<string> Words;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<LL> warriorsS, warriorsB;
    LL warrior;
    LL N, M;
    int TC;
    int iS, iB;

    cin >> TC;

    while (TC--) {
        iS = iB = 0;
        warriorsS.clear();
        warriorsB.clear();
        cin >> N >> M;
        for (int i = 0; i < N;i++) {
            cin >> warrior;
            warriorsS.push_back(warrior);
        }
        for (int i = 0; i < M; i++) {
            cin >> warrior;
            warriorsB.push_back(warrior);
        }
        sort(warriorsS.begin(), warriorsS.end());
        sort(warriorsB.begin(), warriorsB.end());
        while (iS < N && iB < M) {
            (warriorsS[iS] < warriorsB[iB]) ? iS++ : iB++;
        }
        cout << (iB == M ? 'S' : 'B') << "\n";
    }


    return 0;
}
