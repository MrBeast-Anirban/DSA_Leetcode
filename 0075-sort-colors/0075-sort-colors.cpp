/*
Easy solution -> Sort the array inplace :: O(nlogn) time and O(1) space complexity
General Solution -> Use a dictionary to keep the count of color in each iteration then using that count make the colors inplace ordered :: O(n) time and O(1) space complexity.
Optimized solution -> Use three pointer approach. Two pointers at start and end to fix two of the colors ( incase red, blue) and use the third pointer to iterate between the entire array to arrange red and blue from both the sides.
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0, w = 0, b = nums.size()-1;
        while(w <= b){
            if(nums[w] == 0){
                swap(nums[r], nums[w]);
                r++;
                w++;
            }
            else if(nums[w] == 1){
                w++;
            }
            else{
                swap(nums[w], nums[b]);
                b--;
            }
        }
    }
};