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
typedef pair<int, string> Pis;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<string, char> MapSc;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;

bool DetermineSorted(vector<int>& V);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> V(5,0), swappedV;
    bool areEqual;

    for (int i = 0; i < 5; i++) {
        cin >> V[i];
    }

    while (true) {
        for (int i = 0; i < 4; i++) {
            swappedV = V;
            if (swappedV[i] > swappedV[i + 1]) {
                swap(swappedV[i], swappedV[i + 1]);
            }
            areEqual = equal(V.begin(), V.end(),
                swappedV.begin(), swappedV.end());

            if (!areEqual) {
                V = swappedV;
                for (int e : V) {
                    cout << e << " ";
                }
                cout << "\n";
            }
        }
        if (DetermineSorted(V)) {
            break;
        }
    }

    return 0;
}

bool DetermineSorted(vector<int>& V) {
    int maxSize = V.size();

    for (int i = 0; i < maxSize; i++) {
        if (V[i] != i + 1) {
            return false;
        }
    }
    return true;
};