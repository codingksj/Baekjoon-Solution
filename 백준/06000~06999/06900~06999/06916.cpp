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

#define DIGIT 10
#define LENGTH 100

typedef long long LL;
typedef pair<int, int> Pii;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	char segment[DIGIT][LENGTH] = {
        " * * *\n"
        "*     *\n"
        "*     *\n"
        "*     *\n"
        "\n"
        "*     *\n"
        "*     *\n"
        "*     *\n"
        " * * *\n",

        "\n"
        "      *\n"
        "      *\n"
        "      *\n"
        "\n"
        "      *\n"
        "      *\n"
        "      *\n"
        "\n",

        " * * *\n"
        "      *\n"
        "      *\n"
        "      *\n"
        " * * *\n"
        "*\n"
        "*\n"
        "*\n"
        " * * *\n",

        " * * *\n"
        "      *\n"
        "      *\n"
        "      *\n"
        " * * *\n"
        "      *\n"
        "      *\n"
        "      *\n"
        " * * *\n",

        "\n"
        "*     *\n"
        "*     *\n"
        "*     *\n"
        " * * *\n"
        "      *\n"
        "      *\n"
        "      *\n",

        " * * *\n"
        "*\n"
        "*\n"
        "*\n"
        " * * *\n"
        "      *\n"
        "      *\n"
        "      *\n"
        " * * *\n",

        " * * *\n"
        "*\n"
        "*\n"
        "*\n"
        " * * *\n"
        "*     *\n"
        "*     *\n"
        "*     *\n"
        " * * *\n",

        " * * *\n"
        "      *\n"
        "      *\n"
        "      *\n"
        "\n"
        "      *\n"
        "      *\n"
        "      *\n",

        " * * *\n"
        "*     *\n"
        "*     *\n"
        "*     *\n"
        " * * *\n"
        "*     *\n"
        "*     *\n"
        "*     *\n"
        " * * *\n",

        " * * *\n"
        "*     *\n"
        "*     *\n"
        "*     *\n"
        " * * *\n"
        "      *\n"
        "      *\n"
        "      *\n"
        " * * *\n"

	};
    int N;
    cin >> N;
    cout << segment[N];
	return 0;
}