// bubble sort recursive 
#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n){
    for(int i = n - 1; i >= 0; i--){
        
        for(int j = 0; j <= i - 1; j++){
            if(arr[j] > arr[j+1]){
                
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
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
    
    bubble_sort(arr, n);
    

    cout << "sorted: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
