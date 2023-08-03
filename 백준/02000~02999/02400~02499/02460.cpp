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

	vector<int> max_people;
	int out, in;
	int curPeople = 0;
	max_people.push_back(curPeople);
	for (int i = 0; i < 10; i++) {
		cin >> out >> in;
		curPeople = max_people[i] - out + in;
		max_people.push_back(curPeople);
	}
	cout << *max_element(max_people.begin(), max_people.end());
	return 0;
}