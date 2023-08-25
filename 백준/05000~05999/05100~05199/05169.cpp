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

vector<int> MakeFinancialTransactions(int s, int t);
string FindSuspect(vector<int>& people, int s);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
   
    vector<int> people;
    string answer;
    int TC;
    int s, t;

    cin >> TC;

    for (int i = 1; i <= TC; i++) {
        cin >> s >> t;

        people = MakeFinancialTransactions(s, t);
        answer = FindSuspect(people, s);

        cout << "Data Set " << i << ":\n"
            << answer << "\n\n";
    }

    return 0;
}

vector<int> MakeFinancialTransactions(int s, int t) {
    vector<int> people(s + 1, 0);
    int n, money;

    for (int i = 0; i < t; i++) {
        cin >> n >> money;
        people[n] += money;
    }

    return people;
};

string FindSuspect(vector<int>& people, int s) {
    string answer = "";
    bool isTwice;
    int person;

    for (int i = 1; i <= s; i++) {
        person = people[i];
        isTwice = true; 
        for (int j = 1; j <= s; j++) {
            if (i == j || person > 2 * people[j]) {
                continue;
            }
            isTwice = false;
            break;
        }
        if (isTwice) {
            answer += to_string(i) + ' ';
        }
    }
    if (answer.empty()) {
        answer = "No suspect.";
    }

    return answer;
}
