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

    int A, a, B, b, P;
    bool canMakeRing;
   
    cin >> A >> a >> B >> b >> P;

    canMakeRing = (A + B <= P || (a >= B && P >= A || A <= b && P >= B));

    cout << (canMakeRing ? "Yes" : "No") << "\n";

    return 0;
}

