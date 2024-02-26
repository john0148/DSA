#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
using namespace std;

int lower_bound(vector<int> a, int target, int left, int right){
	int res = 0;
	int l = left, r = right;
	while(l <= r){
		int mid = l + (r-l)/2;
		if(a[mid] < target){
			l = mid + 1;
		}
		else{
			res = mid;
			r = mid - 1;
		}
	}

	return res;
}

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

#endif