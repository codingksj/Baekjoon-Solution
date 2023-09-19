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

typedef pair<char, char> Pcc;
typedef pair<char, int> Pci;
typedef pair<char, string> PcS;
typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, string> PiS;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> PSi;
typedef pair<string, LL> PSL;
typedef pair<string, string> PSS;

typedef map<int, string> MapiS;
typedef map<LL, LL> MapLL;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;

typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;

bool CheckIsFriends(const string& X, const string& Y);
string FixNearNumbers(const string& target, const int index, const bool isMinus);
bool CheckIsAlmostFriends(const string& X, const string& Y);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string X, Y;
    string msg;

    for (int i = 0; i < 3; i++) {
        cin >> X >> Y;
        if (CheckIsFriends(X, Y)) {
            msg = "friends";
        }
        else if(CheckIsAlmostFriends(X,Y) || CheckIsAlmostFriends(Y,X)){
            msg = "almost friends";
        }
        else {
            msg = "nothing";
        }
        cout << msg << "\n";
    }

    return 0;
}

bool CheckIsFriends(const string& X, const string& Y) {
    bitset<10> checkX, checkY;
    bool isSame;

    for (const char& x : X) {
        checkX[x - '0'] = true;
    }
    for (const char& y : Y) {
        checkY[y - '0'] = true;
    }

    isSame = checkX == checkY;

    return isSame;
};

string FixNearNumbers(const string& target, const int index, const bool isMinus) {
    string fixedTarget = target;

    if (isMinus && target[index] > '0' && target[index + 1] < '9') {
        fixedTarget[index]--;
        fixedTarget[index + 1]++;
    }
    else if (!isMinus && target[index] < '9' && target[index + 1] > '0') {
        fixedTarget[index]++;
        fixedTarget[index + 1]--;
    }
    if (fixedTarget[0] == '0') {
        fixedTarget = target;
    }

    return fixedTarget;
};

bool CheckIsAlmostFriends(const string& X, const string& Y) {
    string fX1, fX2;
    int maxL = X.length();
    bool isFriends = false;

    for (int i = 0; i < maxL - 1; i++) {
        fX1 = FixNearNumbers(X, i, true);
        fX2 = FixNearNumbers(X, i, false);
        if (CheckIsFriends(fX1, Y) || CheckIsFriends(fX2, Y)) {
            isFriends = true;
            break;
        }
    }
    return isFriends;
};