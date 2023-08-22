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
typedef vector<vector<int>> Matrix2Di;

typedef struct Rfp {
    string company; 
    int met; 
    double price;

    bool operator< (const Rfp& other) const {
        if (met == other.met) {
            return price > other.price;
        } 
        return met < other.met;
    }
}Rfp;


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Rfp> rfps;
    Rfp rfp, ans;
    string req, company;
    double price;
    int r;
    int TC = 1;
    int N, P;

    while (true) {
        cin >> N >> P;

        if (N == 0 && P == 0) {
            break;
        }

        if (TC != 1) {
            cout << "\n";
        }

        for (int i = 0; i < N; i++) {
            cin.ignore();
            getline(cin, req);
        }

        for (int i = 0; i < P; i++) {
            getline(cin, company);
            cin >> price >> r;
            cin.ignore();

            for (int j = 0; j < r; j++) {
                getline(cin, req);
            }

            rfp = { company, r, price };
            rfps.push_back(rfp);
        }

        ans = *max_element(rfps.begin(), rfps.end());

        cout << "RFP #" << TC++ << "\n"
            << ans.company << "\n";

        rfps.clear();

    }
    return 0;
}