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

void MergeSort(vector<int>& arr, int L, int R);
void Merge(vector<int>& arr, int L, int M, int R);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> students;
    int TC, N;
    int minScore, maxScore;
    int maxGap, gap;

    cin >> TC;

    for (int classNum = 1; classNum <= TC; classNum++) {
        cin >> N;

        students.resize(N);
        maxGap = 0;

        for (int& st : students) {
            cin >> st;
        }

        MergeSort(students, 0, N - 1);

        minScore = students[0];
        maxScore = students[N - 1];


        for (int i = 1; i < N; i++) {
            gap = students[i] - students[i - 1];
            maxGap = max(gap, maxGap);
        }

        cout << "Class " << classNum << "\n"
            << "Max " << maxScore
            << ", Min " << minScore
            << ", Largest gap " << maxGap << "\n";

        students.clear();
    }

    return 0;
}

void MergeSort(vector<int>& arr, int L, int R) {
    int M = (L + R) / 2;

    if (L < R) {
        MergeSort(arr, L, M);
        MergeSort(arr, M + 1, R);
        Merge(arr, L, M, R);
    }
};

void Merge(vector<int>& arr, int L, int M, int R) {
    int n1 = M - L + 1;
    int n2 = R - M;

    vector<int> arrL(arr.begin() + L, arr.begin() + L + n1);
    vector<int> arrR(arr.begin() + M + 1, arr.begin() + M + 1 + n2);

    int i = 0, j = 0, k = L;

    while (i < n1 && j < n2) {
        arr[k++] = (arrL[i] <= arrR[j]) ? arrL[i++] : arrR[j++];
    }

    while (i < n1) {
        arr[k++] = arrL[i++];
    }

    while (j < n2) {
        arr[k++] = arrR[j++];
    }
}