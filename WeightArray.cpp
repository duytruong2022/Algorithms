#include<stdio.h>
#include<limits.h>
int MaxRight (int a[], int i, int j) {
    int max = INT_MIN;
    int sum = 0;
    for (int k = i; k <= j; k++) {
        sum += a[k];
        if (sum > max) {
            max = sum;
        }
    }
    return max;
}

int MaxLeft (int a[], int i, int j) {
    int max = INT_MIN;
    int sum = 0;
    for (int k= j; k >= i; k--) {
        sum += a[k];
        if (sum > max) {
            max = sum;
        }
    }
    return max;
}

int MaxWeight (int a[], int i, int j) {
    if (i == j) {
        return a[i];
    }
    int k = (i + j) / 2;
    int leftWeight = MaxWeight (a, i, k);
    int rightWeight = MaxWeight (a, k + 1, j);
    int centreWeight = MaxLeft (a, i, k) + MaxRight (a, k + 1, j);   
    if (leftWeight > rightWeight)
        if (leftWeight > centreWeight)
            return leftWeight;
        else
            return centreWeight;
    else
        if (rightWeight > centreWeight)
            return rightWeight;
        else
            return centreWeight;
}

int main () {
    int a[] = {-2, 11, -4, 13, -5, 2};
    printf ("%d", MaxWeight (a, 0, 5));
}
