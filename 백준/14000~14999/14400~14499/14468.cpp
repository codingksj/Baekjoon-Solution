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

typedef map<int, int> Mapii;
typedef map<int, string> MapiS;
typedef map<LL, LL> MapLL;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;

typedef unordered_map<LL, LL> HashLL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

vector<Pii> MakePositions(const string& cows);
int FindMeetingCows(const vector<Pii>& positions);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Pii> positions;
    string cows;
    int N;

    cin >> cows;

    positions = MakePositions(cows);
    N = FindMeetingCows(positions);

    cout << N << "\n";

    return 0;
}

vector<Pii> MakePositions(const string& cows) {
    vector<Pii> positions(26, { -1,-1 });
    int index, i = 0;

    for (const char& cow : cows) {
        index = cow - 'A';
        (positions[index].first == -1) ?
            positions[index].first = i :
            positions[index].second = i;
        i++;
    }

    return positions;
};

int FindMeetingCows(const vector<Pii>& positions) {
    bool isBetween;
    int cnt = 0;

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            isBetween =
                positions[i].first < positions[j].first &&
                positions[j].first < positions[i].second &&
                positions[i].second < positions[j].second;

            (isBetween) && (cnt++);
        }
    }

    return cnt;
};