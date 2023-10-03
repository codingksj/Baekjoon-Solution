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
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

MapSL MakePublicKeys(const int N);
MapLL MakeOrders(MapSL& pk1, const int N);
Words LoadCiphers(const int N);
Words EncryptCiphers(MapLL& pk2, const Words& ciphers, const int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    MapSL pk1;
    MapLL pk2;
    Words ciphers, plainTexts;
    int TC, N;

    cin >> TC;

    while (TC--) {
        cin >> N;

        pk1 = MakePublicKeys(N);
        pk2 = MakeOrders(pk1, N);
        ciphers = LoadCiphers(N);
        plainTexts = EncryptCiphers(pk2, ciphers, N);

        for (const string& pT : plainTexts) {
            cout << pT << " ";
        }
        cout << "\n";
    }

    return 0;
}

MapSL MakePublicKeys(const int N) {
    MapSL pk1;
    string key;

    for (int i = 0; i < N; i++) {
        cin >> key;
        pk1[key] = i;
    }

    return pk1;
};

MapLL MakeOrders(MapSL& pk1, const int N) {
    MapLL pk2;
    string key;

    for (int i = 0; i < N; i++) {
        cin >> key;
        pk2[pk1[key]] = i;
    }

    return pk2;
};

Words LoadCiphers(const int N) {
    Words ciphers(N);

    for (string& cipher : ciphers) {
        cin >> cipher;
    }

    return ciphers;
};

Words EncryptCiphers(MapLL& pk2, const Words& ciphers, const int N) {
    Words plainTexts(N);

    for (int i = 0; i < N; i++) {
        plainTexts[i] = ciphers[pk2[i]];
    }

    return plainTexts;
};