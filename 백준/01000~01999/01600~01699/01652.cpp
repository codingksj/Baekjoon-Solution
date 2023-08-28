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
#include<tuple>
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
typedef pair<int, string> PiS;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> PSi;
typedef pair<string, LL> PSL;

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

Words GetRoom(int N);
Pii FindPlace(Words& room, int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words room;
    Pii ans;
    int N;

    cin >> N;

    room = GetRoom(N);
    ans = FindPlace(room, N);

    cout << ans.first << ' ' << ans.second << "\n";

    return 0;
};

Words GetRoom(int N) {
    Words room(N);
    
    for (string& line : room) {
        cin >> line;
    }

    return room;
};

Pii FindPlace(Words& room, int N) {
    Pii ans;
    int lengthR = 0;
    int lengthC = 0;
    int cntR = 0, cntC = 0;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (room[r][c] == '.') {
                lengthR++;
            }
            else {
                (lengthR > 1) && (cntR++);
                lengthR = 0;
            }
            if (room[c][r] == '.') {
                lengthC++;
            }
            else {
                (lengthC > 1) && (cntC++);
                lengthC = 0;
            }
        }
        (lengthR > 1) && (cntR++);
        (lengthC > 1) && (cntC++);
        lengthR = lengthC = 0;
    }

    ans = { cntR, cntC };

    return ans;
};