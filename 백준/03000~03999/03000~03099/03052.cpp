#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	set<int> R;
	int num;
	for (int i = 0; i < 10; i++) {
		cin >> num;
		R.insert(num % 42);
	}
	cout << R.size();
	return 0;
}