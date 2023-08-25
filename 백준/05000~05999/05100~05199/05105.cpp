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

bitset<21> CheckDelivery(string start);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    bitset<21> houses;
    string N;

    while (cin >> N) {
        if (N == "#") {
            break;
        }

        houses = CheckDelivery(N);

        if (houses.count() == 20) {
            cout << "none";
        }

        else if (houses != 0) {
            for (int i = 1; i <= 20; i++) {
                if (!houses[i]) {
                    cout << i << ' ';
                }
            }
        }
        else {
            cout << "illegal";
        }

        cout << "\n";
    }

    

    return 0;
}

bitset<21> CheckDelivery(string start) {
    Words movements;
    string line, movement;
    bitset<21> houses;
    bool canMove = true;
    int curPos = stoi(start);
    int dir, delta;

    houses[curPos] = 1;

    getline(cin, line);

    istringstream iss(line);

    while (iss >> movement) {
        movements.push_back(movement);
    }

    for (string movement : movements) {
        dir = (movement[0] == 'U') ? 1 : -1;
        delta = movement[1] - '0';

        curPos += (dir * delta);

        if (curPos < 1 || curPos > 20) {
            canMove = false;
            continue;
        }

        else if (houses[curPos]) {
            canMove = false;
            continue;
        }

        houses[curPos] = 1;
    }

    if (!canMove) {
        houses = 0;
    }

    return houses;
};