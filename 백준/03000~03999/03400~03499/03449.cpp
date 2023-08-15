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

int CountDifferentBits(bitset<101>& bits1, bitset<101>& bits2);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    bitset<101> bits1, bits2;
    int TC;
    
    cin >> TC;
    
    while (TC--) {
        cin >> bits1 >> bits2;
        cout << "Hamming distance is "
            << CountDifferentBits(bits1, bits2) << "." << "\n";
    }
}

int CountDifferentBits(bitset<101>& bits1, bitset<101>& bits2) {
    bitset<101> xorBits = bits1 ^ bits2;
    return xorBits.count();
};
