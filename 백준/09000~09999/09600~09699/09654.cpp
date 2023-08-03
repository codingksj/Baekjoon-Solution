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
#include<iomanip>

using namespace std;

typedef long long LL;

struct Ship {
	string name;
	string shipClass;
	string deployment;
	int inService;
};

void printShip(const Ship& ship) {
	cout << setw(15) << left << ship.name
		<< setw(15) << left << ship.shipClass
		<< setw(11) << left << ship.deployment
		<< setw(10) << ship.inService << "\n";
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
    Ship ships[] = {
        {"N2 Bomber", "Heavy Fighter", "Limited", 21},
        {"J-Type 327", "Light Combat", "Unlimited", 1},
        {"NX Cruiser", "Medium Fighter", "Limited", 18},
        {"N1 Starfighter", "Medium Fighter", "Unlimited", 25},
        {"Royal Cruiser", "Light Combat", "Limited", 4}
    };

    cout << setw(15) << left << "SHIP NAME"
        << setw(15) << left << "CLASS"
        << setw(11) << left << "DEPLOYMENT"
        << setw(10) << "IN SERVICE" << "\n";

    for (const auto& ship : ships) {
        printShip(ship);
    }
	return 0;
}