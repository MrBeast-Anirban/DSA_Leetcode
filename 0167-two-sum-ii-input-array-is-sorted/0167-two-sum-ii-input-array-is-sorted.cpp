/*
Used two pointer approach 
since the verctor is already sorted, so we start two pointers from start and end
if sum of elements exceed targer shift the right pointer backward
otherwise shift the left pointer forward
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int j = numbers.size() -1;
        int i = 0;
        while(i < j){
            if((numbers[i]+ numbers[j]) == target){
                return {i+1, j+1};
            }
            else if((numbers[i]+ numbers[j]) > target){
                j -= 1;
            }
            else{
                i += 1;
            }
        }
        return {};
    }
};