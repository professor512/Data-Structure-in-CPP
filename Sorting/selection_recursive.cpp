#include<bits/stdc++.h>
using namespace std;

void selection_recursive(int arr[], int start, int n){
    
    if(start >= n-1) return;

    int minIndex = start;

    for(int i = start + 1; i <= n-1; i++){

        if(arr[i] < arr[minIndex]) minIndex = i;

    }
    if(minIndex != start){
        int temp = arr[start];
        arr[start] = arr[minIndex];
        arr[minIndex] = temp;
    }
    selection_recursive(arr, start + 1, n);
}


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    selection_recursive(arr, 0, n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
