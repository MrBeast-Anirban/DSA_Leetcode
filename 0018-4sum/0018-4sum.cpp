/*

Use 4 variables i, j, a, b
start with i and j from start these two will act as a sliding window across the vector (i=0,j=i+1), Reduce values nums[i]+nums[j] from target sum. 
newTarget = target - nums[i] - nums[j];
Now for iterataion at any point (i,j) initiate a and b from start and end of the remaining vector.
Now use two pointer technique with pointer a and b to find the remaining target value 'newTarget'
Push the quadruplets to a new vector
Note :- Dont forget to consider the fact that there can be same next value for a pointer which will make the quadruplets same.

*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        for(int i = 0; i < n-3; i++){
            for(int j = i+1; j < n-2; j++){
                long long newTarget = (long long) target - (long long)nums[i] - (long long)nums[j];
                int a = j+1, b = n-1;
                while(a < b){
                    if(nums[a] + nums[b] < newTarget){
                        a++;
                    }
                    else if(nums[a] + nums[b] > newTarget){
                        b--;
                    }
                    else{
                        output.push_back({nums[i], nums[j], nums[a], nums[b]});
                        int temp1 = a, temp2 = b;
                        while(a < b and nums[a] == nums[temp1]) a++;
                        while(a < b and nums[b] == nums[temp2]) b--;
                    }
                }
                while(j+1 < n and nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n and nums[i] == nums[i+1]) i++;
        }
        return output;
    }
};