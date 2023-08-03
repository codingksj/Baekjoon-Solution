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

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

    map<int, string> archive = {
       {1995, "ITMO"},
       {1996, "SPbSU"},
       {1997, "SPbSU"},
       {1998, "ITMO"},
       {1999, "ITMO"},
       {2000, "SPbSU"},
       {2001, "ITMO"},
       {2002, "ITMO"},
       {2003, "ITMO"},
       {2004, "ITMO"},
       {2005, "ITMO"},
       {2006, "PetrSU, ITMO"},
       {2007, "SPbSU"},
       {2008, "SPbSU"},
       {2009, "ITMO"},
       {2010, "ITMO"},
       {2011, "ITMO"},
       {2012, "ITMO"},
       {2013, "SPbSU"},
       {2014, "ITMO"},
       {2015, "ITMO"},
       {2016, "ITMO"},
       {2017, "ITMO"},
       {2018, "SPbSU"},
       {2019, "ITMO"}
    };
    int year;

    cin >> year;
    cout << archive[year];
	return 0;
}