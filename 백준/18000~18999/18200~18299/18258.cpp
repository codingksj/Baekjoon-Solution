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

    queue<int> Q;
    string command;
    int TC;
    int N;

    cin >> TC;

    while (TC--) {
        cin >> command;

        if (command == "push") {
            cin >> N;
            Q.push(N);
        }
        else if (command == "pop") {
            if (Q.empty()) {
                cout << "-1\n";
            }
            else {
                cout << Q.front() << "\n";
                Q.pop();
            }
        }
        else if (command == "size") {
            cout << Q.size() << "\n";
        }
        else if (command == "empty") {
            cout << Q.empty() << "\n";
        }
        else if (command == "front") {
            cout << (Q.empty() ? -1 : Q.front()) << "\n";
        }
        else if (command == "back") {
            cout << (Q.empty() ? -1 : Q.back()) << "\n";
        }
    }

    return 0;
}
