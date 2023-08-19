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

string FindButtonOrders(Words& channels);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words channels;
    string channel, buttonOrders;
    int TC;

    cin >> TC;

    while (TC--) {
        cin >> channel;
        channels.push_back(channel);
    }

    buttonOrders = FindButtonOrders(channels);
    
    cout << buttonOrders;

    return 0;
}

string FindButtonOrders(Words& channels) {
    string answer;
    size_t index1, index2;
    auto pos1 = find(channels.begin(), channels.end(), "KBS1");
    auto pos2 = find(channels.begin(), channels.end(), "KBS2");

    index1 = distance(channels.begin(), pos1);
    index2 = distance(channels.begin(), pos2);

    if (index2 < index1) {
        answer += string(index2, '1');
        answer += string(index2, '4');
        answer += string(index1, '1');
        answer += string(index1, '4');
    }
    else {
        answer += string(index1, '1');
        answer += string(index1, '4');
        answer += string(index2, '1');
        answer += string(index2 - 1, '4');
    }

    return answer;
};