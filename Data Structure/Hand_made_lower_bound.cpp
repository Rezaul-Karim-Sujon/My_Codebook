#include <bits/stdc++.h>
using namespace std;

int a[100008];
int n;
int q;
int binary_left(int left, int right, int x)
{
	int mid;

	mid = (left + right) / 2;

	if((mid+1 == n ||a[mid+1] > x) and (mid == 0 || a[mid-1] < x)) {
		if(a[mid] < x) {
			mid++;

		}
		return mid;
	}

	if(left > right) {
		return -9999;
	}

	if(a[mid] < x) {
		binary_left(mid +1, right, x);
	}

	else {
		binary_left(left, mid - 1, x);
	}

}

int main()
{
    int x,y,left;
    scanf("%d", &n);
		scanf("%d", &q);

		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < q; i++) {
			scanf("%d", &x);
			scanf("%d", &y);

			left = binary_left(0, n-1, x);
			cout << left << endl;
}
}
