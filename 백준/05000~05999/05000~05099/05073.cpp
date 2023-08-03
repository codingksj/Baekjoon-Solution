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
	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) {
			break;
		}
		if (a > b) {
			swap(a, b);
		}
		if (b > c) {
			swap(b, c);
		}
		if (a + b <= c) {
			cout << "Invalid\n";
		}
		else {
			if (a == b && b == c) {
				cout << "Equilateral\n";
			}
			else if (a == b || b == c || c == a) {
				cout << "Isosceles\n";
			}
			else {
				cout << "Scalene\n";
			}
		}
	}
	return 0;
}