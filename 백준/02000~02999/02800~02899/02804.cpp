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
typedef pair<int, string> Pis;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<string, char> MapSc;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;

Words MakeCrosswordBoard(string& A, string& B);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words board;
    string A, B;
    
    cin >> A >> B;

    board = MakeCrosswordBoard(A, B);

    for (string& line : board) {
        cout << line << "\n";
    }

    return 0;
}

Words MakeCrosswordBoard(string& A, string& B) {
    Words board;
    int aLength = A.length();
    int bLength = B.length();
    int posA;
    int posB;

    board.resize(bLength);

    for (int length = 0; length < aLength; length++) {
        int index = B.find_first_of(A[length]);
        if (B.find_first_of(A[length]) != string::npos) {
            posA = index;
            posB = length;
            break;
        }
    }
    for (int i = 0; i < bLength; i++) {
        board[i] = (i != posA) ? string(aLength, '.') : A;
        board[i][posB] = B[i];
    }
    return board;
};