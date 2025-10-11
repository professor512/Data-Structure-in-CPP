#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n){
    for(int i = 0; i <= n - 2; i++){
        int mini = i;
        for(int j = i; j <= n - 1; j++){
            if(arr[j] < arr[mini]) mini = j;
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}



int main(){
    int n;
    cout << "Enter No of Elements" <<endl;
    cin >> n;
    int arr[n];

    
    cout << "Enter Elements to sort" <<endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    selection_sort(arr, n);
    

    cout << "sorted: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
