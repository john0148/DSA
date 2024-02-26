#include "search.h"

void heapify(vector<int> &a, int n, int parent){
	int l = 2*parent;
	int r = 2*parent+1;
	int largest = parent;
	if((a[l] > a[largest]) && (l <= n)) largest = l;
	if((a[r] > a[largest]) && (r <= n)) largest = r;

	if(largest != parent){
		swap(a[largest], a[parent]);
		heapify(a, n, largest);
	}
}

void heap_sort(vector<int> &a, int n){
	// create heap structure
	for(int i = n/2; i >= 1; i--){
		heapify(a, n, i);
	}

	// swap the first element and the last element
	for(int i = n; i >= 2; i--){
		swap(a[1], a[i]);
		heapify(a, i-1, 1);
	}

}

