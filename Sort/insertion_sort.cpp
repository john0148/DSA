#include "search.h"

void insertion_sort(vector<int> &a, int n){
	for(int i = 2; i <= n; i++){
		int j = i-1, tmp;
		a[0] = tmp = a[i];
		while(a[j] > tmp){
			a[j+1] = a[j]; j--;
		}
		a[j+1] = tmp;
	}
}


void binary_insertion_sort(vector<int> &a, int n){
	for(int i = 2; i <= n; i++){
		int j = lower_bound(a, a[i], 1, i);
		int tmp = a[i];
		for(int k = i; k > j; k--){
			a[k] = a[k-1];
		}
		a[j] = tmp;
	}
}


