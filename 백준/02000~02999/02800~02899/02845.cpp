#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<string>
#include<numeric>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iomanip>

using namespace std;

typedef long long LL;
typedef pair<int, int> Pii;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<int> news;
	int L, P, participant;
	int input;
	cin >> L >> P;
	participant = L * P;
	for (int i = 0; i < 5; i++) {
		cin >> input;
		news.push_back(input);
	}
	for (auto it : news) {
		it -= participant;
		cout << it << " ";
	}
	return 0;
}