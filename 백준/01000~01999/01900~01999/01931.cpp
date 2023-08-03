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
#include<iomanip>

using namespace std;

typedef long long LL;
typedef pair<int, int> Pii;

bool Compare(Pii& a, Pii& b) {
	return a.second < b.second;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<Pii> meeting;
	Pii input;
	int TC, count = 1, time;
	cin >> TC;
	while (TC--) {
		cin >> input.first >> input.second;
		meeting.push_back(input);
	}
	sort(meeting.begin(), meeting.end());
	sort(meeting.begin(), meeting.end(), Compare);
	time = meeting[0].second;
	for (int i = 1; i < meeting.size(); i++) {
		if (time <= meeting[i].first) {
			count++;
			time = meeting[i].second;
		}
	}
	cout << count;
	return 0;
}