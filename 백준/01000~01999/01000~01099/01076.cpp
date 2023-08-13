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
typedef unsigned long long ULL;
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

    map<string, LL> color = {
        {"black", 0},
        {"brown", 1},
        {"red", 2},
        {"orange", 3},
        {"yellow", 4},
        {"green", 5},
        {"blue", 6},
        {"violet", 7},
        {"grey", 8},
        {"white", 9}
    };

    map<string, LL> weight = {
        {"black", 1E+0},
        {"brown", 1E+1},
        {"red", 1E+2},
        {"orange", 1E+3},
        {"yellow", 1E+4},
        {"green", 1E+5},
        {"blue", 1E+6},
        {"violet", 1E+7},
        {"grey", 1E+8},
        {"white", 1E+9}
    };


	string R1, R2, R3;
    LL ohm;

	cin >> R1;
	cin >> R2;
	cin >> R3;

    ohm = (color[R1] * 10LL + color[R2]) * weight[R3];

    cout << ohm;

	return 0;
}
