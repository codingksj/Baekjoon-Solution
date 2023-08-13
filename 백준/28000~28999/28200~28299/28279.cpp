#include<iostream>
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
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;

enum Commands {
    PUSH_FRONT = 1,
    PUSH_BACK,
    POP_FRONT,
    POP_BACK,
    SIZE,
    EMPTY,
    FRONT,
    BACK
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

    deque<int> DQ;
    int TC, N, cmd;
    bool empty;

    cin >> TC;

    while (TC--) {
        cin >> cmd;
        empty = DQ.empty();
        if (cmd == PUSH_FRONT) {
            cin >> N;
            DQ.push_front(N);
        }
        else if (cmd == PUSH_BACK) {
            cin >> N;
            DQ.push_back(N);
        }
        else if (cmd == POP_FRONT) {
            if (empty) {
                cout << -1 << "\n";
            }
            else {
                cout << DQ.front() << "\n";
                DQ.pop_front();
            }
        }
        else if (cmd == POP_BACK) {
            if (empty) {
                cout << -1 << "\n";
            }
            else {
                cout << DQ.back() << "\n";
                DQ.pop_back();
            }
        }
        else if (cmd == SIZE) {
            cout << DQ.size() << "\n";
        }
        else if (cmd == EMPTY) {
            cout << empty << "\n";
        }
        else if (cmd == FRONT) {
            cout <<  (empty ? -1 : DQ.front()) << "\n";
        }
        else if (cmd == BACK) {
            cout <<  (empty ? -1 : DQ.back()) << "\n";
        }
    }

	return 0;
}
