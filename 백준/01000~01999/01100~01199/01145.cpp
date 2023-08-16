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
typedef map<string, LL> WordMap;
typedef unordered_map<string, LL> WordHash;

LL FindMinCommonMultiple(vector<LL>& numbers);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<LL> numbers;
    LL number, answer;

    for (int i = 0; i < 5; i++) {
        cin >> number;
        numbers.push_back(number);
    }
    answer = FindMinCommonMultiple(numbers);

    cout << answer;

    return 0;
}

LL FindMinCommonMultiple(vector<LL>& numbers) {
    int count = 0;
    LL max = *max_element(numbers.begin(), numbers.end());
    LL multiple = max;
    LL i = 1;

    while (true) {
        count = 0;
        for (LL& number : numbers) {
            if (i % number) {
                continue;
            }
            count++;
        }
        if (count >= 3) {
            multiple = i;
            break;
        }
        i++;
    }
    return multiple;
};