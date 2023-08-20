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
typedef pair<int, string> Pis;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;

typedef struct _dart {
    int x;
    int y;
}Dart;

double CalcDistance(Dart& D);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Dart dart;
    double distance;
    int TC, game;
    int score;

    cin >> TC;

    while (TC--) {
        cin >> game;
        score = 0;

        while (game--) {
            cin >> dart.x >> dart.y;
            distance = CalcDistance(dart);
            if (distance > 200) {
                continue;
            }
            if (distance == 0) {
                score += 10;
                continue;
            }
            score += floor((220 - distance) / 20);
        }
        cout << score << "\n";
    }

    return 0;
}

double CalcDistance(Dart& D) {
    double distance;
    
    distance = sqrt(pow(D.x, 2) + pow(D.y, 2));

    return distance;
};