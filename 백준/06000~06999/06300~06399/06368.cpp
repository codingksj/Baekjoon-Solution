#include<bits/stdc++.h>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 100;
	constexpr auto Rng = views::iota;
	constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

map<char, string> morse = {
	{'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
	{'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
	{'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
	{'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
	{'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
	{'Z', "--.."}, {'_', "..--"}, {'.', "---."}, {',', ".-.-"}, {'?', "----"}
};
map<string, char> rMorse = {
	{".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'}, {".", 'E'},
	{"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'}, {"..", 'I'}, {".---", 'J'},
	{"-.-", 'K'}, {".-..", 'L'}, {"--", 'M'}, {"-.", 'N'}, {"---", 'O'},
	{".--.", 'P'}, {"--.-", 'Q'}, {".-.", 'R'}, {"...", 'S'}, {"-", 'T'},
	{"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'}, {"-.--", 'Y'},
	{"--..", 'Z'}, {"..--", '_'}, {"---.", '.'}, {".-.-", ','}, {"----", '?'}
};
int len[MAX];
string s, t, res;
int TC, tc, N;

int main() {
	FastIO();
	SetUp();

	cin >> TC;

	while (TC--) {
		Input();
		Solve();
		Output();
	}

	return 0;
}

void FastIO() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	return;
};

void SetUp() {
	return;
};

bool Input() {
	cin >> s;

	return true;
};

void Solve() {
	int cnt = 0;
	auto MakeMorse = [&cnt](const string& s) {
		string res, t;
		for (char ch : s) {
			t = morse[ch];
			res += t;
			len[cnt++] = t.size();
		};
		return res;
	};
	auto Decrypt = [&cnt](const string& s) {
		string res;
		for (int i = cnt - 1, ptr = 0; i >= 0; i--) {
			string key;
			int l = len[i];
			while (l--) {
				key += s[ptr++];
			}
			res += rMorse[key];
		}
		return res;
	};
	t = MakeMorse(s);
	res = Decrypt(t);
};

void Output() {
	println("{}: {}", ++tc, res);
	return;
};
