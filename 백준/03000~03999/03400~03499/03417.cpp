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

string VigenereEncrypt(string P, string K);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string P, K;

    while (true) {
        cin >> K;
        if (K == "0") {
            break;
        }
        cin >> P;
        cout << VigenereEncrypt(P, K) << "\n";
    }
    return 0;
}

string VigenereEncrypt(string P, string K) {
    string encryptionedP = "";
    int pLength = P.length();
    int kLength = K.length();

    char newP;
    char cP, cK;

    for (int i = 0; i < pLength; i++) {
        newP = 'A' + ((P[i] - 'A') + (K[i % kLength] - 'A') + 1) % 26;
        encryptionedP += newP;
    }

    return encryptionedP;
};