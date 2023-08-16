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
typedef map<string, LL> WordsMap;
typedef unordered_map<string, LL> WordsHash;

int FindTempLeader(int studentInfo[1001][5], int studentNum);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int studentInfo[1001][5] = { 0, };
    int studentNum;
    int tempLeader;

    cin >> studentNum;

    for (int i = 0; i < studentNum; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> studentInfo[i][j];
        }
    }

    tempLeader = FindTempLeader(studentInfo, studentNum);

    cout << tempLeader;

    return 0;
}

int FindTempLeader(int studentInfo[1001][5], int studentNum) {
    int maxSameClass[1001] = { 0, };
    int maxFriend;
    int tempLeader;
    

    for (int iM = 0; iM < studentNum; iM++) {
        for (int iY = iM + 1; iY < studentNum; iY++) {
            for (int grade = 0; grade < 5; grade++) {
                if (studentInfo[iM][grade] == studentInfo[iY][grade]) {
                    maxSameClass[iM]++;
                    maxSameClass[iY]++;
                    break;
                }
            }
        }
    }

    maxFriend = *max_element(begin(maxSameClass), end(maxSameClass));

    for (int iM = 0; iM < studentNum; iM++) {
        if (maxSameClass[iM] == maxFriend) {
            tempLeader = iM + 1;
            break;
        }
    }

    return tempLeader;
};