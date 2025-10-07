#include<bits/stdc++.h>
using namespace std;

void revArr(int i, int arr[], int n){
   
    if(i >= n/2) return;

    swap(arr[i], arr[n-i-1]);

    revArr(i+1, arr, n);

}

int main(){
    int n;
    cout << "Enter Array Size: ";
    cin >> n;

    int arr[n]; 
    cout << "Enter Array Elements: "
    for(int i = 0; i < n; i++) cin >> arr[i];

    revArr(0, arr, n);

    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}