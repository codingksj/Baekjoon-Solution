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
	double weight, height, BMI;
	cin >> weight >> height;
	BMI = weight / (height * height);
	if (BMI > 25) {
		cout << "Overweight" << "\n";
	}
	else if (BMI < 18.5) {
		cout << "Underweight" << "\n";
	}
	else {
		cout << "Normal weight" << "\n";
	}
	return 0;
}