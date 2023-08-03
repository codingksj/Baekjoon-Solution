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
	string name, grade;
	int age, weight;
	while (true) {
		cin >> name >> age >> weight;
		if (name == "#") {
			break;
		}
		if (age > 17 || weight >= 80) {
			grade = "Senior";
		}
		else {
			grade = "Junior";
		}
		cout << name << " " << grade << "\n";
	}
	return 0;
}