1class Solution {
2public:
3    vector<vector<int>> threeSum(vector<int>& nums) {
4        vector<vector<int>> result;
5        sort(nums.begin(), nums.end());
6        for(int i = 0; i < nums.size(); i++){
7            if(i > 0 and nums[i] == nums[i-1]){
8                continue;
9            }
10            int j = i+1, k = nums.size()-1;
11            while(j < k){
12                int sum = nums[i] + nums[j] + nums[k];
13                if(sum < 0){
14                    j++; //need to add a greater number to the sum
15                }
16                else if(sum > 0){
17                    k--; //need to add a smaller number to the sum
18                }
19                else{
20                    result.push_back({nums[i], nums[j], nums[k]});
21                    j++;
22                    while(nums[j] == nums[j-1] and j < k){ //skip duplicate at j(th) index
23                        j++;
24                    }
25                }
26            }
27        }
28        return result;
29    }
30};