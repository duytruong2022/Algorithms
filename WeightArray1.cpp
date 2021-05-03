#include<stdio.h>
#include<limits.h>

int MaxWeight (int a[],int n) {
	int max = INT_MIN, sum = a[0];
	for (int i = 1; i < n; i++) {
		if (sum < 0)
			sum = a[i];
		else 
			sum += a[i];
		if (sum > max)
			max = sum;
	}
	return max;
}

int main () {
    int a[] = {-2, 11, -4, 13, -5, 2};
    printf ("%d", MaxWeight (a, 6));
}
