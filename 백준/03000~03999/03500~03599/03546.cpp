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
typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, string> Pis;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
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

#define PI 3.141592653589793

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string bullets, answer;
    int maxL;
    int origin;
    int k, l;

    origin = k = l = 0;

    cin >> bullets;

    for (char bullet : bullets) {
        (bullet == '1') && (++origin);
    }

    maxL = bullets.length();

    bullets += bullets[0];

    for (int i = 0; i < maxL; i++) {
        (bullets[i] == '0') && (++k) && (bullets[i + 1] == '1') && (++l);
    }

    if (origin * k > l * maxL) {
        answer = "SHOOT";
    }
    else if (origin * k < l * maxL) {
        answer = "ROTATE";
    }
    else {
        answer = "EQUAL";
    }

    cout << answer;

    return 0;
}
