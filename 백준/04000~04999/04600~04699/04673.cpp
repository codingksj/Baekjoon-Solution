#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int DigitSum(int n) {
	int sum = 0;
	while (n != 0) {
		sum += (n % 10);
		n /= 10;
	}
	return sum;
}

void FindSelfNumber(int n, set<int>* self) {
	int generator;
	for (int i = 1; i <= n; i++) {
		generator = DigitSum(i) + i;
		self->erase(generator);
	}
}

void FillSet(int n, set<int>* self) {
	for (int i = 1; i <= n; i++) {
		self->insert(i);
	}
}

void PrintSelfNumber(set<int>* self) {
	for (auto it : *self) {
		cout << it << "\n";
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	set<int> self_number;
	int range = 10000;
	FillSet(range, &self_number);
	FindSelfNumber(range, &self_number);
	PrintSelfNumber(&self_number);
	return 0;
}