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
	string music;
	getline(cin, music);
	if (music == "1 2 3 4 5 6 7 8") {
		printf("ascending\n");
	}
	else if (music == "8 7 6 5 4 3 2 1") {
		printf("descending\n");
	}
	else {
		printf("mixed\n");
	}
	return 0;
}