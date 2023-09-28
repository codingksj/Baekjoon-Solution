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

typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

bool CheckDividedBy3(const string& number);
bool CheckDividedBy10(const string& number);
string MakeMaximumNumber(const string& number);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string number;
    bool isMultipleOf30;

    cin >> number;

    isMultipleOf30 = CheckDividedBy3(number) && CheckDividedBy10(number);

    cout << (isMultipleOf30 ? MakeMaximumNumber(number) : "-1") << "\n";

    return 0;
}

bool CheckDividedBy3(const string& number) {
    bool isMultipleOf3;
    int sum = 0;

    for (const char& digit : number) {
        sum += digit - '0';
    }

    isMultipleOf3 = sum % 3 == 0;

    return isMultipleOf3;
};

bool CheckDividedBy10(const string& number) {
    bool isMultipleOf10 = false;

    for (const char& digit : number) {
        if (digit == '0') {
            isMultipleOf10 = true;
            break;
        }
    }

    return isMultipleOf10;
};

string MakeMaximumNumber(const string& number) {
    string sortedNumber = number;

    sort(sortedNumber.begin(), sortedNumber.end(), greater<char>());

    return sortedNumber;
};