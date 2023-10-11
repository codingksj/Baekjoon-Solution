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
typedef vector<vector<bool>> Matrix2D_b;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

int CalcOriginalDistance(const string& distance);
int Power(const int base, const int exp);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string distance;
    int originalDistance;

    cin >> distance;

    originalDistance = CalcOriginalDistance(distance);

    cout << originalDistance << "\n";

    return 0;
}

int CalcOriginalDistance(const string& distance) {
    int length = distance.length();
    int result = 0;
    int digit;

    for (int i = length - 1; i >= 0; i--) {
        digit = distance[i] - '0';
        (digit > 4) && (--digit);
        result += Power(9, length - i - 1) * digit;
    }

    return result;
};

int Power(const int base, const int exp) {
    int number = 1;

    for (int i = 0; i < exp; i++) {
        number *= base;
    }

    return number;
};