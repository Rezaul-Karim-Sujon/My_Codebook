#include <bits/stdc++.h>
using namespace std;

int a[100008];
int n;
int q;
int binary_right(int left, int right, int x)
{
	int mid;

	mid = (left + right) / 2;

	if((mid+1 == n ||a[mid+1] > x) and (mid == 0 || a[mid-1] < x)) {

		if(a[mid] > x) {
			mid--;
		}
		return mid;
	}

	if(left > right) {
		return -1;
	}

	if(a[mid] < x) {
		binary_right(mid +1, right, x);
	}

	else {
		binary_right(left, mid - 1, x);
	}

}

int main()
{
    int x,y,right;
    scanf("%d", &n);
		scanf("%d", &q);

		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < q; i++) {
			scanf("%d", &x);
			scanf("%d", &y);

			right = binary_right(0, n-1, y);
			cout << right << endl;
}
}
