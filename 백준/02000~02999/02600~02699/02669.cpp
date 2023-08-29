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

typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, string> PiS;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> PSi;
typedef pair<string, LL> PSL;

typedef map<int, string> MapiS;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;

typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;

typedef struct Coord {
    int x;
    int y;
}Coord;

typedef struct Rectangle {
    Coord start;
    Coord end;
}Rectangle;

vector<Rectangle> GetRectangles();
int CalcArea(vector<Rectangle>& rectangles);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Rectangle> rectangles = GetRectangles();
    int area = CalcArea(rectangles);

    cout << area;

    return 0;
}

vector<Rectangle> GetRectangles() {
    vector<Rectangle> rectangles(4);

    for (Rectangle& rect : rectangles) {
        cin >> rect.start.x
            >> rect.start.y
            >> rect.end.x
            >> rect.end.y;
    }

    return rectangles;
};

int CalcArea(vector<Rectangle>& rectangles) {
    Matrix2D_i space(101, vector<int>(101, 0));
    int area = 0;
    int sx, ex;
    int sy, ey;

    for (Rectangle& rect : rectangles) {
        sx = rect.start.x, ex = rect.end.x;
        sy = rect.start.y, ey = rect.end.y;

        for (int x = sx; x < ex; x++) {
            for (int y = sy; y < ey; y++) {
                space[x][y] = 1;
            }
        }
    }

    for (vector<int>& row : space) {
        area += accumulate(row.begin(), row.end(), 0);
    }

    return area;
};