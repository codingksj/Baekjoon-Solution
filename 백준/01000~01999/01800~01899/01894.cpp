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
typedef pair<int, int> Pii;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, string> UMapSS;
typedef vector<string> Words;

typedef struct Point {
    double x;
    double y;

    bool operator <(const Point& other) const {
        if (x != other.x) {
            return x < other.x;
        }
        return y < other.y;
    }
}Point;

typedef struct _vector {
    double dx;
    double dy;
}Vector;

void MakeUniquePointsArray(Point uPoints[], Point Points[]);
Vector MakeVector(Point& src, Point& dest);
Vector CombineVector(Vector& Va, Vector& Vb);
Point MovePoint(Point& P, Vector& V);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Point points[4], p4;
    Point uPoints[3];
    Vector V1, V2, Vsum;

    cout.precision(3);
    cout << fixed;

    while (cin >>
        points[0].x >> points[0].y >>
        points[1].x >> points[1].y >>
        points[2].x >> points[2].y >>
        points[3].x >> points[3].y
        ) {

        MakeUniquePointsArray(uPoints, points);

        V1 = MakeVector(uPoints[0], uPoints[1]);
        V2 = MakeVector(uPoints[0], uPoints[2]);

        Vsum = CombineVector(V1, V2);

        p4 = MovePoint(uPoints[0], Vsum);

        cout << p4.x << " " << p4.y << "\n";
    }

    return 0;
}


void MakeUniquePointsArray(Point uPoints[], Point Points[]) {
    map<Point, int> pointCount;
    int i = 1;

    for (int i = 0; i < 4; i++) {
        pointCount[Points[i]]++;
    }

    for (pair<const Point, int>& p : pointCount) {
        if (p.second == 2) {
            uPoints[0] = p.first;
        }
        else {
            uPoints[i++] = p.first;
        }
    }
};

Vector MakeVector(Point& src, Point& dest) {
    Vector V;

    V.dx = dest.x - src.x;
    V.dy = dest.y - src.y;

    return V;
};

Vector CombineVector(Vector& Va, Vector& Vb) {
    Vector resV;

    resV.dx = Va.dx + Vb.dx;
    resV.dy = Va.dy + Vb.dy;

    return resV;
};

Point MovePoint(Point& P, Vector& V) {
    Point newP;

    newP.x = P.x + V.dx;
    newP.y = P.y + V.dy;

    return newP;
};