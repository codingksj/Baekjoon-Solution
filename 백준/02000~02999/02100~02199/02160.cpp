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

int ComparePictures(char picture1[5][7], char picture2[5][7]);
pair<int, int> FindMostSimilarPicture(char pictures[][5][7], int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    pair<int, int> result;
    char pictures[51][5][7];
    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 7; c++) {
                cin >> pictures[i][r][c];
            }
        }
    }
   
    result = FindMostSimilarPicture(pictures, N);

    cout << result.first << " " << result.second;

    return 0;
}

int ComparePictures(char picture1[5][7], char picture2[5][7]) {
    int difference = 0;

    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 7; c++) {
            if (picture1[r][c] != picture2[r][c]) {
                difference++;
            }
        }
    }

    return difference;
}

pair<int, int> FindMostSimilarPicture(char pictures[][5][7], int N) {
    pair<int, int> result;
    int minDifference = 36; 

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int difference = ComparePictures(pictures[i], pictures[j]);

            if (difference < minDifference) {
                minDifference = difference;
                result = { i + 1, j + 1 };
            }
        }
    }
    return result;
}

