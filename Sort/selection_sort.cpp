#include "search.h"

void selection_sort(vector<int> &a, int n){
	for(int i = 1; i <= n; i++){
		int index_min = i;
		for(int j = i; j <= n; j++){
			if(a[j] < a[index_min]){
				index_min = j;
			}
		}

		if(a[index_min] != i) swap(a[i], a[index_min]);
	}
}


int main(){
	freopen("input.txt", "r", stdin);
	freopen("a.txt", "w", stdout);

	int n; cin >> n;
	vector<int> a(n+1);
	for(int i = 1; i <=  n; i++){
		cin >> a[i];
	}

	insertion_sort(a, n);

	for(int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << "\n";

}