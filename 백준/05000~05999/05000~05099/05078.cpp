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

bool Compare(const string& e1, const string& e2);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    Words shirts;
    string shirt;
    int W, H;

    while (true) {
        cin >> W;

        if (W == 0) {
            break;
        }

        while (W--) {
            cin >> shirt;
            shirts.push_back(shirt);
        }

        cin >> H;

        while (H--) {
            cin >> shirt;
            shirts.push_back(shirt);
        }

        sort(shirts.begin(), shirts.end(), Compare);

        for (string& shirt : shirts) {
            cout << shirt << " ";
        }

        cout << "\n";

        shirts.clear();
    }

    return 0;
}

bool Compare(const string& e1, const string& e2) {
    char size1 = e1[0], size2 = e2[0];
    char color1 = e1[1], color2 = e2[1];
    bool isSmall;

    if (size1 != size2) {
        isSmall = (size1 == 'S' && (size2 == 'M' || size2 == 'L')) ||
            (size1 == 'M' && size2 == 'L');

        return isSmall;
    }

    return color1 < color2;
};