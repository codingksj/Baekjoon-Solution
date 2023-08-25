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

Words GetBuildings(int N);
Words FindInitial(Words& buildings, string& initial);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words buildings, answer;
    string initial;
    int TC, N;

    cin >> TC;

    for (int i = 1; i <= TC; i++) {
        cin >> N;
        cin.ignore();

        buildings = GetBuildings(N);

        cin >> initial;

        answer = FindInitial(buildings, initial);

        cout << "Data Set " << i << ":\n";
        if (!answer.empty()) {
            for (string& e : answer) {
                cout << e << "\n";
            }
        }
    }

    return 0;
}

Words GetBuildings(int N) {
    Words buildings(N);

    for (string& building : buildings) {
        getline(cin, building);
    }

    return buildings;
};

Words FindInitial(Words& buildings, string& initial) {
    Words answer;
    string upperedInitial = initial;
    string upperedBuilding;
    int count;
    int maxL = initial.length();

    transform(initial.begin(), initial.end(), upperedInitial.begin(), ::toupper);

    for (string& building : buildings) {
        upperedBuilding = building;
        transform(building.begin(), building.end(), upperedBuilding.begin(), ::toupper);

        count = 0;

        for (char c : upperedBuilding) {
            if (count == maxL) {
                break;
            }
            if (c == upperedInitial[count]) {
                count++;
            }
        }

        if (count == maxL) {
            answer.push_back(building);
        }
    }

    return answer;
};