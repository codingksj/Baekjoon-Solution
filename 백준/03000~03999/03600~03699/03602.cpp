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

string GetMaximumSize(int b, int w, int size);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int b, w;
    int size;

    cin >> b >> w;

    size = ceil(sqrt(b + w));

    cout << GetMaximumSize(b, w, size);

    return 0;
}

string GetMaximumSize(int b, int w, int size) {
    bool canMakeIChess;
    int countB, countW;
    int squareSize = size * size;

    countB = squareSize / 2;
    countW = squareSize - countB;

    canMakeIChess = ((b >= countB) && (w >= countW)) ||
        ((b >= countW) && (w >= countB));

    if (size < 1) {
        return "Impossible";
    }
    else if (canMakeIChess) {
        return to_string(size);
    }
    else {
        return GetMaximumSize(b, w, size - 1);
    }
};