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

typedef struct Donor {
    unordered_map<int, int> candidates;
    int total;
    bool isViolate;
}Donor;

#define PI 3.141592653589793

vector<Donor> GetDonors(int c, int d, int t);
vector<int> FindViolators(vector<Donor>& donors, int d);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Donor> donors;
    vector<int> violators;
    string answer;
    int TC;
    int c, d, t;

    cin >> TC;

    for (int i = 1; i <= TC; i++) {
        cin >> c >> d >> t;

        donors = GetDonors(c, d, t);
        violators = FindViolators(donors, d);

        cout << "Data Set " << i << ":\n";

        if (violators.size()) {
            cout << "Violators" << ":\n";
            for (int donor : violators) {
                cout << donor << "\n";
            }
        }
        else {
            cout << "No violations" << "\n";
        }
    }

    return 0;
}

vector<Donor> GetDonors(int c, int d, int t) {
    vector<Donor> donors;
    Donor basic = { {},0,false };
    int di, ci, mi;

    donors.resize(d + 1, basic);

    for (int i = 0; i < t; i++) {
        cin >> di >> ci >> mi;

        donors[di].candidates[ci] += mi;
        donors[di].total += mi;
    }

    return donors;
};

vector<int> FindViolators(vector<Donor>& donors, int d) {
    Donor& donor = donors[0];
    vector<int> violators;
    const int PERSONAL = 2100;
    const int TOTAL = 40000;

    for (int i = 1; i <= d; i++) {
        donor = donors[i];
        (donor.total > TOTAL) && (donor.isViolate = true);

        for (pair<const int, int>& p : donor.candidates) {
            if (p.second > PERSONAL || donor.isViolate) {
                donor.isViolate = true;
                break;
            }
        }

        if (donor.isViolate) {
            violators.push_back(i);
        }
    }

    return violators;
};