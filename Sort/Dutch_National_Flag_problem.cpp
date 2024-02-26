#include "search.h"

void sort012(vector<int> &a, int n){
	int l, m , r;
	l = m = 1; r = n;
	while(m <= r){
		if(a[m] == 0){
			swap(a[l++], a[m++]);
		} else if(a[m] == 1){
			m++;
		} else{
			swap(a[m], a[r--]);
		}
	}
}



int main(){
	freopen("input.txt", "r", stdin);
	freopen("a.txt", "w", stdout);
	int n; cin >> n;
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++) cin >> a[i];

	sort012(a, n);
	for(int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << endl;
}