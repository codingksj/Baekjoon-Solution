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

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string respond;
    vector<int> high, low;
    int N;
    bool isHonest;

    while (cin >> N) {
        if (N == 0) {
            break;
        }

        isHonest = true;

        cin.ignore();

        getline(cin, respond);

        if (respond == "too high") {
            high.push_back(N);
            continue;
        }
        if (respond == "too low") {
            low.push_back(N);
            continue;
        }

        for (int& e : high) {
            if (e <= N) {
                isHonest = false;
                break;
            }
        }

        for (int& e : low) {
            if (e >= N) {
                isHonest = false;
                break;
            }
        }

        cout << "Stan " << (isHonest ? "may be honest" : "is dishonest") << "\n";

        high.clear();
        low.clear();
    }

    return 0;
}