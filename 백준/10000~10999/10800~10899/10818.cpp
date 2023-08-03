#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int minV = 1000000;
    int maxV = -1000000;
    for(int i=0;i<n;i++){
        if(minV>arr[i]){
            minV = arr[i];
        }
        if(maxV<arr[i]){
            maxV = arr[i];
        }
    }
    cout << minV << ' '<<maxV;
    return 0;
}