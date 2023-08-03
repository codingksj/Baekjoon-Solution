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
	map<string, string> cheer = {
		{"SONGDO" , "HIGHSCHOOL"},
		{"CODE" , "MASTER"},
		{"2023" , "0611"},
		{"ALGORITHM" , "CONTEST"}
	};
	string S;
	cin >> S;
	cout << cheer[S];
	return 0;
}