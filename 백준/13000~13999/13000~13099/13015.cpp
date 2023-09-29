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

Words MakeStars(const int size);
Words RemoveSpace(const Words& stars);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words stars;
    int size;

    cin >> size;

    stars = MakeStars(size);

    for (const string& line : stars) {
        cout << line << "\n";
    }

    return 0;
}

Words MakeStars(const int size) {
    Words stars, cleanedStars;
    int width = 4 * size - 3;
    int height = 2 * size - 1;
    bool isEdge;

    stars.resize(height, string(width, ' '));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 2 * size - 1; j++) {
            isEdge = (j == i || j == i + size - 1) || (i == 0 && j < size);
            if (isEdge) {
                stars[i][j] =
                    stars[i][width - 1 - j] =
                    stars[height - 1 - i][j] =
                    stars[height - 1 - i][width - 1 - j] = '*';
            }
        }
    }
    
    cleanedStars = RemoveSpace(stars);

    return cleanedStars;
};

Words RemoveSpace(const Words& stars) {
    Words cleanedStars = stars;
    int length;

    for (string& line : cleanedStars) {
        for (length = line.length() - 1; length >= 0 && line[length] == ' '; length--);
        if (length > 0 && length != line.length() - 1) {
            line = line.substr(0, length + 1);
        }
    }

    return cleanedStars;
};