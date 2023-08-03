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

typedef struct _position {
	double speed;
	int weight;
	int strength;
}Position;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	const Position WR = { 4.5,150,200 };
	const Position LM = { 6.0, 300, 500 }; 
	const Position QB = { 5.0, 200,300 };
	Position player;

	bool IsWR, IsLM, IsQB;
	string position;

	while (true) {
		position = "";
		cin >> player.speed >> player.weight >> player.strength;
		if (player.speed == 0 && player.weight == 0 && player.strength == 0) {
			break;
		}

		IsWR = player.speed <= WR.speed
			&& player.weight >= WR.weight
			&& player.strength >= WR.strength;

		IsLM = player.speed <= LM.speed
			&& player.weight >= LM.weight
			&& player.strength >= LM.strength;

		IsQB = player.speed <= QB.speed
			&& player.weight >= QB.weight
			&& player.strength >= QB.strength;

		position += IsWR ? "Wide Receiver " : "";
		position += IsLM ? "Lineman " : "";
		position += IsQB ? "Quarterback " : "";

		cout << (position == "" ? "No positions" : position) << "\n";
	}
	return 0;
}