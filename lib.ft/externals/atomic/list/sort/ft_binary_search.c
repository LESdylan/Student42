void binarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) return;
        else if (arr[mid] > target)
            binarySearch(arr, left, mid - 1, target);
        else
            binarySearch(arr, mid + 1, right, target);
    }
}
