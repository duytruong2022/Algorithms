#include<stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void swap(long long &a, long long &b) {
	long long temp;
	temp = a;
	a = b;
	b = temp;
}
long long partition (long long arr[], long long low, long long high)
{
    long long pivot = arr[high];    // pivot
    long long left = low;
    long long right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++; 
        while(right >= left && arr[right] > pivot) right--; 
        if (left >= right) break; 
        swap(arr[left], arr[right]);
        left++;
        right--; 
    }
    swap(arr[left], arr[high]);
    return left; 
}
void quickSort(long long arr[], long long low, long long high)
{
    if (low < high)
    {
        long long pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

long long B_search (long long a[], long long first, long long last, long long x) {
	long long center;
	if (x > a[last]) return last;
	if (last >= first) {
		center = (last + first) / 2;
		if (a[center] == x)
			return center;
		else if (a[center] > x)
			return B_search (a, first, center - 1, x);
		else
			return B_search (a, center + 1, last, x);
	}
	else
		return last;
}

int main() {
	long long i, M, N, count, k, kt, vt1, vt2;
	long long *a, *b, F, L;
	cin >> N;
	cin >> M;
	a = (long long*) malloc(N * sizeof(long long));
	b = (long long*) malloc(N * sizeof(long long));
	for (i = 0; i < N; i++)
		cin >> a[i];
	quickSort(a, 0, N - 1);
	count = 0;
	b[0] = a[0];
	for (i = 1; i < N; i++) {
		if (a[i] != a[i - 1]) {
			count++;
			b[count] = a[i];
		}	
	}
	for (k = 0; k < M; k++) {
		cin >> F;
		cin >> L;
		if (L < F) {
			kt = 0;
			printf("%d\n", kt);
			continue;
		}
		kt = 0;
		vt1 = B_search(b, 0, count, L);
		vt2 = B_search(b, 0, count, F);
		kt += vt1 - vt2 + 1;
		if ((F == b[vt2]) && (F == L))
			kt = 1;
		if (F != b[vt2]) // 10 20 30 40 50 60
			kt--;
		printf("%d\n", kt);
	}
}
