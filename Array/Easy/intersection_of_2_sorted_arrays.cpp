// https://www.naukri.com/code360/problems/intersection-of-2-arrays_1082149
#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	vector < int > intersecArr;
	int i = 0, j = 0;


	while(i < n && j < m){
		if(arr1[i] < arr2[j]){
			i++;
		}
		else if( arr2[j] < arr1[i]){
			j++;
		}
		else{
			intersecArr.push_back(arr1[i]);
			i++;
			j++;
		}
	}
	return intersecArr;
}
