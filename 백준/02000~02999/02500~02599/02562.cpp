#include <iostream>
#include <string>

using namespace std;

int main() {
    int n=9;
    int arr[n];
    int index=0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int maxV = 0;
    for(int i=0;i<n;i++){
        if(maxV<arr[i]){
            maxV = arr[i];
            index = i+1;
        }
    }
    cout << maxV << '\n';
    cout << index << '\n';
    return 0;
}