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

void quickSort (long long arr[], long long low, long long high)
{
    if (low < high)
    {
        long long pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int twoPointSearch (long long T, long long n, long long m, long long a[], long long b[]) {
    int i, j;
    long long sum;
    for (i = n - 1; i > 0; i--)
        for (j = 0; j < m; j++)
            if (a[i] - b[j] == T){
                printf ("%lld %lld", a[i], b[j]);
                return 1;
            }
}

int main () {
    long long m,n,i, suma = 0, sumb = 0, div;
    long long *a, *b;
    scanf ("%lld %lld", &m, &n);
    a = (long long*) malloc(m * sizeof(long long));
    b = (long long*) malloc(n * sizeof(long long));
    for (i = 0; i < m; i++) {
        scanf("%lld", &a[i]);
        suma += a[i];
    }
    for (i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        sumb += b[i];
    }
    div = suma - sumb;
    quickSort (a, 0, m -1);
    quickSort (b, 0, n-1);
    twoPointSearch (div/2, m, n, a, b);
}