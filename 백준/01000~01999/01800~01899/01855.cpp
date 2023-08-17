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
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, string> UMapSS;
typedef vector<string> Words;

string DecodeCipher(string& cipher, int K);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string cipher, plaintext;
    int K;
    
    cin >> K;
    cin >> cipher;

    plaintext = DecodeCipher(cipher, K);

    cout << plaintext;

    return 0;
}

string DecodeCipher(string& cipher, int K) {
    Words subciphers;
    string plaintext = "", subcipher;
    int maxL = cipher.length();
    int maxSize;

    for (int i = 0; i < maxL; i+=K) {
        subcipher = cipher.substr(i, K);
        subciphers.push_back(subcipher);
    }

    maxSize = subciphers.size();

    for (int length = 0; length < K; length++) {
        for (int i = 0; i < maxSize; i++) {
            plaintext += (i & 1) ?
                subciphers[i][K - 1 - length] : subciphers[i][length];
        }
    }

    return plaintext;
};