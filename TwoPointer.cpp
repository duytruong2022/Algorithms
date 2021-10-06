
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

int twoPointSearch (long long T, int n, long long a[]) {
    int i, j, sum;
    i = 0;
    j = n - 1;
    while (i != j)
    {
        sum = a[i] + a[j];
        if (sum == T)
            return 1;
        else if (sum > T)
            j--;
        else
            i++;
    }
    return 0;
}

int main () {
    long long a[] = {5, 9, 9, 11, 25, 30, 55};
    int n = 7, T = 36;
    quickSort (a, 0, n - 1);
    printf ("%d", twoPointSearch(T, n, a));
}