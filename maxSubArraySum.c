#include <limits.h>
#include <stdio.h>
#include <math.h>


int main() {
	int nums[] = {-1, 0, -2};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
    int maxSum = maxSubArraySum(nums, 0, numsSize - 1);
    printf("maxSum is %d\n", maxSum);
    return maxSum;
}


int maxSubArraySum(int A[], int left, int right) {
    if (left > right) {
        return -INT_MAX;
    }

    if (left == right) {
        return A[left];
    }
    
    if (right - left == 1){
        if (A[left] >= (A[left] + A[right]) && A[left] >= A[right]){
            return A[left];
        }
        else if (A[right] >= (A[left] + A[right]) && A[right] >= A[left]){
            return A[right];
        }
        else{
            return A[left] + A[right];
        }
        
    	// return fmax(fmax(A[left], A[left] + A[right]), A[right]);
	}

    int mid = (left + right) / 2;
    
    int leftMaxSum = maxSubArraySum(A, left, mid - 1);

    int rightMaxSum = maxSubArraySum(A, mid + 1, right);

    int crossMaxSum = maxCrossingSum(A, left, mid, right);

    if (leftMaxSum >= rightMaxSum && leftMaxSum >= crossMaxSum){
        return leftMaxSum;
    }
    else if (rightMaxSum >= leftMaxSum && rightMaxSum >= crossMaxSum){
        return rightMaxSum;
    }
    else{
        return crossMaxSum;
    }
//    return fmax(fmax(leftMaxSum, rightMaxSum), crossMaxSum);
}

int maxCrossingSum(int A[], int left, int mid, int right) {
    int leftSum = -INT_MAX, rightSum = -INT_MAX;
    int sum = 0;
    int i = 0;

    
    for (i = mid; i >= left; i--) {
        sum += A[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }

    sum = 0;
    
    for (i = mid + 1; i <= right; i++) {
        sum += A[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }

    if (leftSum >= rightSum && leftSum >= (leftSum + rightSum)){
        return leftSum;
    }
    else if (rightSum >= leftSum && rightSum >= (leftSum + rightSum)){
        return rightSum;
    }
    else{
        return leftSum + rightSum;
    }
}
