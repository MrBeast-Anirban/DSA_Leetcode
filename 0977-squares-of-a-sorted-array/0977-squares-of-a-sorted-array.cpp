/*Approach 1 :- First square the entire array then sort O(nlogn)
Approach 2 :- Use another array and two pointers to traverse and compare in the main array. O(n) space O(n) time
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int left = 0, right = nums.size()-1;
        for(int k = right; k >= 0; k--){
            if(abs(nums[left]) < abs(nums[right])){
                res[k] = nums[right]*nums[right--];
            }
            else{
                res[k] = nums[left]*nums[left++];
            }
        }
        return res;
    }
};