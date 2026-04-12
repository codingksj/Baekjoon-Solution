#include<bits/stdc++.h>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
using Ti3 = tuple<int, int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
	constexpr string_view SEPS = " \n";
	constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
	constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
	constexpr double EPS = 1E-9;
	constexpr int DIGITS = 10, ALPHABETS = 26, MAX = 1E+5;
	constexpr auto Rng = views::iota;
	constexpr auto Rev = views::reverse;
	constexpr auto Split = views::split;
	constexpr auto Take = views::take;
}
using namespace CONSTS;

class Vec {
public:
	double x, y;
	Vec() : x(0), y(0) {}
	Vec(double x, double y) : x(x), y(y) {}
	Vec operator-(const Vec& other) const { return Vec(x - other.x, y - other.y); }
	Vec operator-() const { return Vec(-x, -y); }
	double Dot(const Vec& other) const { return x * other.x + y * other.y; }
	double Cross(const Vec& other) const { return x * other.y - y * other.x; }
};
class Point {
public:
	double x, y;
	Point() : x(0), y(0) {}
	Point(double x, double y) : x(x), y(y) {}
	Point operator+(const Vec& v) const { return Point(x + v.x, y + v.y); }
	Vec operator-(const Point& other) const { return Vec(x - other.x, y - other.y); }
	double GetDist(const Point& other) const {
		double dx = x - other.x, dy = y - other.y;
		return sqrt(dx * dx + dy * dy);
	}
	double CCW(const Point& b, const Point& c) const {
		return (b.x - x) * (c.y - y) - (b.y - y) * (c.x - x);
	}
};
void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

Point dots[MAX];
Point B, C;
int N;
double totalDist;

int main() {
	FastIO();
	SetUp();

	Input();
	Solve();
	Output();

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
	cin >> N;
	for (auto& [x, y] : dots | Take(N)) {
		cin >> x >> y;
	}
	cin >> C.x >> C.y >> B.x >> B.y;

	return true;
};

void Solve() {
	Point A = {2 * C.x - B.x, 2 * C.y - B.y};
	double r = C.GetDist(A);
	for (const auto& P : dots | Take(N)) {
		int ccw = A.CCW(B, P);
		if (ccw >= 0) {
			totalDist += max(0.0, P.GetDist(C) - r);
		}
		else {
			Vec vAB = B - A;
			Vec vAP = P - A;
			Vec vBP = P - B;
			if (vAB.Dot(vAP) < 0) {
				totalDist += P.GetDist(A);
			}
			else if ((-vAB).Dot(vBP) < 0) {
				totalDist += P.GetDist(B);
			}
			else {
				double dist = abs(vAB.Cross(vAP)) / sqrt(vAB.Dot(vAB));
				totalDist += dist;
			}
		}
	}
	return;
};

void Output() {
	println("{}", totalDist);
	return;
};
