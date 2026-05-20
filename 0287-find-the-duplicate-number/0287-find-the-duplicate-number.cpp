// Solution: Using slow and fast pointer.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        //Find the meeting point of the two pointers
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        // find the interence of the cycle
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};