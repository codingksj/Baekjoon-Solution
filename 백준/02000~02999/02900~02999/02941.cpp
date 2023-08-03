#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
    vector<string> croatian = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
    int idx;
    string word;
    cin >> word;
    for (int i = 0; i < croatian.size(); i++)
    {
        while (1) {
            idx = word.find(croatian[i]);
            if (idx == string::npos) {
                break;
            }
            word.replace(idx, croatian[i].length(), "*");
        }
    }
    cout << word.length();
	return 0;
}