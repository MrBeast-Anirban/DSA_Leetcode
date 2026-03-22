// take two pointers i and j = i+1
//move j when nums[i] == [j] and swap when nums[i] != nums[j] and increment both
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = i+1, count = 1;
        while(j < nums.size()){
            if(nums[i] == nums[j]){
                j++;
            }
            else{
                nums[++i] = nums[j++];
                count++;
            }
        }
        return count;
    }
};