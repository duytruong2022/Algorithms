#include<stdio.h>

long long B_search (long long a[], long long first, long long last, long long x) {
	long long center;
	if (last >= first) {
		center = (last + first) / 2;
		if (a[center] == x)
			return 1;
		else if (a[center] > x)
			return B_search (a, first, center - 1, x);
		else
			return B_search (a, center + 1, last, x);
	}
	return 0;
}

long long main() {
	long long a[] = {1, 3, 5, 7, 9, 12, 15};
	prlong longf("%d", B_search (a, 0, 6, 9));
}
