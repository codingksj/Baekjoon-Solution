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
#include<iomanip>

using namespace std;

typedef long long LL;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string fan = ":fan:";
	string hongjun;
	cin >> hongjun;
	hongjun = ":" + hongjun + ":";
	cout
		<< fan << fan << fan << "\n"
		<< fan << hongjun << fan << "\n"
		<< fan << fan << fan << "\n";
	return 0;
}