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

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
    int p[4];
    int x, y, r;
    int target = 0;

    for (int i = 0; i < 4; i++) { 
        cin >> p[i]; 
    }

    cin >> x >> y >> r;

    for (int i = 0; i < 4; i++) {
        if (p[i] == x) {
            target = i + 1;
        }
    }

    cout << target;
	return 0;
}