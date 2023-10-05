#include<iostream>
#include<sstream>
#include<bitset>
#include<set>
#include<unordered_map>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<tuple>
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
typedef unsigned long long ULL;
typedef long double LD;

typedef pair<char, char> Pcc;
typedef pair<char, int> Pci;
typedef pair<char, string> PcS;
typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, string> PiS;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> PSi;
typedef pair<string, LL> PSL;
typedef pair<string, string> PSS;

typedef map<int, int> Mapii;
typedef map<int, string> MapiS;
typedef map<LL, LL> MapLL;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;

typedef unordered_map<LL, LL> HashLL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

typedef struct Robot {
    int r;
    int c;
    int dir;
}Robot;

Robot MoveRobot(const Robot& robot, const int distance);
Robot TurnRobot(const Robot& robot, const int dir);
bool CheckPositionValidness(const Robot& robot, const int M);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Robot robot;
    string command;
    int N, M;
    int number;
    bool isValid = true;

    cin >> M >> N;
    
    robot = { 0,0,1 };

    while (isValid && N--) {
        cin >> command >> number;

        robot = (command == "MOVE") ?
            MoveRobot(robot, number) :
            TurnRobot(robot, number);

        isValid = CheckPositionValidness(robot, M);
    }

    isValid ?
        cout << robot.c << " " << robot.r << "\n" :
        cout << -1 << "\n";

    return 0;
}

Robot MoveRobot(const Robot& robot, const int distance) {
    Robot movedRobot;
    int dr[] = { 1,0,-1,0 };
    int dc[] = { 0,1,0,-1 };
    int nr = robot.r + dr[robot.dir] * distance;
    int nc = robot.c + dc[robot.dir] * distance;
    
    movedRobot = { nr,nc, robot.dir };

    return movedRobot;
};

Robot TurnRobot(const Robot& robot, const int dir) {
    Robot turnedRobot;
    int ndir = (robot.dir + 3 - 2 * dir) % 4;

    turnedRobot = { robot.r, robot.c, ndir };

    return turnedRobot;
};

bool CheckPositionValidness(const Robot& robot, const int M) {
    bool isValidR = !(robot.r<0 || robot.r>M);
    bool isValidC = !(robot.c<0 || robot.c>M);
    bool isValid = isValidR && isValidC;

    return isValid;
};
