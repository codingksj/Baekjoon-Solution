#include<bits/stdc++.h>
#include<random>

using namespace std;

int kth(vector<int> &a, int k) {
  random_device rd;
  mt19937 gen(rd());
  shuffle(a.begin(), a.end(), gen);
  nth_element(a.begin(), a.begin() + k - 1, a.end());
  return a[k-1];
}
