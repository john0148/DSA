#include "search.h"

void flash_sort(vector<int> &a, int n){

	//find the maximum and minimum of array
	int min, max;
	min = max = a[1];
	for(int i = 2; i <= n; i++){
		if(a[i] < min) min = a[i];
		if(a[i] > max) max = a[i];
	}


	//each segment determine the number of elements
	int m = 0.43*n;
	vector<int> l(m+1, 0);
	for(int i = 1; i <= n; i++){
		int k = (m-1)*(a[i] - min)/(max - min) + 1;
		l[k]++;
	}

	for(int i = 2; i <= m; i++) l[i] += l[i-1];

	//transmit each element to correct segment
	int count = 1, i = 1, k = m;
	while(count < n){
		while(i > l[k]){
			i++;
			k = (m-1)*(a[i] - min)/(max - min) + 1;
		}

		int x, y;
		x = a[i];
		while(i <= l[k]){
			k = (m-1)*(x - min)/(max - min) + 1;
			y = a[l[k]]; a[l[k]] = x; x = y;
			l[k]--; count++;
		}
	}

	//insertion_sort
	for(int k = 2; k <= m; k++){
		for(int i = l[k]; i > l[k-1]; i--){
			if(a[i] > a[i+1]){
				int tmp = a[i], j = i;
				while(tmp > a[j + 1]){
					a[j] = a[j+1];
					j++;
				}
				a[j] = tmp;
			}
		}
	}

}
