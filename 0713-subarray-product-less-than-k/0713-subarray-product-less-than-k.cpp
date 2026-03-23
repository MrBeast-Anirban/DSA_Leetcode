/*
sliding window technique with two pointer solution
if we have an array [a,b,c] and want to add 'd' when how many consecutive subarrays will be there?
[a,b,c,d][b,c,d][c,d][d] = 4 

*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0 || k == 1){
            return 0;
        }
        int i = 0, j = 0, product = 1, count = 0;
        while(j < n){
            product *= nums[j];
            //incase if the product of the subarray i to j exceeds or equal to k remove ith element from subarray
            while(i <= j && product >= k){
                product /= nums[i];
                i++;
            }
            //on adding a new j how many new subarrays we get (j-i)+1
            count += (j-i)+1;
            j++;
        }
        return count;
    }
};