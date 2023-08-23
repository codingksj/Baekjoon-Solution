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

typedef struct Item {
    double length;
    double height;
    double thickness;
}Item;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Item item;
    string result;
    bool minLetter, maxLetter, maxPacket, maxParcel;
    double t[3];

    while (cin >> t[0] >> t[1] >> t[2]) {
        if (t[0] == 0 && t[1] == 0 && t[2] == 0) {
            break;
        }

        sort(t, t + 3);

        item.thickness = t[0];
        item.height = t[1];
        item.length = t[2];

        minLetter = 
            (item.length >= 125) &&
            (item.height >= 90) && 
            (item.thickness >= 0.25);

        maxLetter =
            (item.length <= 290) && 
            (item.height <= 155) && 
            (item.thickness <= 7);

        maxPacket = 
            (item.length <= 380) &&
            (item.height <= 300) &&
            (item.thickness <= 50);

        maxParcel =
            item.length + (item.height + item.thickness) * 2 <= 2100;

        result = "not mailable";

        if (minLetter) {
            if (maxLetter) {
                result = "letter";
            }
            else if (maxPacket) {
                result = "packet";
            }
            else if (maxParcel) {
                result = "parcel";
            }
        }
        cout << result << "\n";
    }

    return 0;
}
