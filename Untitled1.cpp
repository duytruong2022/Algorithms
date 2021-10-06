void swap(int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
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
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
	int i;
	int a[] = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4};
	
	partition(a,0,10);
	for (i = 0; i < 10; i++){
		printf("%d ", a[i]);
	}
}
