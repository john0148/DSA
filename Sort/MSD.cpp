#include <iostream>
#include <vector>
#include <climits>
#include <math.h>

using namespace std;


int digit(int a, int d){
	return (int)(a / pow(10, d-1)) % 10;
}

void MSD_sort(int* a, int l, int r, int d){
	if(l >= r || d <= 0){
		return;
	}

	int n = r - l + 1;

	int count[11] = {};


	for(int i = l; i <= r; i++){
		int c = digit(a[i], d);
		count[c]++;
	} 

	for(int i = 1; i <= 10; i++) count[i] += count[i-1];

	int tmp[n+1] = {};
	for(int i = l; i <= r; i++){
		int c = digit(a[i], d);
		tmp[count[c]] = a[i];
		count[c]--;
	}

	for(int i = l; i <= r; i++){
		a[i] = tmp[i - l + 1];
	}

	for(int i = 0; i <= 9; i++){
		MSD_sort(a, l + count[i], l + count[i+1] - 1, d-1);
	}

}

int main(){

	freopen("input.txt", "r", stdin);
	freopen("a.txt", "w", stdout);
	int n; cin >> n;
	int a[n+1];
	for(int i = 1; i <= n; i++) cin >> a[i];

	MSD_sort(a, 1, n, 9);

	for(int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << endl;

}