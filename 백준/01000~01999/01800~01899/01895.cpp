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

Matrix2D_i FilteringImage(const Matrix2D_i& image, const int R, const int C);
int CalcPixel(const Matrix2D_i& filteredImage, const int T);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Matrix2D_i image, filteredImage;
    int R, C, T, count;

    cin >> R >> C;

    image.resize(R, vector<int>(C, 0));

    for (vector<int>& row : image) {
        for (int& col : row) {
            cin >> col;
        }
    }

    cin >> T;

    filteredImage = FilteringImage(image, R, C);
    count = CalcPixel(filteredImage, T);

    cout << count << "\n";

    return 0;
}


Matrix2D_i FilteringImage(const Matrix2D_i& image, const int R, const int C) {
    Matrix2D_i filteredImage(R - 2, vector<int>(C - 2, 0));
    vector<int> subImage;
    const int CENTER = 4;

    for (int r = 0; r < R - 2; r++) {
        for (int c = 0; c < C - 2; c++) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    subImage.push_back(image[r + i][c + j]);
                }
            }
            sort(subImage.begin(), subImage.end());
            filteredImage[r][c] = subImage[CENTER];
            subImage.clear();
        }
    }

    return filteredImage;
};

int CalcPixel(const Matrix2D_i& filteredImage, const int T) {
    int count = 0;

    for (const vector<int>& row : filteredImage) {
        for (const int& col : row) {
            (col >= T) && count++;
        }
    }

    return count;
};