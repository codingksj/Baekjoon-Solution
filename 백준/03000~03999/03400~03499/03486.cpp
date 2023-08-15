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

int GetReversedSum(string& n1, string& n2);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string n1, n2;
    int TC;
    
    cin >> TC;
    
    while (TC--) {
        cin >> n1 >> n2;
        cout << GetReversedSum(n1, n2) << "\n";
    }
}

int GetReversedSum(string& n1, string& n2) {
    string reverseSum;
    int sum;
    int Rn1, Rn2;

    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());

    Rn1 = stoi(n1);
    Rn2 = stoi(n2);
    sum = Rn1 + Rn2;
    
    reverseSum = to_string(sum);

    reverse(reverseSum.begin(), reverseSum.end());

    sum = stoi(reverseSum);

    return sum;
};