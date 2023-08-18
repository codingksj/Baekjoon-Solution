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


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<double> studentsC, studentsE;
    double stC, stE;
    double sumC, sumE;
    double avgC, avgE;
    int TC, N, M;
    int count;

    cin >> TC;

    while (TC--) {
        studentsC.clear();
        studentsE.clear();
        sumC = sumE = count = 0;

        cin >> N >> M;

        for (int i = 0; i < N; i++) {
            cin >> stC;
            sumC += stC;
            studentsC.push_back(stC);
        }
        for (int i = 0; i < M; i++) {
            cin >> stE;
            sumE += stE;
            studentsE.push_back(stE);
        }
        sort(studentsC.begin(), studentsC.end());
        sort(studentsE.begin(), studentsE.end());

        avgC = sumC / N;
        avgE = sumE / M;

        for (int i = 0; i < N; i++) {
            if (studentsC[i] >= avgC) {
                break;
            }
            if (studentsC[i] > avgE) {
                count++;
            }
        }
        cout << count << "\n";

    }

    return 0;
}
