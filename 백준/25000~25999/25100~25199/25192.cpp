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

    set<string> gomgom;
    string command;
    int TC;
    int count = 0;

    cin >> TC;

    while (TC--) {
        cin >> command;
        if (command == "ENTER") {
            count += gomgom.size();
            gomgom.clear();
            continue;
        }
        gomgom.insert(command);
    }
    count += gomgom.size();
    gomgom.clear();

    cout << count;

    return 0;
}

