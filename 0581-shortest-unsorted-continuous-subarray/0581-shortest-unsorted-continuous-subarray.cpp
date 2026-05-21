class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n-1;
        if (n <= 1) return 0;
        // 1. Find the first element out of order from the left
        while (i < n - 1 && nums[i] <= nums[i + 1]) {
            i++;
        }

        // If the whole array is already sorted
        if (i == n - 1) return 0;

        // 2. Find the first element out of order from the right
        while (j > 0 && nums[j] >= nums[j - 1]) {
            j--;
        }
        int startIndex = i, endIndex = j;
        //finding min and max in the subarray[startIndex to endIndex]
        int max = INT_MIN, min = INT_MAX;
        while(i <= j){
            if(nums[i] > max) max = nums[i];
            if(nums[i] < min) min = nums[i];
            i++;
        }
        // find out the index where the min belong between index [0 to startIndex]
        int left = 0;
        while(left < startIndex && nums[left] <= min) left++;
        // find out the index where the max belong between index [endIndex to nums.size()-1]
        int right = n-1;
        while(right > endIndex && nums[right] >= max) right--;
        //return the length of the subarray [left to right]
        return right-left+1;
    }
};