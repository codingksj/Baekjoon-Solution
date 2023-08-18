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
typedef pair<int, int> Pii;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<string, char> MapSc;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, string> UMapSS;
typedef vector<string> Words;

string AddBinary(string& b1, string& b2);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string b1, b2;
    string ans;
    int TC;

    cin >> TC;

    while (TC--) {
        cin >> b1 >> b2;

        ans = AddBinary(b1, b2);

        cout << ans << "\n";
    }

    return 0;
}

string AddBinary(string& bin1, string& bin2) {
    bitset<81> num1(bin1);
    bitset<81> num2(bin2);
    bitset<81> sum;

    int carry = 0;

    for (int i = 0; i < 81; ++i) {
        sum[i] = num1[i] ^ num2[i] ^ carry;
        carry = (num1[i] & num2[i]) | (carry & (num1[i] ^ num2[i]));
    }

    string result = sum.to_string();
    size_t firstOnePos = result.find('1');

    if (firstOnePos != string::npos) {
        return result.substr(firstOnePos);
    }
    else {
        return "0"; 
    }
}