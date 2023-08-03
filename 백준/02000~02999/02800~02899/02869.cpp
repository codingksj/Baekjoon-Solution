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
	int A, B, V;
	int day;
	cin >> A >> B >> V;
	day = ceil(double(V - B) / (A - B));
	cout << day << "\n";
	return 0;
}