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

	int Ca, Ba, Pa;
	int Cr, Br, Pr;
	int lack = 0;

	cin >> Ca >> Ba >> Pa;
	cin >> Cr >> Br >> Pr;

	lack += (Ca - Cr < 0) ? (Cr - Ca) : 0;
	lack += (Ba - Br < 0) ? (Br - Ba) : 0;
	lack += (Pa - Pr < 0) ? (Pr - Pa) : 0;

	cout << lack;

	return 0;
}