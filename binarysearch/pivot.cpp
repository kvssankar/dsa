// 3 5 1 2 3
     m
int findPivot(int array[], int size) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (array[mid] > array[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}