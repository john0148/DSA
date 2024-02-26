#include "search.h"

void bubble_sort(vector<int> &a, int n){
	for(int i = 1; i <= n; i++){
		for(int j = n; j >= i + 1; j--){
			if(a[j] < a[j-1]) swap(a[j], a[j-1]);
		}
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

	bubble_sort(a, n);
	
	for(int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << "\n";

}