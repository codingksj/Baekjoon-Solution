#include<iostream>
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
typedef pair<int, int> Pii;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string text;
	map<string, string> translate = {
        {"CU", "see you"},
        {":-)", "I’m happy"},
        {":-(", "I’m unhappy"},
        {";-)", "wink"},
        {":-P", "stick out my tongue"},
        {"(~.~)", "sleepy"},
        {"TA", "totally awesome"},
        {"CCC", "Canadian Computing Competition"},
        {"CUZ", "because"},
        {"TY", "thank-you"},
        {"YW", "you’re welcome"},
        {"TTYL", "talk to you later"}
    };

    while (true) {
        getline(cin, text);
        if (translate[text] == "") {
            cout << text << "\n";
            continue;
        }
        cout << translate[text] << "\n";
        if (text == "TTYL") {
            break;
        }
    }
	return 0;
}