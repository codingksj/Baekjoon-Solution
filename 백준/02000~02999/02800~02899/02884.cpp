#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

typedef struct _clock {
	int hour;
	int minute;
}Clock;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Clock current, alarm;
	int total_minute;
	cin >> current.hour >> current.minute;
	total_minute = current.hour * 60 + current.minute;
	if (total_minute < 45) {
		total_minute += 1440;
	}
	alarm.hour = (total_minute - 45) / 60;
	alarm.minute = (total_minute - 45) % 60;
	cout << alarm.hour << " " << alarm.minute << "\n";
	return 0;
}