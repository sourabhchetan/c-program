#include <stdio.h>

int longestSubarrayWithSumK(int arr[], int n, int k) {
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum == k) {
                int len = j - i + 1;
                if (len > maxLen)
                    maxLen = len;
            }
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {10, 5, 2, 7, 1, -10};
    int k = 15;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = longestSubarrayWithSumK(arr, n, k);
    printf("Length of longest subarray with sum %d: %d\n", k, result);

    return 0;
}
