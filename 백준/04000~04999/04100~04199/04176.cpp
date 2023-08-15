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

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<string> X;
    string input;

    while (true) {
        X.clear();

        cin >> input;

        if (input == "END") {
            break;
        }
        X.push_back(input);
        for (int i = 1; i < 25; i++) {
            X.push_back(to_string(X[i - 1].length()));
        }
        for (int i = 1; i < 25; i++) {
            if (X[i] == X[i - 1]) {
                cout << i << "\n";
                break;
            }
        }
    }

    return 0;
}

