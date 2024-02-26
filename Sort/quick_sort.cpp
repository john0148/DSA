#include "search.h"


using namespace std;

// int quick(vector<int> &a, int l, int r){ 
// 	int p =  
// 	swap(a[p], a[r]);
// 	while(l < r){
// 		while(a[l] < a[p]) l++;
// 		while(a[r] >= a[p]) r--;
// 		if(l < r) {
// 			swap(a[l], a[r]);
// 			l++; r--;		
// 		}
// 	}
// 	swap(a[p], a[l]);
// 	return l;
// }

// int partition(vector<int> &a, int l, int r){
// 	int n = r;
// 	int pivot = a[l];
// 	int i = l-1, j = r + 1;
// 	while(1){
// 		do{
// 			i++;
// 		}while(a[i] < pivot);
// 		do{
// 			j--;
// 		}while(a[j] > pivot);
// 		if(i < j){
// 			swap(a[i], a[j]);
// 			for(int k = 1; k <= n; k++) cout << a[k] << " ";
// 			cout << endl;
// 		}
// 		else return j;
// 	}
// 	return j;
// }

void partition_1(int* a, int l, int r, int& i, int& j){
	int lo, mid, hi;
	lo = mid = l; hi = r;

	int v = a[l];
	while(mid <= hi){
		if(a[mid] < v){
			swap(a[mid++], a[lo++]);
		} else if(a[mid] == v){
			mid++;
		} else{
			swap(a[mid], a[hi--]);
		}
	}

	i = lo - 1;
	j = mid;
}


void partition_2(int* a, int l, int r, int& i, int& j, int pivot){
	int lo, mid, hi;
	lo = mid = l; hi = r;

	int v = a[pivot];
	while(mid <= hi){
		if(a[mid] < v){
			swap(a[mid++], a[lo++]);
		} else if(a[mid] == v){
			mid++;
		} else{
			swap(a[mid], a[hi--]);
		}
	}

	i = lo - 1;
	j = mid;
}


void quick_sort(int* a, int l, int r){
	if(l >= r) return;
	int i, j;
	partition_1(a, l, r, i, j);

	quick_sort(a, l, i);
	quick_sort(a, j, r);
}


int quick_select(int* a, int l, int r, int k){
	int i, j;
	partition_1(a, l, r, i, j);
	if(k <= i) return quick_select(a, l, i, k);
	else if((i < k) && (k < j)) return a[i+1];
	else return quick_select(a, j, r, k);
}

void insertion_sort(int* a, int n){
	for(int i = 2; i <= n; i++){
		int tmp, j;
		a[0] = tmp = a[i];
		j = i-1;
		while(a[j] > tmp){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = tmp;
	}
}

int findMedian(int* a, int n){
	insertion_sort(a, n);
	return a[(n+1)/2];
}

int kthSmallest(int* a, int l, int r, int k){
	if(k > 0 && k <= r-l+1){
		int n = (r-l+1);
		int i;
		int median[(n+4)/5 + 1] = {};
		for(i = 1; i <= n/5; i++){
			median[i] = findMedian(a + (i-1)*5, 5);
		}

		if((i-1)*5 < n){
			median[i] = findMedian(a + (i-1)*5, n%5);
		}

		for(int i = 1; i <= (n+4)/5; i++) cout << median[i] << " ";
		cout << endl;

		for(int i = l; i <= r; i++) cout << a[i] << " ";
		cout << endl;
		// int medofMed = (i == 1) ? median[i] : kthSmallest(median, 1, i, (i+1)/2);

		// int x, y;
		// partition_2(a, l, r, x, y, medofMed);
		// if(k <= x) return kthSmallest(a, l, x, k);
		// else if((x < k) && (k < y)) return a[i+1];
		// else return kthSmallest(a, y, r, k);
	}
	return INT_MAX;
}


int main(){
	freopen("input.txt", "r", stdin);
	freopen("a.txt", "w", stdout);
	int n; cin >> n;
	int k; cin >> k;
	int a[n+1];
	for(int i = 1; i <= n; i++) cin >> a[i];

	kthSmallest(a, 1, n, k);
	// for(int i = 1; i <= n; i++) cout << a[i] << " ";
	// cout << endl;

}