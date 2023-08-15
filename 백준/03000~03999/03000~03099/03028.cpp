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

void Swap(int* a, int* b);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string commands;
    int balls[4] = { 0,1,0,0 };

    cin >> commands;
    for (char command : commands) {
        if (command == 'A') {
            Swap(&balls[1], &balls[2]);
        }
        else if (command == 'B') {
            Swap(&balls[2], &balls[3]);
        }
        else {
            Swap(&balls[3], &balls[1]);
        }
    }
    for (int i = 1; i <= 3; i++) {
        if (balls[i]) {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}

void Swap(int* a, int* b) {
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
};